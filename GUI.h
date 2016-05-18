/*  
 *  Free University of Bolzano, Software Engineering 2015/2016
 *  Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 *  Project name: Pingui
 *  Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */
 
#ifndef GUI_H
#define	GUI_H

#include <iostream>
#include "./Event.h"
#include <vector>
using namespace std;

class GUI {
    private:
        
    public:
    	GUI();
        virtual ~GUI();
        void printAll(vector<Event*> eventsList);

};

#endif	/* GUI_H */