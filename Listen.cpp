/* 
 * File:   Listen.cpp
 * Author: Manuel
 * 
 * Created on 27. April 2016, 16:02
 */

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


void Listen::listener() 
{
    while(1)
	{
        string command;
        getline(cin, command);
        if(command == "add" || command == "add event")
        {
            cout << "You selected add" << endl;
            cout << "Select if the event is a \"meeting\" or a \"deadline\"" << endl;
            getline(cin, command);
            m.createNewEvent(command);
        }
        else
        {
            if(command == "update" || command == "update event")
            {
                cout << "You selected update" << endl;
            }
            else
            {
                if(command == "remove" || command == "remove event")
                {
                    cout << "You selected remove" << endl;
                }
                else
                {
                    if(command == "filter" || command == "filter event")
                    {
                        cout << "You selected filter" << endl;
                    }
                    else
                    {
                        if(command == "print" || command == "print event")
                        {
                            cout << "You selected print" << endl;
                        }
                        else
                        {
                            if(command == "check" || command == "check event")
                            {
                                cout << "You selected check" << endl;
                            }
                            else
                            {
                            	if(command == "help")
                            	{
                            		cout << "You selected help" << endl;
                            	}
                            	else
                            	{
                            		if(command == "exit" || command == "kill pingui")
                               		{
                                 	   cout << "***********************Goodbye***********************" << endl;
                                	   return;
                                	}
                               		else
	                                {
	                                	cout << "***Invalid command!***\n***Digit help for the list of commands***" << endl;
    	                            }
                            	}
                            }
                        }
                    }
                }
            }
        }
        cout << "Waiting for another command from the user" << endl;
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
}