/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */
 
#include "./Event.h"

Event::Event() {
        //cout << "creating event object" << endl;
}

Event::~Event() {
        //cout << "destroying event object" << endl;
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

/*int Event::getID(){
    return id;
}

void Event::setID(int i){
    id=i;
}*/
