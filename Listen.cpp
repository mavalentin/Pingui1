/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */
 
#include "Listen.h"

Listen::Listen() 
{
}

Listen::Listen(const Listen& orig) 
{
}

Listen::~Listen() 
{
}


string Listen::listenLabel(string type) {
    string label;
    while (label.empty()){
        gui.ask("Insert the name of the "+type);
        getline(cin, label);
        if (label.empty()){
            gui.error("A name is required");
        }
    }
    return label;
}    
    
string Listen::listenStartDate(string type){
    string startDate;
    bool available;
    while (available==false || startDate.empty()){
        gui.ask("Insert the date and time of the "+type);
        getline(cin, startDate);
        
        if (startDate.empty()){
            gui.error("A date and time is required");
        }
        else{
        available=m.checkAvailability(startDate);
        if (available==true){
            cout << "L:this is available"<<endl;
            }
        else {
            gui.error("The selected day is not available.\nPlease select another day");
        }
        }
    }
    return startDate;
}

string Listen::listenEndDate(string type){
    string endDate;
    while (endDate.empty()){
        gui.ask("Insert the ending date and time of the "+type);
        getline(cin, endDate);
        if (endDate.empty()){
            gui.error("An end date is required");
        }
    }
    return endDate;
}

string Listen::listenDescription(string type){
    string description;
    gui.ask("Insert the description of the "+type);
    getline(cin, description);
    
    return description;
}

string Listen::listenLocation(string type){
    string location;
    gui.ask("Insert the location of the "+type);
    getline(cin, location);
    
    return location;
}

void Listen::removeAll()
{
    // Remove all the data stored in the database file
    gui.notify("You are about to remove all the saved events");
    gui.ask("Do you really want to continue? [Y/n]");
    string command;
    getline(cin, command);
    if(command == "Y" || command == "y")
    {
        gui.notify("Selected remove all");
        m.emptyFile();
    }
    else
        gui.notify("Aborted remove all");
}