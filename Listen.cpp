#include "Listen.h"
#include "Manage.h"

Manage m;

Listen::Listen() 
{
}

Listen::Listen(const Listen& orig) 
{
}

Listen::~Listen() 
{
}


string Listen::listenLabel(string type) {
    string label;
    cout << "Insert the name of the "+type << endl;
    getline(cin, label);
    return label;
}    
    
string Listen::listenStartDate(string type){
    string startDate;
    cout << "Insert the date and time of the "+type << endl;
    getline(cin, startDate);
    return startDate;
}

string Listen::listenEndDate(string type){
    string endDate;
    cout << "Insert the ending date and time of the "+type << endl;
    getline(cin, endDate);
    return endDate;
}

string Listen::listenDescription(string type){
    string description;
    cout << "Insert the description of the "+type << endl;
    getline(cin, description);
    return description;
}

string Listen::listenLocation(string type){
    string location;
    cout << "Insert the location of the "+type << endl;
    getline(cin, location);
    return location;
}

void Listen::removeAll()
{
    // Remove all the data stored in the database file
    cout << "You are about to remove all the saved events" << endl;
    cout << "Do you really want to continue? [Y/n]" << endl;
    string command;
    getline(cin, command);
    if(command == "Y" || command == "y")
    {
        cout << "Selected remove all" << endl;
        m.emptyFile();
    }
    else
        cout << "Aborted remove all" << endl;
}
    
    
    
                //old code
//    cout << "*********" << endl;
//	cout << "********* ";

//	string command;
//	getline(cin, command);

  //  Manage ma;
//	if(command == "show all")
//	{
  //      ma.showAllEvents();
    //}
	//else 
	//	if(command == "time")
	//	{
	//		cout << "*********" << endl;
	//		cout << "********* " + ma.currentTime() << endl;
	//		cout << "*********" << endl;
   	  //  }
