#ifndef MANAGE_H
#define	MANAGE_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <list>
#include "Event.h"
#include "MeetingEvent.h"
using namespace std;

class Manage {
public:
    Manage();
    ~Manage();
    void appendToFile(string data);
    string currentTime();
    void showAllEvents();
    string readFromFile();
    void createNewEvent(string type, string data);
    
private:
    list<MeetingEvent> eventsList; //must be a list of generic Events -> solve polymorphism problem for the list
};

#endif	/* MANAGE_H */

