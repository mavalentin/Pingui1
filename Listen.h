/* 
 * File:   Listen.h
 * Author: Manuel
 *
 * Created on 27. April 2016, 16:02
 */

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
	    void listener();
	private:
};

#endif	/* LISTEN_H */