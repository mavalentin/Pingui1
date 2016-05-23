/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */
 
#ifndef MANAGE_H
#define	MANAGE_H
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
    void createNewEvent(string type);
    void setEventID(Event *e);
    void listenToData(string type);
    void removeEvent(string id);
    void clearList(vector<Event*> eventsList);
    void filter();
    
private:
    vector<Event*> eventsList; //access objects with * and objectvariables with ->
    string name, description, startDate, endDate, location;
    string intToString(int i);
};

#endif	/* MANAGE_H */

