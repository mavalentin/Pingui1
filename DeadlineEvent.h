/* 
 * File:   deadlineEvent.h
 * Author: Manuel
 *
 * Created on 27. April 2016, 15:04
 */

#ifndef DEADLINEEVENT_H
#define	DEADLINEEVENT_H

#include <iostream>
#include "./Event.h"
using namespace std;

class DeadlineEvent: public Event {
public:
    DeadlineEvent();
    ~DeadlineEvent();
private:
	// Temporary we work with time as a string (without any format check)
	string timex;
};

#endif	/* DEADLINEEVENT_H */

