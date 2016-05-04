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

void Listen::add()
{
	string name, description;
	cout << "Insert the name of the event/meeting " << endl;
	getline(cin, name);
	cout << "" << endl;

	cout << "Insert the description of the event/meeting "<< endl;
	getline(cin, description);
	cout << "" << endl;
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