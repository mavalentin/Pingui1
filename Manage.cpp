/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */

#include "Manage.h"
#include "Listen.h"
#include "GUI.h"

Listen l;
GUI gui;

Manage::Manage() {
}

Manage::~Manage() {
}

//Write data to file

void Manage::appendToFile(string data) {
    //Creates a filestream
    fstream file;
    //Creates and opens the file
    file.open("database.dat", fstream::app | fstream::out);
    //Writes something on the file
    file << data;
    //Closes the file
    file.close();
}

//Empty the whole file

void Manage::emptyFile() {
    //Creates a filestream
    fstream file;
    //Truncates the file
    file.open("database.dat", fstream::out | fstream::trunc);
    //Closes the file
    file.close();

}

//Clear the list of events

void Manage::clearList(vector<Event*> eventsList) {
    //iterate through list, deallocate memory of dynamic objects and clear the list
    vector<Event*>::iterator it;
    for (it = eventsList.begin(); it < eventsList.end(); it++) {
        delete *it;
    }
    eventsList.clear();
}

//Return current time

string Manage::currentTime() {
    time_t t = time(NULL);
    return asctime(localtime(&t));
}

//Print all the events on the command line

void Manage::showAllEvents() {
    gui.list(eventsList);
}

//Read and import all events from the file

void Manage::readAllFromFile() {
    //Reader for the file
    ifstream file;
    //Open the file
    file.open("database.dat", fstream::in);
    string line;
    string result;
    MeetingEvent *tempmeeting;
    DeadlineEvent *tempdeadline;


    //DELETION OF OLD OBJECTS
    //empty the vecor list and recreate events from read file
    eventsList.clear();

    //RECREATION OF OBJECTS
    //Checks if file has been opened
    if (file.is_open()) {

        while (getline(file, line)) {
            //iterate through file

            //if meeting found, get its 5 pieces of data
            if (line.find("/|\\MEETING/|\\") != string::npos) {
                tempmeeting = new MeetingEvent;
                for (int index = 1; index <= 5; index++) {
                    getline(file, line);

                    switch (index) {

                        case (1):
                            tempmeeting->setLabel(line);
                            break;

                        case (2):
                            tempmeeting->setDesc(line);
                            break;

                        case (3):
                            tempmeeting->setStartDate(line);
                            break;

                        case (4):
                            tempmeeting->setEndDate(line);
                            break;

                        case (5):
                            tempmeeting->setLocation(line);
                    }
                }

                //add the newly created event to the list
                MeetingEvent *newevent = tempmeeting;
                eventsList.push_back(newevent);


            }//if deadline found, get its 3 pieces of data
            else if (line.find("/|\\DEADLINE/|\\") != string::npos) {
                tempdeadline = new DeadlineEvent;
                for (int index = 1; index <= 3; index++) {
                    getline(file, line);

                    switch (index) {

                        case (1):
                            tempdeadline->setLabel(line);
                            break;

                        case (2):
                            tempdeadline->setDesc(line);
                            break;

                        case (3):
                            tempdeadline->setStartDate(line);
                            break;

                    }
                }
                //add the newly created event to the list
                DeadlineEvent *newevent = tempdeadline;
                eventsList.push_back(newevent);
            }

        }
        //Closes the file
        file.close();
    } else
        gui.error("Impossible to open the file");

    gui.notify("Pingui found " + intToString(eventsList.size()) + " events");

}

//Integer to String converter

string Manage::intToString(int i) {
    //convert integer to string
    stringstream sstm;
    sstm << i;
    return sstm.str();
}

//String to Integer converter

int Manage::stringToInt(string s) {
    return atoi(s.c_str());
}

//Serialize the event object, create a string which can be written to file

template<typename T> string Manage::constructDataString(T* event) {
    string dataString = event->getLabel() + "\n" + event->getDesc() + "\n" + event->getStartDate() + "\n";

    //add meeting-specific data to string
    if (MeetingEvent * m = dynamic_cast<MeetingEvent*> (event)) {
        dataString += m->getEndDate() + "\n" + m->getLocation() + "\n";
        string temp = dataString;
        dataString = "/|\\MEETING/|\\\n" + temp;
    }//add deadline-specific data to string
    else if (DeadlineEvent * m = dynamic_cast<DeadlineEvent*> (event)) {
        string temp = dataString;
        dataString = "/|\\DEADLINE/|\\\n" + temp;
    }


    return dataString;
}

//Update the file: empty it and re-export all the events to it

void Manage::updateFile() {
    //empty file
    emptyFile();
    //rewrite file with all events in the list
    vector<Event*>::iterator it;
    for (it = eventsList.begin(); it < eventsList.end(); it++) {
        Event *e = *it;
        appendToFile(constructDataString(e));
    }
}

//Get data from user input and save it

void Manage::listenToData(string type) {
    //Meeting-specific
    if (type == "meeting") {
        //NAME
        name = l.listenLabel(type, "new");
        cout << "" << endl;
        // If user inputs "abort", returns to the main menu
        if (name == "abort")
            return;
        //START DATE
        startDate = l.listenStartDate(type, "new");
        cout << "" << endl;
        // If user inputs "abort", returns to the main menu
        if (startDate == "abort")
            return;
        //END DATE
        endDate = l.listenEndDate(type, "new");
        cout << "" << endl;
        // If user inputs "abort", returns to the main menu
        if (endDate == "abort")
            return;
        //DESCRIPTION
        description = l.listenDescription(type, "new");
        cout << "" << endl;
        // If user inputs "abort", returns to the main menu
        if (description == "abort")
            return;
        //LOCATION
        location = l.listenLocation(type, "new");
        cout << "" << endl;
        // If user inputs "abort", returns to the main menu
        if (location == "abort")
            return;

        //Deadline-specific
    } else if (type == "deadline") {
        //NAME
        name = l.listenLabel(type, "new");
        cout << "" << endl;
        // If user inputs "abort", returns to the main menu
        if (name == "abort")
            return;
        //START DATE
        startDate = l.listenStartDate(type, "new");
        cout << "" << endl;
        // If user inputs "abort", returns to the main menu
        if (startDate == "abort")
            return;
        //DESCRIPTION
        description = l.listenDescription(type, "new");
        cout << "" << endl;
        // If user inputs "abort", returns to the main menu
        if (description == "abort")
            return;


    }
}

//Create a new event, and save it in list and file

void Manage::createNewEvent(string type) {
    string dataToWrite;

    //Meeting-specific
    if (type == "meeting") {
        MeetingEvent *event = new MeetingEvent;

        gui.notify("You selected the meeting event");

        //call listening function
        listenToData(type);


        // If user inputs "abort", returns to the main menu
        if (name == "abort" | startDate == "abort" | endDate == "abort" | description == "abort" | location == "abort")
            return;

        //set event variables
        event->setLabel(name);
        event->setStartDate(startDate);
        event->setEndDate(endDate);
        event->setDesc(description);
        event->setLocation(location);


        //insert event into the list
        eventsList.push_back(event);
        //construct string to write to file
        dataToWrite = constructDataString(event);

    }        //Deadline-specific
    else if (type == "deadline") {
        DeadlineEvent *event = new DeadlineEvent;
        gui.notify("You selected the deadline event");

        //call listening function
        listenToData(type);


        // If user inputs "abort", returns to the main menu
        if (name == "abort" | startDate == "abort" | description == "abort")
            return;

        //set event variables
        event->setLabel(name);
        event->setStartDate(startDate);
        event->setDesc(description);

        //insert event into the list
        eventsList.push_back(event);
        //construct string to write to file
        dataToWrite = constructDataString(event);

    }//check for abort
    else if (type == "abort")
        return;

    else {
        gui.error("Invalid event type!");
        return;
    }

    //write to file
    appendToFile(dataToWrite);
    gui.notify(("The event has been saved"));

}

//Update an event

void Manage::updateEvent(string id) {
    //Get a pointer to the event to update
    Event* e = eventsList[stringToInt(id)];

    //NAME
    name = l.listenLabel("", "update");
    // If user inputs "abort", returns to the main menu
    if (name == "abort")
        return;
    if (!name.empty()) {
        e->setLabel(name);
    }


    //STARTDATE
    startDate = l.listenStartDate("", "update");
    // If user inputs "abort", returns to the main menu
    if (startDate == "abort")
        return;
    if (!startDate.empty()) {
        e->setStartDate(startDate);
    }

    //ENDDATE
    //Only in case of a meeting
    if (MeetingEvent * m = dynamic_cast<MeetingEvent*> (e)) {
        endDate = l.listenEndDate("", "update");
        // If user inputs "abort", returns to the main menu
        if (endDate == "abort")
            return;
        if (!endDate.empty()) {
            m->setEndDate(endDate);
        }
    }

    //LOCATION
    //Only in case of a meeting
    if (MeetingEvent * m = dynamic_cast<MeetingEvent*> (e)) {
        location = l.listenLocation("", "update");
        // If user inputs "abort", returns to the main menu
        if (location == "abort")
            return;
        if (!location.empty()) {
            m->setLocation(location);
        }
    }

    //DESCRIPTION
    description = l.listenDescription("", "update");
    // If user inputs "abort", returns to the main menu
    if (description == "abort")
        return;
    if (!description.empty()) {
        e->setDesc(description);
    }


    //update file
    updateFile();
    gui.notify("The event has been updated");
}


//Remove an event

void Manage::removeEvent() {
    //get a valid id from user
    string sid = l.listenForID();

    //check for abort
    if (sid == "abort")
        return;

    int id = atoi(sid.c_str());

    vector<Event*>::iterator it = eventsList.begin();
    //Go to the right position according to the ID
    advance(it, id);

    //Get a pointer and remove the event
    Event* e = *(it);
    eventsList.erase(it);
    delete e;

    //update database file
    updateFile();
    gui.notify("The event has been removed");
}

//Find the events based on the name

void Manage::find() {
    string value_to_filter;

    gui.ask("Insert the name/label of the event");
    getline(cin, value_to_filter);

    //Iterate through list and find the matching names
    vector<Event*>::iterator it;
    std::vector<Event*> event;
    for (it = eventsList.begin(); it < eventsList.end(); it++) {
        //Match name with substring
        if (((*it)->getLabel()).find(value_to_filter) != std::string::npos)
            //Add the matching event to a vector list
            event.push_back(*it);
    }

    //Call the function for printing the found events on screen
    gui.list(event);
}

//Check the availability of a date

bool Manage::checkAvailability(string date) {
    vector<Event*>::iterator it;
    //iterates through list and return true of false based on if an event on the same day is found
    for (it = eventsList.begin(); it < eventsList.end(); it++) {
        if ((date.compare((*it)->getStartDate())) == 0) {
            return false;
        }
    }
    return true;
}

//Get the index in the list of a specific event

int Manage::getEventIndex(Event* e) {
    int pos = std::find(eventsList.begin(), eventsList.end(), e) - eventsList.begin();
    if (pos < eventsList.size()) {
        return pos;
    } else return -1;
}

//Check the availability of any date inserted by the user

void Manage::check() {
    string date;

    gui.ask("Enter the date to check (dd/mm/yyy)");
    getline(cin, date);

    //check for abort
    if (date == "abort")
        return;

    bool av = checkAvailability(date);
    if (av == false) {
        gui.error("This date is not available");
    }
    if (av == true) {
        gui.notify("This date is available");
    }
}

//Print to screen a speficic event

void Manage::print() {
    string sid = l.listenForID();

    //check for abort
    if (sid == "abort")
        return;

    int id = atoi(sid.c_str());
    gui.print(eventsList[id]);
}