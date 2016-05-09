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