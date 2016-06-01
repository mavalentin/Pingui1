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
#include <string>
using namespace std;

class GUI {
    private:
        
    public:
    	GUI();
        virtual ~GUI();
        void list(vector<Event*> eventsList);
        void print(Event* event);
        void error(string e);
        void invalidCommand();
        void notify(string message);
        void ask(string question);
        void warn(string warning);
        void help();
        void welcome();
        void greetings();
        void waitingNextCommand();
        void pingui();
};

#endif	/* GUI_H */