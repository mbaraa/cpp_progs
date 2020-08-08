#ifndef OUTPUTCONTROL_H
#define OUTPUTCONTROL_H

#include <stdio.h>

// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

class OutputControl {
public:
    
    // press key to continue
    static void hold(){

        puts("\npress enter to continue....");
        // getchar is used to input a character
        while(getchar() != '\n');
        while(getchar() != '\n');

    } // static void hold

    // clear screen
    static void clear(){

        int counter = 0;
        while(counter < 100){
            puts("\n");
            counter++;
        }

    } // static void clear

}; // class OutputControl

#endif // OUTPUTCONTRROL_H