/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */

#ifndef DEADLINEEVENT_H
#define DEADLINEEVENT_H

#include <iostream>
#include "./Event.h"
using namespace std;

class DeadlineEvent : public Event {
public:
    DeadlineEvent();
    virtual ~DeadlineEvent();

    //For now we have the time already together with the date


    //void setTime(string date1);
    //string getTime();

private:
    // Temporary we work with time as a string (without any format check)
    //string timex;
};

#endif /* DEADLINEEVENT_H */

