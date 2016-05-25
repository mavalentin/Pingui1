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
    file.open("database.dat", fstream::out | std::fstream::trunc);
    //Closes the file
    file.close();

    gui.notify("All events removed");
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
        clearList(eventsList);
        
        //RECREATION OF OBJECTS
	//Checks if file has been opened
	if(file.is_open())
	{
            //int current_line=1;
            
            //getline(file, line);
                
                while(getline(file, line)){
		
                    
                    //if meeting found, get its 6 pieces of data
                    if(line.find("/|\\MEETING/|\\")!=string::npos){
                        tempmeeting = new MeetingEvent;
                        for (int index=1; index<=6; index++){
                            getline(file, line);
                            
                            switch (index)
                            {
                                case (1):
                                    tempmeeting->setID(atoi(line.c_str()));
                                    break;
                                    
                                case (2):
                                    tempmeeting->setLabel(line);
                                    break;
                                    
                                case (3):
                                    tempmeeting->setDesc(line);
                                    break;
                                    
                                case (4):
                                    tempmeeting->setStartDate(line);
                                    break;
                                    
                                case (5):
                                    tempmeeting->setEndDate(line);
                                    break;
                                    
                                case (6):
                                    tempmeeting->setLocation(line);
                            }
                        }
                        MeetingEvent *newevent = tempmeeting;
                        eventsList.push_back(newevent);
                    }
                    
                    //if deadline found, get its 4 pieces of data
                    else if(line.find("/|\\DEADLINE/|\\")!=string::npos){
                        tempdeadline=new DeadlineEvent;
                        for (int index=1; index<=4; index++){
                            getline(file, line);
                            
                            switch (index)
                            {
                                case (1):
                                    tempdeadline->setID(atoi(line.c_str()));
                                    break;
                                    
                                case (2):
                                    tempdeadline->setLabel(line);
                                    break;
                                    
                                case (3):
                                    tempdeadline->setDesc(line);
                                    break;
                                    
                                case (4):
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
        gui.notify("We found " + intToString(eventsList.size()) + " events in database and saved them to vector list.");
        
        
        //how to extract an event from list and cast down: 
        //MeetingEvent *testt = dynamic_cast<MeetingEvent*>(eventsList[0]);
        //cout << testt->getLocation();
}

string Manage::intToString(int i){
    stringstream sstm;
    sstm << i;
    return sstm.str();
}

template<typename T> string Manage::constructDataString(T* event){
    string dataString = intToString(event->getID())+"\n"+event->getLabel()+"\n"+event->getDesc()+"\n"+event->getStartDate()+"\n";
    
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

void Manage::setEventID(Event *e){
    //if list is empty set ID=0, or else add 1 to the ID of the last object
    if (eventsList.empty()){
        e->setID(0);
    }
    else{
        int lastID=eventsList.back()->getID();
        e->setID(lastID+1);
    }
}



void Manage::listenToData(string type){
    if (type=="meeting"){
        //NAME
            name=l.listenLabel(type);
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(name == "abort")
                    return ;
        //START DATE
            startDate=l.listenStartDate(type);
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(startDate == "abort")
                    return ;
        //END DATE
            endDate=l.listenEndDate(type); 
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(endDate == "abort")
                    return ;
        //DESCRIPTION
            description=l.listenDescription(type);
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(description == "abort")
                    return ;
        //LOCATION
            location=l.listenLocation(type);  
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(location == "abort")
                    return ;
            
          
    }
    else if (type=="deadline"){
        //NAME
            name=l.listenLabel(type);
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(name == "abort")
                    return ;
        //START DATE
            startDate=l.listenStartDate(type);
            cout << "" << endl;
            // If user inputs "abort", returns to the main menu
            if(startDate == "abort")
                    return ;
        //DESCRIPTION
            description=l.listenDescription(type);
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

            //ID
            setEventID(event);
            
            
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

            //ID
            setEventID(event);
            
            
            //insert event into the list
            eventsList.push_back(event);
            //construct string to write to file
            dataToWrite=constructDataString(event);
            
    }
    else
        gui.error("Invalid event type!");
        gui.notify("Exiting the add option");
        
        
        //write to file
        appendToFile(dataToWrite);
    
}




void Manage::removeEvent(string id)
{
	// Uncomment this part in case the id is not passed as parameter, but asked from this method
//	cout<<"Insert the ID of the event you want to delete"<<endl;
//	string id;
//  getline(cin, id);

    bool removed = false;
    vector<Event*>::iterator it;
    for (it=eventsList.begin(); it < eventsList.end(); it++)
    {
        //transform id to string
        stringstream sstm;
        sstm << (*it)->getID();
    	// If set to true, then it means that an event has been removed and all the IDs have to be shifted by one before
    	if(removed){
    		//(*it)->setID((*it)->getID()-1);
        }
    	else
	    	// Check if the ID of the actual event corresponds to the ID of the event to remove. If yes, remove it and set to true the boolean variable removed
	    	if((id.compare(sstm.str()))==0)
	    	{
                        Event* e=*(it);
                        eventsList.erase(it);
                        delete e;
	    		removed = true;
	    	}    
   }
    //update database file
    updateFile();
}


void Manage::filter()
{
    string value_to_filter;
    
    gui.notify("The field that will be filtered is the name of the event");
    gui.ask("Insert the value to filter");
    getline(cin, value_to_filter);

    vector<Event*>::iterator it;
    std::vector<Event*> event;
    for(it=eventsList.begin(); it < eventsList.end(); it++)
    {
        cout << eventsList[1]->getLabel() << endl;
        if((*it)->getLabel() == value_to_filter)
            event.push_back(*it);
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
    cout << "M: this is available" << endl;
    return true;
}
