/* 
 * File:   Manage.h
 * Author: Manuel
 *
 * Created on 27. April 2016, 15:55
 */

#ifndef MANAGE_H
#define	MANAGE_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class Manage {
public:
    Manage();
    ~Manage();
    void appendToFile(string data);
    string currentTime();
    void showAllEvents();
    string readFromFile();
    void createNewEvent(string type);
    
private:

};

#endif	/* MANAGE_H */
