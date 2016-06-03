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

vector<Event*> Manage::eventsList;

int main(int argc, char** argv) {
    Manage m;
    Listen l;
    GUI gui;

    gui.welcome();

    const string COMMANDS[] = {"add", "update", "remove", "find", "print", "removeall", "showall", "check", "help", "commands", "bye", "exit", "pingui", "hello"};
    const int NUM_COMMANDS = sizeof (COMMANDS) / sizeof (COMMANDS[0]);

    string user_input;
    int command, i;

    //Read file and import events in program memory
    m.readAllFromFile();

    while (1) {

        // Get the line inputs
        getline(cin, user_input);

        command = -1;
        i = 0;

        // Loop through the command list
        while (command == -1 && i < NUM_COMMANDS) {
            // Look for command in the user input
            if (COMMANDS[i] == user_input) {
                command = i;
            }

            /*
            // Check if the word is close to the user input
            for (int n = 0; n != user_input.size(); n++)
            {
                //cout << user_input[n] << endl;
            } */

            i++;
        }

        switch (command) {
            case 0:
                l.addEvent();
                break;

            case 1:
                l.updateEvent();
                break;

            case 2:
                m.removeEvent();
                break;

            case 3:
                m.find();
                break;

            case 4:
                m.print();
                break;

            case 5:
                l.removeAll();
                break;

            case 6:
                m.showAllEvents();
                break;

            case 7:
                m.check();
                break;

            case 8:
            case 9:
                gui.help();
                break;

            case 10:
            case 11:
                gui.greetings();
                return 0;
                break;

            case 12:
            case 13:
                gui.pingui();
                break;

            default:
                gui.invalidCommand();

        }

        gui.waitingNextCommand();
    }

    return 0;
}