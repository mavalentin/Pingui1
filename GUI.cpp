/*	
 *	Free University of Bolzano, Software Engineering 2015/2016
 *	Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 * 	Project name: Pingui
 *	Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */
 
#include "./GUI.h"

GUI::GUI() {
        //cout << "creating gui object" << endl;
}

GUI::~GUI() {
        //cout << "destroying gui object" << endl;
}

void GUI::printAll(vector<Event*> eventsList){

    cout << "***************************************" << endl;
    cout << " | ID | LABEL " << endl;

    for (size_t i = 0; i < eventsList.size(); i++){
        //create the string for output

        cout << " |  " << eventsList[i]->getID() << " | " << eventsList[i]->getLabel() << endl;

    }
    
    cout << "***************************************" << endl;

}