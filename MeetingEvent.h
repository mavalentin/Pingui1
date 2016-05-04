/* 
 * File:   MeetingEvent.h
 * Author: Manuel
 *
 * Created on 27. April 2016, 15:25
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

