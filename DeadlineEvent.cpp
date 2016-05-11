/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */

#include "DeadlineEvent.h"
DeadlineEvent::DeadlineEvent() {
    cout << "creating deadlineevent object" << endl;
}

DeadlineEvent::~DeadlineEvent() {
    cout << "destroying deadlineevent object" << endl;
}



/*
void DeadlineEvent::setTime(string t) {
        timex=t;
}
string DeadlineEvent::getTime() {
        return timex;
}*/