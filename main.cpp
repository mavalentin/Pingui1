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
        string command;
        getline(cin, command);
        if(command == "add")
        {
            cout << "You selected add" << endl;
        }
        else
        {
            if(command == "update")
            {
                cout << "You selected update" << endl;
            }
            else
            {
                if(command == "remove")
                {
                    cout << "You selected remove" << endl;
                }
                else
                {
                    if(command == "filter")
                    {
                        cout << "You selected filter" << endl;
                    }
                    else
                    {
                        if(command == "print")
                        {
                            cout << "You selected print" << endl;
                        }
                        else
                        {
                            if(command == "check")
                            {
                                cout << "You selected check" << endl;
                            }
                            else
                            {
                                if(command == "exit")
                                {
                                    cout << "***********************Goodbye***********************" << endl;
                                    return 0;
                                }
                                else
                                {

                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //DeadlineEvent d;
    return 0;
}
//sdfsdfsdfsdf

//sdfsdfsdfsdf
//ciao
//rew
