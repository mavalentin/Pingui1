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


string Listen::listenLabel(string type, string action) {
    string label;
    
    if(action=="new"){
    while (label.empty()){
        gui.ask("Insert the name of the "+type);
        getline(cin, label);
        if (label.empty()){
            gui.error("A name is required");
        }
    }
    }
    
    else if(action=="update"){
        gui.ask("Enter the new name (empty for same)");
        getline(cin, label);
    }
    return label;
    
}    
    
string Listen::listenStartDate(string type, string action){
    string startDate;
    bool available;
    if(action=="new"){
        while (available==false || startDate.empty()){
            gui.ask("Insert the date and time of the "+type);
            getline(cin, startDate);

            if (startDate.empty()){
                gui.error("A date and time is required");
            }
            else{
                
            available=m.checkAvailability(startDate);
            if (available==true){
                }
            else {
                gui.error("The selected day is not available");
                gui.error("Please select another day");
            }
            }
        }
    }
    
    else if(action=="update"){
        while (available==false){
            gui.ask("Enter the new date (empty for same)");
            getline(cin, startDate);

            available=m.checkAvailability(startDate);
            if (available==true){
                }
            else {
                gui.error("The selected day is not available.\nPlease select another day");
            }
            }
        }
    
    
    return startDate;
}

string Listen::listenEndDate(string type, string action){
    string endDate;
    if(action=="new"){
        while (endDate.empty()){
            gui.ask("Insert the ending date and time of the "+type);
            getline(cin, endDate);
            if (endDate.empty()){
                gui.error("An end date is required");
            }
        }
    }
    
    else if (action=="update"){
        gui.ask("Enter the new end date (empty for same)");
        getline(cin, endDate);
    }
    return endDate;
}

string Listen::listenDescription(string type, string action){
    string description;
    if(action=="new"){
        gui.ask("Insert the description of the "+type);
        getline(cin, description);
    }
    
    else if(action=="update"){
        gui.ask("Enter the new description (empty for same)");
        getline(cin, description);
    }
    
    return description;
}

string Listen::listenLocation(string type, string action){
    string location;
    if(action=="new"){
        gui.ask("Insert the location of the "+type);
        getline(cin, location);
    }
    
    else if(action=="update"){
        gui.ask("Enter the location (empty for same)");
        getline(cin, location);
    }
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
        m.emptyFile();
        
        gui.notify("All events have been removed");
        m.readAllFromFile();
    }
    else
        gui.warn("Aborted remove all");
    
}

void Listen::addEvent()
{
    string user_input;
    gui.ask("Select if the event is a \"meeting\" or a \"deadline\"");
    getline(cin,user_input);
    m.createNewEvent(user_input);
}

void Listen::updateEvent(){
    string user_input;
    gui.ask("Enter the ID of the event to update");
    getline(cin,user_input);
    m.updateEvent(user_input);
}

int Listen::listenForID(){
    string id;
    int iid=-1;
    int pos=-2;
    int size=m.eventsList.size();
    while(iid<0 || iid>=size || pos != id.size()-1){
        if(iid>=size){
            gui.error("ID not found.");
        }
        gui.ask("Please enter the ID of the event");
        
        getline(cin, id);
        iid=atoi(id.c_str());
        pos=id.find_last_of("0123456789");
        
        if (pos != id.size()-1){
            gui.error("Enter only integers");
        }
        
        if(iid<0){
            gui.error("ID not found.");
        }
    }
    
    return iid;
}