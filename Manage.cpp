/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */
 
#include "Manage.h"
#include "Listen.h"

Listen l;



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
    //Creates and opens the file (override mode)
    file.open("database.dat", fstream::out);
    //Writes empty string on the file
    file << "" << endl;
    //Closes the file
    file.close();

    cout << "All events removed" << endl;
}

string Manage::currentTime(){
    time_t t = time(NULL);
    return asctime(localtime(&t));
}

void Manage::showAllEvents() {
    cout << "*********" << endl;
	//cout << readAllFromFile() << endl; //here we will need to read from the vectorlist instead of database	
	cout << "*********" << endl;
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
            //iterate through list, deallocate memory of dynamic objects
        vector<Event*>::iterator it;
        for (it=eventsList.begin(); it < eventsList.end(); it++){
            delete *it;
        }
        eventsList.clear();
        
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
                        DeadlineEvent *newevent = tempdeadline;
                        eventsList.push_back(newevent);
                    }
                
            }
            //Closes the file
		file.close();
	}
	else
		cout << "Impossible to open the file\n" << endl;

        cout << "We found " << eventsList.size() << " events in database and saved them to vector list." << endl;
}

template<typename T> string Manage::constructDataString(T* event){
    string dataString;
    stringstream sstm;
    sstm << event->getID() << "\n"+event->getLabel()+"\n"+event->getDesc()+"\n"+event->getStartDate()+"\n";
    dataString=sstm.str();
    
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

            cout << "You selected the meeting event" << endl;

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
            cout << "You selected the deadline event" << endl;

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
        cout <<"Invalid event type!\nExiting the add option" << endl;
        
        
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
    	// If set to true, then it means that an event has been removed and all the IDs have to be shifted by one before
    	if(removed)
    		(*it)->setID((*it)->getID()-1);
    	else
	    	// Check if the ID of the actual event corresponds to the ID of the event to remove. If yes, remove it and set to true the boolean variable removed
	    	if(id.compare((*it)->getID()+""))
	    	{
	    		eventsList.erase(eventsList.begin() + 1);
	    		removed = true;
	    	}    
   }
  // TODO: add them to a string that will be written on the database.dat file. Problem with casting at the constructDataString()
}