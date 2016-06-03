/*  
 *  Free University of Bolzano, Software Engineering 2015/2016
 *  Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 *  Project name: Pingui
 *  Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class Event {
private:
    string label, description;
    //time_t date;
    // Temporary we work with time as a string (without any check)
    string startDate;
    //int id;

public:
    Event();
    virtual ~Event();

    void setStartDate(string date1);
    string getStartDate();
    void setLabel(string label1);
    string getLabel();
    void setDesc(string desc1);
    string getDesc();
    /*void setID(int i);
    int getID();*/
};

#endif /* EVENT_H */

