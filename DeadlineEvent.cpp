/* 
 * File:   deadlineEvent.cpp
 * Author: Manuel
 * 
 * Created on 27. April 2016, 15:04
 */

#include "DeadlineEvent.h"
DeadlineEvent::DeadlineEvent(string t) {
    cout << "creating deadlineevent object" << endl;

    timex = t;
}

DeadlineEvent::~DeadlineEvent() {
    cout << "destroying deadlineevent object" << endl;
}

void DeadlineEvent::setTime(string t) {
        timex=t;
}
string DeadlineEvent::getTime() {
        return timex;
}