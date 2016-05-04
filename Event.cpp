/* 
 * File:   Event.cpp
 * Author: Manuel
 * 
 * Created on 27. April 2016, 14:42
 */

#include "./Event.h"

Event::Event() {
        cout << "creating event object" << endl;
}

Event::~Event() {
        cout << "destroying event object" << endl;
}


void Event::setDate(string date1) {
        date=date1;
}
string Event::getDate() {
        return date;
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

