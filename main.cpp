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
#include "GUI.h"

using namespace std;

int main(int argc, char** argv) {
    Manage m;
    Listen l;
    GUI gui;

    gui.welcome();
    
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
                gui.notify("You selected add");
                gui.ask("Select if the event is a \"meeting\" or a \"deadline\"");
                getline(cin,user_input);
                m.createNewEvent(user_input);
                break;

            case 1:
                gui.notify("You selected update");
                break;
            
            case 2:
                gui.notify("You selected remove");
                m.removeEvent("1");
                break;
            
            case 3:
                gui.notify("You selected filter");
                m.filter();
                break;
            
            case 4:
                gui.notify("You selected print");
                break;
            
            case 5:
                l.removeAll();
                break;
            
            case 6:
                m.showAllEvents();
                break;
            
            case 7:
                gui.notify("You selected check");
                break;
            
            case 8:
                gui.help();
                break;
            
            case 9:
                gui.greetings();
                return 0;
                break;
            
            default:
                gui.invalidCommand();

        }

        gui.waitingNextCommand();
    }
    return 0;
}