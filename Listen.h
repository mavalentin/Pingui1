#ifndef LISTEN_H
#define	LISTEN_H
#include <iostream>
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
};

#endif	/* LISTEN_H */