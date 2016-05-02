/* 
 * File:   Manage.cpp
 * Author: Manuel
 * 
 * Created on 27. April 2016, 15:55
 */

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
        
        eventsList.insert(event);
    }
    
    if (type == "deadline"){
        //create object
    }
    
    appendToFile(//extracted data
            );
}
