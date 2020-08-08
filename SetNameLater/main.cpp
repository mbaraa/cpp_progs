#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "TimeTracker.h"
// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

void hold(){
    puts("\npress enter to continue....");
    // getchar is used to input a character
    while(getchar() != '\n');
}

int main() {

    TimeCapsule *t = new TimeCapsule();

    /*while(true) {
        puts("Select sth:");
        puts("1. Start session");
        puts("2. End Session and print result");
        short choice;
        scanf("%d", &choice);
        printf("%d\n", choice);

        switch(choice) {
            case 1:
                t->setTime();
                break;
            case 2:
                printf("You've spent %d seconds on this\n", t->setTime());
                break;
            case 3:
                puts(t->getCurrentTime());
                break;
            default:
                puts(RED);
                puts("Yo choose right next time....");
                puts(RESET);
        }
        hold();
        while(getchar() != '\n');

    }
*/

   /* std::map<char *, TimeCapsule> sessions;
    sessions["s1"].updateCurrentTime();
    sleep(3);
    sessions["s2"].updateCurrentTime();
    sleep(3);
    sessions["s3"].updateCurrentTime();
    sleep(4);
    sessions["s4"].updateCurrentTime();
    sleep(2);

    printf("spent time of session 1 is: %d seconds\n", sessions["s1"].getSpentTime());
    printf("spent time of session 2 is: %d seconds\n", sessions["s2"].getSpentTime());
    printf("spent time of session 3 is: %d seconds\n", sessions["s3"].getSpentTime());
    printf("spent time of session 4 is: %d seconds\n", sessions["s4"].getSpentTime());
*/    
    TimeTracker tr;
    tr.addSession("foo");
    sleep(2);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaa: %d\n",  tr.getSessionTime("foo") );

    return 0;
}
