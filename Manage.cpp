/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */
 
#include "Manage.h"
#include "Listen.h"
#include "GUI.h"

Listen l;
GUI gui;

Manage::Manage() {
}

Manage::~Manage() {
}

void Manage::appendToFile(string data){
    //Creates a filestream
    fstream file;
    //Creates and opens the file
    file.open("database.dat", fstream::app|fstream::out);
    //Writes something on the file
    file << data;
    //Closes the file
    file.close();
}

void Manage::emptyFile(){
    //Creates a filestream
    fstream file;
    //Truncates the file
    file.open("database.dat", fstream::out | fstream::trunc);
    //Closes the file
    file.close();
    
}

void Manage::clearList(vector<Event*> eventsList){
    //iterate through list, deallocate memory of dynamic objects and clear the list
    vector<Event*>::iterator it;
        for (it=eventsList.begin(); it < eventsList.end(); it++){
            delete *it;
        }
        eventsList.clear();
}

string Manage::currentTime(){
    time_t t = time(NULL);
    return asctime(localtime(&t));
}

void Manage::showAllEvents() {
    // Print all the events on the command line
    gui.list(eventsList);
}

void Manage::readAllFromFile() {
    //Reader for the file
	ifstream file;
	//Open the file
	file.open("database.dat", fstream::in);
	string line;
	string result;
        MeetingEvent *tempmeeting;
        DeadlineEvent *tempdeadline;
        
        
        //DELETION OF OLD OBJECTS
        //empty the vecor list and recreate events from read file
        //clearList(eventsList);
        eventsList.clear();
        
        //RECREATION OF OBJECTS
	//Checks if file has been opened
	if(file.is_open())
	{
            //int current_line=1;
            
            //getline(file, line);
                
                while(getline(file, line)){
		
                    
                    //if meeting found, get its 5 pieces of data
                    if(line.find("/|\\MEETING/|\\")!=string::npos){
                        tempmeeting = new MeetingEvent;
                        for (int index=1; index<=5; index++){
                            getline(file, line);
                            
                            switch (index)
                            {
                                /*case (1):
                                    tempmeeting->setID(atoi(line.c_str()));
                                    break;*/
                                    
                                case (1):
                                    tempmeeting->setLabel(line);
                                    break;
                                    
                                case (2):
                                    tempmeeting->setDesc(line);
                                    break;
                                    
                                case (3):
                                    tempmeeting->setStartDate(line);
                                    break;
                                    
                                case (4):
                                    tempmeeting->setEndDate(line);
                                    break;
                                    
                                case (5):
                                    tempmeeting->setLocation(line);
                            }
                        }
                        MeetingEvent *newevent = tempmeeting;
                        eventsList.push_back(newevent);
                    }
                    
                    //if deadline found, get its 3 pieces of data
                    else if(line.find("/|\\DEADLINE/|\\")!=string::npos){
                        tempdeadline=new DeadlineEvent;
                        for (int index=1; index<=3; index++){
                            getline(file, line);
                            
                            switch (index)
                            {
                                /*case (1):
                                    tempdeadline->setID(atoi(line.c_str()));
                                    break;*/
                                    
                                case (1):
                                    tempdeadline->setLabel(line);
                                    break;
                                    
                                case (2):
                                    tempdeadline->setDesc(line);
                                    break;
                                    
                                case (3):
                                    tempdeadline->setStartDate(line);
                                    break;
                                    
                            }
                        }
                        //copy the temporary event to a new one and add it to the list
                        DeadlineEvent *newevent = tempdeadline;
                        eventsList.push_back(newevent);
                    }
                
            }
            //Closes the file
		file.close();
	}
	else
		gui.error("Impossible to open the file");
        
        gui.notify("Pingui found " + intToString(eventsList.size()) + " events");
        
        
        //how to extract an event from list and cast down: 
        //MeetingEvent *testt = dynamic_cast<MeetingEvent*>(eventsList[0]);
        //cout << testt->getLocation();
}

string Manage::intToString(int i){
    //convert integer to string
    stringstream sstm;
    sstm << i;
    return sstm.str();
}

int Manage::stringToInt(string s){
    return atoi(s.c_str());
}

template<typename T> string Manage::constructDataString(T* event){
    string dataString = /*intToString(event->getID())+"\n"+*/event->getLabel()+"\n"+event->getDesc()+"\n"+event->getStartDate()+"\n";
    
    //add meeting-specific data to string
    if (MeetingEvent* m = dynamic_cast<MeetingEvent*>(event)){
        dataString+=m->getEndDate()+"\n"+m->getLocation()+"\n";
        string temp=dataString;
        dataString="/|\\MEETING/|\\\n"+temp;
    }
    
    //add deadline-specific data to string
    else if (DeadlineEvent* m = dynamic_cast<DeadlineEvent*>(event)){
        string temp=dataString;
        dataString="/|\\DEADLINE/|\\\n"+temp;
    }
    
    
    return dataString;
}

void Manage::updateFile(){
    //empty file
    emptyFile();
    //rewrite file with all events in the list
    vector<Event*>::iterator it;
        for (it=eventsList.begin(); it < eventsList.end(); it++){
            Event *e = *it;
            appendToFile(constructDataString(e));
        }
}


/*void Manage::setEventID(Event *e){
    //if list is empty set ID=0, or else add 1 to the ID of the last object
    if (eventsList.empty()){
        e->setID(0);
    }
    else{
        int lastID=eventsList.back()->getID();
        e->setID(lastID+1);
    }
}*/



void Manage::listenToData(string type){
    if (type=="meeting"){
        //NAME
            name=l.listenLabel(type, "new");
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(name == "abort")
                    return ;
        //START DATE
            startDate=l.listenStartDate(type, "new");
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(startDate == "abort")
                    return ;
        //END DATE
            endDate=l.listenEndDate(type, "new"); 
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(endDate == "abort")
                    return ;
        //DESCRIPTION
            description=l.listenDescription(type, "new");
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(description == "abort")
                    return ;
        //LOCATION
            location=l.listenLocation(type, "new");  
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(location == "abort")
                    return ;
            
          
    }
    else if (type=="deadline"){
        //NAME
            name=l.listenLabel(type, "new");
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(name == "abort")
                    return ;
        //START DATE
            startDate=l.listenStartDate(type, "new");
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(startDate == "abort")
                    return ;
        //DESCRIPTION
            description=l.listenDescription(type, "new");
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(description == "abort")
                    return ;
            
            
    }
}


void Manage::createNewEvent(string type){
    string dataToWrite;
    
        if (type == "meeting"){
            MeetingEvent *event = new MeetingEvent;

            gui.notify("You selected the meeting event");

            //call listening function
            listenToData(type);
            
            
            // If user inputs "abort", returns to the main menu
            if(name == "abort" | startDate == "abort" | endDate == "abort" | description == "abort" | location == "abort")
                    return ;
            
            //set event variables
            event->setLabel(name);
            event->setStartDate(startDate);
            event->setEndDate(endDate);
            event->setDesc(description);
            event->setLocation(location);

            /*//ID
            setEventID(event);*/
            
            
            //insert event into the list
            eventsList.push_back(event);
            //construct string to write to file
            dataToWrite=constructDataString(event);
                        
    }
    
    
    
    else if (type == "deadline"){
            DeadlineEvent *event=new DeadlineEvent;
            gui.notify("You selected the deadline event");

            //call listening function
            listenToData(type);
            
            
            // If user inputs "abort", returns to the main menu
            if(name == "abort" | startDate == "abort" | description == "abort")
                    return ;
            
            //set event variables
            event->setLabel(name);
            event->setStartDate(startDate);
            event->setDesc(description);

            /*//ID
            setEventID(event);*/
            
            
            //insert event into the list
            eventsList.push_back(event);
            //construct string to write to file
            dataToWrite=constructDataString(event);
            
    }
    else
        gui.error("Invalid event type!");
        
        
        //write to file
        appendToFile(dataToWrite);
        gui.notify(("The event has been saved"));
    
}


void Manage::updateEvent(string id){
    /*vector<Event*>::iterator it;
    it=findWithID(id);*/
    Event* e=eventsList[stringToInt(id)];
    
    //NAME
    name=l.listenLabel("","update");
    if(!name.empty()){
      e->setLabel(name);  
    }
    
    
    //STARTDATE
    startDate=l.listenStartDate("","update");
    if(!startDate.empty()){
        e->setStartDate(startDate);
    }
    
    //ENDDATE
    if (MeetingEvent* m = dynamic_cast<MeetingEvent*>(e)){
        endDate=l.listenEndDate("", "update");
        if(!endDate.empty()){
            m->setEndDate(endDate);
        }
    }
    
    //LOCATION
    if (MeetingEvent* m = dynamic_cast<MeetingEvent*>(e)){
        location=l.listenLocation("", "update");
        if(!location.empty()){
            m->setLocation(location);
        }
    }
    
    //DESCRIPTION
    description=l.listenDescription("", "update");
    if(!description.empty()){
        e->setDesc(description);
    }
    
    
    //update file
    updateFile();
    gui.notify(("The event has been updated"));
}

/*vector<Event*>::iterator Manage::findWithID(string id){
    vector<Event*>::iterator it;
    Event* e;
    for (it=eventsList.begin(); it < eventsList.end(); it++)
    {
        //transform id to string
        stringstream sstm;
        sstm << (*it)->getID();
    	// Check if the ID of the actual event corresponds to the ID of the event to remove. If yes, remove it and set to true the boolean variable removed
	    	if((id.compare(sstm.str()))==0)
	    	{
                    return it;
	    	}    
   }
    return it;
}*/



void Manage::removeEvent()
{
    //get a valid id from user
    int id=l.listenForID();
    
    vector<Event*>::iterator it=eventsList.begin();
    advance(it, id);
    //it=findWithID(id);
	    	// Check if the ID of the actual event corresponds to the ID of the event to remove. If yes, remove it and set to true the boolean variable removed
	    	Event* e=*(it);
                eventsList.erase(it);
                delete e;
   
    //update database file
    updateFile();
    gui.notify("The event has been removed");
}


void Manage::find()
{
    string value_to_filter;
    
    //gui.notify("The field that will be filtered is the name of the event");
    gui.ask("Insert the name/label of the event");
    getline(cin, value_to_filter);

    vector<Event*>::iterator it;
    std::vector<Event*> event;
    for(it=eventsList.begin(); it < eventsList.end(); it++)
    {
    	//Match name with substring
    	if(((*it)->getLabel()).find(value_to_filter) != std::string::npos)
    		event.push_back(*it);
    		
/*
        //cout << eventsList[1]->getLabel() << endl;
        if((*it)->getLabel() == value_to_filter)
           event.push_back(*it);
*/
    }

    gui.list(event);
    // TODO: print all the events found in the list event  
}


bool Manage::checkAvailability(string date){
    vector<Event*>::iterator it;
    //bool available=true;
    //iterates through list and sets available=true if an event on the same day is found
    for (it=eventsList.begin(); it < eventsList.end(); it++)
    {
	    	if((date.compare((*it)->getStartDate()))==0)
	    	{
                    return false;
	    	}
   }
    return true;
}

int Manage::getEventIndex(Event* e){
    int pos = std::find(eventsList.begin(), eventsList.end(), e)-eventsList.begin();
    if (pos<eventsList.size()){
        return pos;
    }
    else return -1;
}

void Manage::check(){
    string date;
    
    gui.ask("Enter the date to check");
    getline(cin, date);
    bool av=checkAvailability(date);
                if(av==false){
                    gui.error("This date is not available");
                }
                if(av==true){
                    gui.notify("This date is available");
                }
}

void Manage::print(){
    int id=l.listenForID();
    gui.print(eventsList[id]);
}