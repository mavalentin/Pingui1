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
    void createNewEvent(string type);
    
private:
    vector<Event*> eventsList; //access objects with * and objectvariables with ->
};

#endif	/* MANAGE_H */

