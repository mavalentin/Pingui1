#include "./Event.h"

Event::Event() {
        cout << "creating event object" << endl;
}

Event::~Event() {
        cout << "destroying event object" << endl;
}


void Event::setStartDate(string date1) {
        startDate=date1;
}
string Event::getStartDate() {
        return startDate;
}

void Event::setLabel(string label1) {
        label=label1;
}
string Event::getLabel() {
        return label;
}

void Event::setDesc(string desc1) {
        description=desc1;
}
string Event::getDesc() {
        return description;
}

