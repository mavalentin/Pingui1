/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */

#include <iostream>
#include "DeadlineEvent.h"
#include "Manage.h"
#include "Listen.h"

using namespace std;

int main(int argc, char** argv) {
    Manage m;
    Listen l;
    cout << "********* Welcome to PINGUI! **********" << endl;
    m.appendToFile("Another day with Pingui "+m.currentTime());    
    
    //initialize listening
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
                            if(command == "remove all")
                            {
                                l.removeAll(); 
                            }
                            else
                            {
                                if(command == "show all")
                                {
                                    m.showAllEvents(); 
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
                                        	   return 0;
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
            }
        }
        cout << "Waiting for another command from the user" << endl;
    }
    return 0;
}