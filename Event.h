#ifndef EVENT_H
#define	EVENT_H

#include <iostream>
using namespace std;

class Event {
    private:
        string label, description;
	//time_t date;
        // Temporary we work with time as a string (without any check)
        string startDate;

    public:
        Event();
        ~Event();
    
        void setStartDate(string date1);
        string getStartDate();
        void setLabel(string label1);
        string getLabel();
        void setDesc(string desc1);
        string getDesc();
};

#endif	/* EVENT_H */

