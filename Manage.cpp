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
    file << data << endl;
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
	cout << readAllFromFile() << endl;	
	cout << "*********" << endl;
}

string Manage::readAllFromFile() {
    //Reader for the file
	ifstream file;
	//Open the file
	file.open("database.dat", fstream::in);
	string line;
	string result;
	//Checks if file has been opened
	if(file.is_open())
	{
		//Print the content of the file
		while(getline(file, line))
		{
			result += line;
			result += '\n';
		}
		//Closes the file
		file.close();
	}
	else
		cout << "Impossible to open the file" << endl;

	return result;
}

template<typename T> string Manage::constructDataString(T* event){
    string dataString;
    stringstream sstm;
    sstm << event->getID() << "\n"+event->getLabel()+"\n"+event->getDesc()+"\n"+event->getStartDate();
    dataString=sstm.str();
    
    //add meeting-specific data to string
    if (MeetingEvent* m = dynamic_cast<MeetingEvent*>(event)){
        dataString+="\n"+m->getEndDate()+"\n"+m->getLocation();
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


void Manage::createNewEvent(string type){
    string dataToWrite;
    
        if (type == "meeting"){
            MeetingEvent *event = new MeetingEvent;
            string name, description, startDate, endDate, location;

            cout << "You selected the meeting event" << endl;

            //NAME
            name=l.listenLabel(type);
    // If user inputs "abort", returns to the main menu
            if(name == "abort")
                    return ;
            event->setLabel(name);
            cout << "" << endl;

            //START DATE
            startDate=l.listenStartDate(type);
    // If user inputs "abort", returns to the main menu
            if(startDate == "abort")
                    return ;
            //get and set start date
            event->setStartDate(startDate);
            cout << "" << endl;

            //END DATE
            endDate=l.listenEndDate(type);
    // If user inputs "abort", returns to the main menu
            if(endDate == "abort")
                    return ;
            //get and set end date
            event->setEndDate(endDate);
            cout << "" << endl;

            //DESCRIPTION
            description=l.listenDescription(type);
    // If user inputs "abort", returns to the main menu
            if(description == "abort")
                    return ;
            //get and set description
            event->setDesc(description);
            cout << "" << endl;

            //LOCATION
            location=l.listenLocation(type);
    // If user inputs "abort", returns to the main menu
            if(location == "abort")
                    return ;
            //get and set location
            event->setLocation(location);
            cout << "" << endl;

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

            string name, description, date;

            //NAME
            name=l.listenLabel(type);
    // If user inputs "abort", returns to the main menu
            if(name == "abort")
                    return ;
            event->setLabel(name);
            cout << "" << endl;

            //DATE
            date=l.listenStartDate(type);
    // If user inputs "abort", returns to the main menu
            if(date == "abort")
                    return ;
            //get and set start date
            event->setStartDate(date);
            cout << "" << endl;

            //DESCRIPTION
            description=l.listenDescription(type);
    // If user inputs "abort", returns to the main menu
            if(description == "abort")
                    return ;
            //get and set description
            event->setDesc(description);
            cout << "" << endl;
            
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
