/*  
 *  Free University of Bolzano, Software Engineering 2015/2016
 *  Authors: Marco Mondini, Luca Sabiucciu, Manuel Valentin
 *  Project name: Pingui
 *  Goal: Simple command based todo-list, for saving, removing and updating appointments 
 */
 
#ifndef LISTEN_H
#define	LISTEN_H
#include <iostream>
#include "Manage.h"
#include "GUI.h"
using namespace std;

class Listen 
{
    public:
    Listen();
        Listen(const Listen& orig);
        virtual ~Listen();
        string listenLabel(string type);
        string listenStartDate(string type);
        string listenEndDate(string type);
        string listenDescription(string type);
        string listenLocation(string type);
    void removeAll();
    private:
        Manage m;
        GUI gui;
};

#endif	/* LISTEN_H */