/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */

#include "./GUI.h"

// Predefined string used as appendix of the program outputs, to make it clean and more readable
const string atext = "   °°° ";
const string atextQ = "  ?°°° ";
const string atextE = "  !°°° ";
const string endl2 = "\n\n       ";

GUI::GUI() {
}

GUI::~GUI() {
}

// Welcome message called when the program starts

void GUI::welcome() {

    cout << endl << atext << "Welcome to PINGUI!" << endl2;

    // Print 'Pingui' (the logo) on the screen
    pingui();

}


// Hello message, printed out before killing the program

void GUI::greetings() {

    cout << endl << atext << "Goodbye" << endl << endl;

}


// Methods to print on the screen the message with the correct appendix
// In order to highlight the type of message 

void GUI::notify(string message) {
    cout << endl << atext << message << endl;
}

void GUI::ask(string question) {
    cout << endl << atextQ << question << ": ";
}

void GUI::warn(string warning) {
    cout << endl << atextE << warning << endl;
}

void GUI::error(string e) {
    cout << endl << atextE << "ERROR: " << e << endl;
}


// Print on the screen a list of Event objects

void GUI::list(vector<Event*> eventsList) {

    cout << endl << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl << endl;
    cout << atext << " ID | DATE | LABEL " << endl << endl;

    for (size_t i = 0; i < eventsList.size(); i++) {
        //a summary is shown, with only index, date and name
        cout << atext << "  " << m.getEventIndex(eventsList[i]) << " |  " << eventsList[i]->getStartDate() << " | " << eventsList[i]->getLabel() << endl;

    }

    cout << endl << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl2;

}

// Print on the screen single event, with its complete data

void GUI::print(Event* event) {
    cout << endl << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl << endl;

    //Print the event data based on the event type
    if (MeetingEvent * meeting = dynamic_cast<MeetingEvent*> (event)) {
        cout << atext << "/|\\MEETING/|\\\n" << endl;
        cout << atext << "ID: " << m.getEventIndex(event) << endl;
        cout << atext << "LABEL: " << meeting->getLabel() << endl;
        cout << atext << "START DATE: " << meeting->getStartDate() << endl;
        cout << atext << "END DATE: " << meeting->getEndDate() << endl;
        cout << atext << "LOCATION: " << meeting->getLocation() << endl;
        cout << atext << "DESCRIPTION: " << meeting->getDesc() << endl;
    }
    else if (DeadlineEvent * deadline = dynamic_cast<DeadlineEvent*> (event)) {
        cout << atext << "/|\\DEADLINE/|\\\n" << endl;
        cout << atext << "ID: " << m.getEventIndex(event) << endl;
        cout << atext << "LABEL: " << deadline->getLabel() << endl;
        cout << atext << "DATE: " << deadline->getStartDate() << endl;
        cout << atext << "DESCRIPTION: " << deadline->getDesc() << endl;
    }


    cout << endl << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl2;

}


// Method called in the main when a command is finished and the program is ready to listen again

void GUI::waitingNextCommand() {

    cout << endl << atext << "Waiting for another command from the user.. " << endl2;

}


// Method to alert the user that the insert command is not valid

void GUI::invalidCommand() {

    cout << endl << atextE << "Invalid command. Digit 'help' for the list of commands.";

}


// Print the list of availble commands

void GUI::help() {

    cout << endl << atext << "HELP SECTION" << endl << endl;
    cout << atext << "Add       -> 'add' to create a new event." << endl;
    cout << atext << "Update    -> 'update' to modify an already existing event." << endl;
    cout << atext << "Remove    -> 'remove' to delete an already existing event." << endl;
    cout << atext << "Remove all-> 'removeall' to delete all the events present in the file." << endl;
    cout << atext << "Find      -> 'find' to select a subset of events by name." << endl;
    cout << atext << "Print     -> 'print' to print all the present events." << endl;
    cout << atext << "Show all  -> 'showall' to print all the present events." << endl;
    cout << atext << "Check     -> 'check' to take a look at the events." << endl;
    cout << atext << "Exit      -> 'exit' or 'bye' to log out from the application." << endl;

}


// Print a funny penguin on the screen

void GUI::pingui() {

    cout << endl;

    cout << atext << "   __" << endl;
    cout << atext << "-=(o '." << endl;
    cout << atext << "   '.-.\\" << endl;
    cout << atext << "   /|  \\\\" << endl;
    cout << atext << "   '|  ||" << endl;
    cout << atext << "    _\\_):,_" << endl;

    cout << endl2;

}