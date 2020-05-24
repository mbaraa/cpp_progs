// C
#include <stdio.h>  // C library to perform Input/Output operations
#include <time.h>   // C Time Library
#include <unistd.h> // UNIX Process management API 
int main(void) {
    time_t rawtime;   // typedef long time_t, you know the rest :)
    
    while(1){
      system("clear"); // clear the screen for better formatting
      time(&rawtime); // assign current time to the variable t
      char **time_string = ctime(&rawtime); /* string to hold the time,
      							 not necessary at all but I like to see pointers :) */
      printf("\nTime:\n%s", time_string); // finally print the time
      sleep(1); // wait one second to see seconds changing :)
    }
    
    return 0;
}
