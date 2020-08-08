#include <stdio.h>
#include <stdlib.h>
#include "TimeTracker.h"

// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

// press key to continue
void hold(){
    puts("\npress enter to continue....");
    // getchar is used to input a character
    while(getchar() != '\n');
}

// clear screen
void clear(){
    int counter = 0;
    while(counter < 100){
        puts("\n");
        counter++;
    }
}

int selectMenu() {
    
    puts("Menu:");
    puts("1. Add a session");
    puts("2. Get a session's spent time");
    puts("3. Exit\n");
    printf("Select sth: ");
    int choice;
    scanf("%d", &choice);

    return choice;
}

//
void printOptionsMenu() {

    TimeTracker *timeSessions = new TimeTracker();
    char sessionName[99];

    while(true) {
        clear();
        int choice = selectMenu();

        switch(choice) {

            case 1:
                printf("enter session's name: ");
                scanf("%s", sessionName);
                timeSessions->addSession(sessionName);
                break;

            case 2:
                printf("enter session's name: ");
                scanf("%s", sessionName);
                printf("You've spent %d seconds on %s\n", timeSessions->getSessionTime(sessionName), sessionName);
                break;

            case 3:
                puts(RED);
                puts("Have a nice day!");
                puts(RESET);
                exit(0);

            default:
                puts(RED);
                puts("Yo choose right next time....");
                puts(RESET);
        }
        hold();
        while(getchar() != '\n');

    }
} 