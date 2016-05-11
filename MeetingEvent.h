/*  
 *  Free University of Bolzano, Software Engineering 2015/2016
 *  Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 *  Project name: Pingui
 *  Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */

#ifndef MEETINGEVENT_H
#define	MEETINGEVENT_H

#include <iostream>
#include "./Event.h"

using namespace std;

class MeetingEvent: public Event {
public:
    MeetingEvent();
    MeetingEvent(const MeetingEvent& orig);
    virtual ~MeetingEvent();

    void setEndDate(string date1);
    string getEndDate();
    void setLocation(string date1);
    string getLocation();
private:
	// Temporary we work with date as string (without any check)
	string endDate;
	string location;
};

#endif	/* MEETINGEVENT_H */

