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
	time_t date;
    
    public:
        Event();
        ~Event();
    
        void setDate(time_t date1);
        time_t getDate();
        void setLabel(string label1);
        string getLabel();
        void setDesc(string desc1);
        string getDesc();
};

#endif	/* EVENT_H */

