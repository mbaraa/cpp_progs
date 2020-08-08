#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "TimeCapsule.h"
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

    while(true) {
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
            default:
                puts(RED);
                puts("Yo choose right next time....");
                puts(RESET);
        }
        hold();
        while(getchar() != '\n');

    }

    return 0;
}
