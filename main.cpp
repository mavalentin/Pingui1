/* 
 * File:   main.cpp
 * Author: Manuel
 *
 * Created on 27. April 2016, 14:41
 */

#include <iostream>
#include "DeadlineEvent.h"
#include "Manage.h"
#include "Listen.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Manage m;
    Listen l;
    cout << "****************************" << endl;
    cout << "****************************" << endl;
    cout << "********* Welcome to PINGUI!" << endl;
    cout << "*********" << endl;
    cout << "*********" << endl;
    m.appendToFile("Another day with Pingui "+m.currentTime());    
    
    while(1)
	{
		l.listener();
	}

    //DeadlineEvent d;
    return 0;
}
//sdfsdfsdfsdf

//sdfsdfsdfsdf
//ciao
//rew
