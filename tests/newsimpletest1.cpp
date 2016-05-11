/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest1.cpp
 * Author: Manuel
 *
 * Created on 11. Mai 2016, 14:31
 */

#include <stdlib.h>
#include <iostream>
#include "Listen.h"

/*
 * Simple C++ Test Suite
 */

void testListenLabel() {
    string type;
    Listen listen;
    type="meeting";
    string result = listen.listenLabel(type);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testListenLabel (newsimpletest1) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest1" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testListenLabel (newsimpletest1)" << std::endl;
    testListenLabel();
    std::cout << "%TEST_FINISHED% time=0 testListenLabel (newsimpletest1)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

