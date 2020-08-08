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
    }

    // clear screen
    static void clear(){
        int counter = 0;
        while(counter < 100){
            puts("\n");
            counter++;
        }
    }

};
