/* 
 * File:   Event.h
 * Author: Manuel
 *
 * Created on 27. April 2016, 14:42
 */

#ifndef EVENT_H
#define	EVENT_H

#include <iostream>
using namespace std;

class Event {
    private:
        string label, description;
	//time_t date;
        // Temporary we work with time as a string (without any check)
        string date;

    public:
        Event();
        ~Event();
    
        void setDate(string date1);
        string getDate();
        void setLabel(string label1);
        string getLabel();
        void setDesc(string desc1);
        string getDesc();
};

#endif	/* EVENT_H */

