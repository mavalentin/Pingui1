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
using namespace std;

class Manage {
public:
    Manage();
    ~Manage();
    void appendToFile(string data);
    void emptyFile();
    string currentTime();
    void showAllEvents();
    string readAllFromFile();
    template<typename T> string constructDataString(T* event);
    void createNewEvent(string type);
    void setEventID(Event *e);
    
private:
    vector<Event*> eventsList; //access objects with * and objectvariables with ->
};

#endif	/* MANAGE_H */

