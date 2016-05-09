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

void Manage::createNewEvent(string type){
        if (type == "meeting"){
            MeetingEvent event;
            string name, description, startDate, endDate, location;

            cout << "You selected the meeting event" << endl;

            //NAME
            name=l.listenLabel(type);
    // If user inputs "abort", returns to the main menu
            if(name == "abort")
                    return ;
            event.setLabel(name);
            cout << "" << endl;

            //START DATE
            startDate=l.listenStartDate(type);
    // If user inputs "abort", returns to the main menu
            if(startDate == "abort")
                    return ;
            //get and set start date
            event.setStartDate(startDate);
            cout << "" << endl;

            //END DATE
            endDate=l.listenEndDate(type);
    // If user inputs "abort", returns to the main menu
            if(endDate == "abort")
                    return ;
            //get and set end date
            event.setEndDate(endDate);
            cout << "" << endl;

            //DESCRIPTION
            description=l.listenDescription(type);
    // If user inputs "abort", returns to the main menu
            if(description == "abort")
                    return ;
            //get and set description
            event.setDesc(description);
            cout << "" << endl;

            //LOCATION
            location=l.listenLocation(type);
    // If user inputs "abort", returns to the main menu
            if(location == "abort")
                    return ;
            //get and set location
            event.setLocation(location);
            cout << "" << endl;


            //insert event into the list
            eventsList.push_back(&event);
            
            //TODO: call serialize and appendToFile
            
            
    }
    
    
    
    
    
    else if (type == "deadline"){
            DeadlineEvent event;
            cout << "You selected the deadline event" << endl;

            string name, description, date;

            //NAME
            name=l.listenLabel(type);
    // If user inputs "abort", returns to the main menu
            if(name == "abort")
                    return ;
            event.setLabel(name);
            cout << "" << endl;

            //DATE
            date=l.listenStartDate(type);
    // If user inputs "abort", returns to the main menu
            if(date == "abort")
                    return ;
            //get and set start date
            event.setStartDate(date);
            cout << "" << endl;

            //DESCRIPTION
            description=l.listenDescription(type);
    // If user inputs "abort", returns to the main menu
            if(description == "abort")
                    return ;
            //get and set description
            event.setDesc(description);
            cout << "" << endl;
            
            
            //insert event into the list
            eventsList.push_back(&event);
            
            //TODO: call serialize and appendToFile
            
            

	// Make a call to the Manage.cpp file that formats the string to add and pass it to the method
    }
    else
        cout <<"Invalid event type!\nExiting the add option" << endl;
    
    
    //write created object to file
    //todo: call serialize class
        
        
    //string dataToWrite;
    //appendToFile(dataToWrite);
}
