/* 
 * File:   MeetingEvent.cpp
 * Author: Manuel
 * 
 * Created on 27. April 2016, 15:25
 */

#include "MeetingEvent.h"

MeetingEvent::MeetingEvent() {
}

MeetingEvent::MeetingEvent(const MeetingEvent& orig) {
}

MeetingEvent::~MeetingEvent() {
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