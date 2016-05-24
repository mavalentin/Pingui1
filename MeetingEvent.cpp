/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */
 
#include "MeetingEvent.h"

MeetingEvent::MeetingEvent() {
    //gui.notify("creating meetingevent object");
}

MeetingEvent::MeetingEvent(const MeetingEvent& orig) {
}

MeetingEvent::~MeetingEvent() {
    //gui.notify("destroying meetingevent object");
}

void MeetingEvent::setLocation(string l) {
        location=l;
}
string MeetingEvent::getLocation() {
        return location;
}

void MeetingEvent::setEndDate(string d) {
        endDate=d;
}
string MeetingEvent::getEndDate() {
        return endDate;
}