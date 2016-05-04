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

void Manage::createNewEvent(string type, string data){
    if (type == "meeting"){
        MeetingEvent event;
        //todo: extract from input data and insert in event object variables
        
        //totest: insert event into the list
        eventsList.push_front(event);
    }
    
    else if (type == "deadline"){
        //todo: copy functionality from meeting
    }
    
    
    //write created object to file
    //todo: call serialize class
    string dataToWrite;
    appendToFile(dataToWrite);
}
