#include <stdio.h>
#include <stdlib.h>
#include "TimeTracker.h"
#include "OutputControl.h"

class Menu {
public:
    // constructor
    Menu() {
        this->sessionsSet = new TimeTracker();
    }
    // destructor
    ~Menu() {
        delete this->sessionsSet;
    }


    //
    void printOptionsMenu() {

        while(true) {
            OutputControl::clear();
            
            // list sessions
            this->sessionsSet->listSessions();
            int choice = Menu::chooseFromMenu();

            switch(choice) {

                case 1:
                    addSession();
                    break;

                case 2:
                    getSessionTime();
                    break;

                case 3:

                    break;

                case 4:

                    break;

                case 5:
                    puts(RED);
                    puts("Have a nice day!");
                    puts(RESET);
                    exit(0);

                default:
                    puts(RED);
                    puts("Yo choose right next time....");
                    puts(RESET);
            }

            OutputControl::hold();
            //while(getchar() != '\n');

        }
    } 

private: // variables
    TimeTracker *sessionsSet;

private: // functions
    // select an option from menu
    int chooseFromMenu() {
    
        puts("Menu:");
        puts("1. Add a session");
        puts("2. Get a session's spent time");
        puts("3. End a session");
        puts("4. Save sessions to file and exit");
        puts("5. Exit\n");
        printf("Select sth: ");
        int choice;
        scanf("%d", &choice);

        return choice;
    }

    // add a session to the given session set
    void addSession() {
        char sessionName[99];
        printf("enter session's name: ");
        scanf("%s", sessionName);
        sessionsSet->addSession(sessionName);
    }

    // print spent time of a session
    void getSessionTime() {
        char sessionName[99];
        printf("enter session's name: ");
        scanf("%s", sessionName);
        printf("You've spent %d seconds on %s\n", sessionsSet->getSessionTime(sessionName), sessionName);
    }

};
