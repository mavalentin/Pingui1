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
    cout << "********* Welcome to PINGUI! **********" << endl;
    m.appendToFile("Another day with Pingui "+m.currentTime());    
    
    //initialize listening
    l.listener();
    

    return 0;
}