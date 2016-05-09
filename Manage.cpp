#include "Manage.h"

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
string Manage::currentTime(){
    time_t t = time(NULL);
    return asctime(localtime(&t));
}

void Manage::showAllEvents() {
    cout << "*********" << endl;
	cout << readFromFile() << endl;	
	cout << "*********" << endl;
}

string Manage::readFromFile() {
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
        string name, description, startDate, endDate;
        
        cout << "You selected the meeting event" << endl;
        
        cout << "Insert the name of the meeting " << endl;
	getline(cin, name);
	cout << "" << endl;
// If user inputs "abort", returns to the main menu
	if(name == "abort")
		return ;

	cout << "Insert the starting date and time of the meeting " << endl;
	getline(cin, startDate);
	cout << "" << endl;
// If user inputs "abort", returns to the main menu
	if(startDate == "abort")
		return ;

	cout << "Insert the ending date and time of the meeting " << endl;
	getline(cin, endDate);
	cout << "" << endl;
// If user inputs "abort", returns to the main menu
	if(endDate == "abort")
		return ;

	cout << "Insert the description of the meeting "<< endl;
	getline(cin, description);
	cout << "" << endl;
// If user inputs "abort", returns to the main menu
	if(description == "abort")
		return ;
        //todo: extract from input data and insert in event object variables
        
        //totest: insert event into the list
        eventsList.push_front(event);
    }
    
    else if (type == "deadline"){
        //todo: copy functionality from meeting
        
        cout << "You selected the deadline event" << endl;

	string name, description, date;

	cout << "Insert the name of the event " << endl;
	getline(cin, name);
	cout << "" << endl;
// If user inputs "abort", returns to the main menu
	if(name == "abort")
		return ;

	cout << "Insert the date of the event "<< endl;
	getline(cin, date);
	cout << "" << endl;
// If user inputs "abort", returns to the main menu
	if(date == "abort")
		return ;

	cout << "Insert the description of the event "<< endl;
	getline(cin, description);
	cout << "" << endl;
// If user inputs "abort", returns to the main menu
	if(description == "abort")
		return ;

	// Make a call to the Manage.cpp file that formats the string to add and pass it to the method
    }
    else
        cout <<"Invalid event type!\nExiting the add option" << endl;
    
    
    //write created object to file
    //todo: call serialize class
    string dataToWrite;
    appendToFile(dataToWrite);
}
