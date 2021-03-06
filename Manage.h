/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */

#ifndef MANAGE_H
#define MANAGE_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "Event.h"
#include "MeetingEvent.h"
#include "DeadlineEvent.h"
#include <sstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Manage {
public:
    Manage();
    ~Manage();
    void appendToFile(string data);
    void emptyFile();
    string currentTime();
    void showAllEvents();
    void readAllFromFile();
    template<typename T> string constructDataString(T* event);
    void updateFile();
    void createNewEvent(string type);
    void updateEvent(string id);
    //void setEventID(Event *e);
    void listenToData(string type);
    void removeEvent();
    void clearList(vector<Event*> eventsList);
    void find();
    bool checkAvailability(string date);
    int getEventIndex(Event* e);
    int stringToInt(string s);
    string intToString(int i);
    void check();
    void print();
    static vector<Event*> eventsList;

private:
    string name, description, startDate, endDate, location;
};

#endif /* MANAGE_H */

