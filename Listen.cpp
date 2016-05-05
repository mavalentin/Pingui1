/* 
 * File:   Listen.cpp
 * Author: Manuel
 * 
 * Created on 27. April 2016, 16:02
 */

#include "Listen.h"
#include "Manage.h"

Listen::Listen() 
{
}

Listen::Listen(const Listen& orig) 
{
}

Listen::~Listen() 
{
}

void Listen::addDeadLineEvent()
{
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

void Listen::addMeetingEvent()
{
	cout << "You selected the meeting event" << endl;

	string name, description, startDate, endDate;
	
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
}

void Listen::listener() 
{
    cout << "*********" << endl;
	cout << "********* How can I help you?" << endl;
	cout << "*********" << endl;
	cout << "********* ";

	string command;
	getline(cin, command);

    Manage ma;
	if(command == "show all")
	{
        ma.showAllEvents();
    }
	else 
		if(command == "time")
		{
			cout << "*********" << endl;
			cout << "********* " + ma.currentTime() << endl;
			cout << "*********" << endl;
   	    }
}