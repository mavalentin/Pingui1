/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */
 
#include "./GUI.h"

const string atest = "   °°° ";
const string atestQ = "  ?°°° ";
const string atestE = "  !°°° ";
const string endl2 = "\n\n       ";

GUI::GUI() {
        //cout << "creating gui object" << endl;
}

GUI::~GUI() {
        //cout << "destroying gui object" << endl;
}

void GUI::welcome(){

    cout << endl << atest << "Welcome to PINGUI!" << endl2;

    // Print Pengui on the screen
    pengui();

}

void GUI::greetings(){

    cout << endl << atest << "Goodbye" << endl << endl;

}

void GUI::notify(string message){

    cout << endl << atest << message << endl2;

}

void GUI::ask(string question){

    cout << endl << atestQ << question << endl2;

}

void GUI::list(vector<Event*> eventsList){

    cout << endl;
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << " | ID | LABEL " << endl;

    for (size_t i = 0; i < eventsList.size(); i++){
        
        cout << " |  " << eventsList[i]->getID() << " | " << eventsList[i]->getLabel() << endl;

    }

    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl2;

}

void GUI::waitingNextCommand(){

    cout << endl << atest << "Waiting for another command from the user" << endl2;

}

void GUI::invalidCommand(){

    cout << endl;
    cout << atestE << "Invalid command!" << endl;
    cout << atest << "Digit help for the list of commands" << endl;

}

void GUI::error(string e){

	cout << endl << atestE << "Error: " << e << endl2;

}

void GUI::help(){

	string help = "Help section:\n\tAdd: type \"add\" to add an event. Instructions of what to insert will be followed\n\n\tUpdate: type \"update\" to modify an already existing event. Instructions of what to insert will be followed\n\n\tRemove: type \"remove\" to delete an already existing event. Instructions of what to insert will be followed\n\n\tRemove All: type \"removeall\" to delete all the events present in the file. Instructions of what to insert will be followed\n\n\tFilter: type \"filter\" to select a subset of events from the existing events saved into the file. Instructions of what to insert will be followed\n\n\tPrint: type \"print\" to print all the present events. Instructions of what to insert will be followed\n\n\tShow All: type \"showall\" to print all the present events. Instructions of what to insert will be followed\n\n\tCheck: type \"check\" to take a look at the events. Instructions of what to insert will be followed\n\n\tHelp: type \"help\" to get help\n\n\tExit: type \"exit\" to log out from the application\n";

	cout << endl << help << endl2;

}

void GUI::pengui(){

    cout << endl;

    cout << atest << "   __" << endl;
    cout << atest << "-=(o '." << endl;
    cout << atest << "   '.-.\\" << endl;
    cout << atest << "   /|  \\\\" << endl;
    cout << atest << "   '|  ||" << endl;
    cout << atest << "    _\\_):,_" << endl;

    cout << endl2;

}