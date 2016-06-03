/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */

#include "Listen.h"

Listen::Listen() {
}


Listen::~Listen() {
}

//FUNCTIONS FOR LISTENING VARIOUS DATA TYPES

//Listen Label

string Listen::listenLabel(string type, string action) {
    string label;

    //In case of creating new event
    if (action == "new") {
        while (label.empty()) {
            gui.ask("Insert the name of the " + type);
            getline(cin, label);
            if (label.empty()) {
                gui.error("A name is required");
            }
        }
    }//in case of updating an event
    else if (action == "update") {
        gui.ask("Enter the new name (empty for same)");
        getline(cin, label);
    }
    return label;

}

//Listen Start Date

string Listen::listenStartDate(string type, string action) {
    string startDate;
    bool available;

    //In case of creating new event
    if (action == "new") {
        while (available == false || startDate.empty()) {
            gui.ask("Insert the date (and time) of the " + type + " (dd/mm/yyyy mm:hh)");
            getline(cin, startDate);

            if (startDate.empty()) {
                gui.error("A date and time is required");
            } else {
                //check availability of date
                available = m.checkAvailability(startDate);
                if (available == true) {
                } else {
                    gui.error("The selected day is not available");
                    gui.error("Please select another day");
                }
            }
        }
    }//in case of updating an event
    else if (action == "update") {
        while (available == false) {
            gui.ask("Enter the new date (and time), (dd/mm/yyyy mm:hh) (empty for same)");
            getline(cin, startDate);

            //check availability of date
            available = m.checkAvailability(startDate);
            if (available == true) {
            } else {
                gui.error("The selected day is not available.\nPlease select another day");
            }
        }
    }


    return startDate;
}

//Listen End Date

string Listen::listenEndDate(string type, string action) {
    string endDate;

    //In case of creating new event
    if (action == "new") {
        while (endDate.empty()) {
            gui.ask("Insert the ending date (and time) of the " + type + " (dd/mm/yyyy mm:hh)");
            getline(cin, endDate);
            if (endDate.empty()) {
                gui.error("An end date is required");
            }
        }
    }//in case of updating an event
    else if (action == "update") {
        gui.ask("Enter the new end date (and time), (dd/mm/yyyy mm:hh) (empty for same)");
        getline(cin, endDate);
    }
    return endDate;
}

//Listen description

string Listen::listenDescription(string type, string action) {
    string description;

    //In case of creating new event
    if (action == "new") {
        gui.ask("Insert the description of the " + type);
        getline(cin, description);
    }//in case of updating an event
    else if (action == "update") {
        gui.ask("Enter the new description (empty for same)");
        getline(cin, description);
    }

    return description;
}

//Listen location

string Listen::listenLocation(string type, string action) {
    string location;

    //In case of creating new event
    if (action == "new") {
        gui.ask("Insert the location of the " + type);
        getline(cin, location);
    }//in case of updating an event
    else if (action == "update") {
        gui.ask("Enter the location (empty for same)");
        getline(cin, location);
    }
    return location;
}

//ADDITIONAL FUNCTIONS

//Remove all events

void Listen::removeAll() {
    // Remove all the data stored in the database file
    gui.notify("You are about to remove all the saved events");
    gui.ask("Do you really want to continue? [Y/n]");
    string command;
    getline(cin, command);
    if (command == "Y" || command == "y") {
        m.emptyFile();

        gui.notify("All events have been removed");
        m.readAllFromFile();
    } else
        gui.warn("Aborted remove all");

}

//Adding event, choose meeting or deadline

void Listen::addEvent() {
    string user_input;
    gui.ask("Select if the event is a \"meeting\" or a \"deadline\"");
    getline(cin, user_input);
    m.createNewEvent(user_input);
}

//Updating event, ask the ID of the event to update

void Listen::updateEvent() {
    string user_input;
    gui.ask("Enter the ID of the event to update");
    getline(cin, user_input);

    //check for abort
    if (user_input == "abort")
        return;

    m.updateEvent(user_input);
}


//ID Listener and checker

string Listen::listenForID() {
    string id;
    int iid = -1;
    int pos = -2;
    int size = m.eventsList.size();

    while (iid < 0 || iid >= size || pos != id.size() - 1) {
        if (iid >= size) {
            gui.error("ID not found.");
        }
        gui.ask("Please enter the ID of the event");

        getline(cin, id);

        //check for abort
        if (id == "abort")
            return id;

        //check id for validity and existence
        iid = atoi(id.c_str());
        pos = id.find_last_of("0123456789");

        if (pos != id.size() - 1) {
            gui.error("Enter only integers");
        }

        if (iid < 0) {
            gui.error("ID not found.");
        }
    }

    return id;
}