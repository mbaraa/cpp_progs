#ifndef OUTPUTCONTROL_H
#define OUTPUTCONTROL_H

#include <stdio.h>
#include <iostream>

// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

class OutputControl {
public:
    
    // press key to continue
    static void hold(){

        puts("\npress enter to continue....");
        std::cin.ignore();

    } // static void hold

    // clear screen
    static void clear() {
        printf("\033[H\033[2J");
    
    } // static void clear

}; // class OutputControl

#endif // OUTPUTCONTRROL_H