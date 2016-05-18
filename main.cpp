/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "DeadlineEvent.h"
#include "Manage.h"
#include "Listen.h"

using namespace std;

int main(int argc, char** argv) {
    Manage m;
    Listen l;


    string help = "Help section:\n\tAdd: type \"add\" to add an event. Instructions of what to insert will be followed\n\n\tUpdate: type \"update\" to modify an already existing event. Instructions of what to insert will be followed\n\n\tRemove: type \"remove\" to delete an already existing event. Instructions of what to insert will be followed\n\n\tRemove All: type \"removeall\" to delete all the events present in the file. Instructions of what to insert will be followed\n\n\tFilter: type \"filter\" to select a subset of events from the existing events saved into the file. Instructions of what to insert will be followed\n\n\tPrint: type \"print\" to print all the present events. Instructions of what to insert will be followed\n\n\tShow All: type \"showall\" to print all the present events. Instructions of what to insert will be followed\n\n\tCheck: type \"check\" to take a look at the events. Instructions of what to insert will be followed\n\n\tHelp: type \"help\" to get help\n\n\tExit: type \"exit\" to log out from the application\n";



    cout << "********* Welcome to PINGUI! **********" << endl;
    
    const string COMMANDS[] = { "add", "update", "remove", "filter", "print", "removeall", "showall", "check", "help", "exit"};
    const int NUM_COMMANDS = sizeof(COMMANDS)/sizeof(COMMANDS[0]);

    string user_input;
    int command;

    m.readAllFromFile();
    
    while(1)
	{

        // Get the line inputs
        getline(cin, user_input);

        command = -1;

        // Loop through the command list
        for (int i = 0; i < NUM_COMMANDS; ++i)
        {
            // Look for command in the user input
            if ( COMMANDS[i] == user_input )
            {
                command = i;
                break;
            }
        }

        switch ( command )
        {
            case 0:
                cout << "You selected add" << endl;
                cout << "Select if the event is a \"meeting\" or a \"deadline\"" << endl;
                getline(cin,user_input);
                m.createNewEvent(user_input);
                break;

            case 1:
                cout << "You selected update" << endl;
                break;
            
            case 2:
                cout << "You selected remove" << endl;
                break;
            
            case 3:
                cout << "You selected filter" << endl;
                break;
            
            case 4:
                cout << "You selected print" << endl;
                break;
            
            case 5:
                l.removeAll();
                break;
            
            case 6:
                m.showAllEvents();
                break;
            
            case 7:
                cout << "You selected check" << endl;
                break;
            
            case 8:
//                cout << "You selected help" << endl;
                cout << help << endl;
                break;
            
            case 9:
                cout << "***********************Goodbye***********************" << endl;
                return 0;
                break;
            
            default:
                cout << "***Invalid command!***\n***Digit help for the list of commands***" << endl;

        }

        cout << "Waiting for another command from the user" << endl;
    }
    return 0;
}