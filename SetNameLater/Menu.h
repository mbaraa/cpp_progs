#ifndef MENU_H
#define MENU_H 

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

    // print choice menu
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
                    endSession();
                    break;
                case 4:
                    _66();
                default:
                    puts(RED);
                    puts("Yo choose right next time....");
                    puts(RESET);

            } // switch
        
            OutputControl::hold();
        
        } //while

    } // void printOptionsMenu()

private: // variables
    TimeTracker *sessionsSet;

private: // functions
    // select an option from menu
    int chooseFromMenu() {
    
        puts("Menu:");
        puts("1. Add a session");
        puts("2. Get a session's spent time");
        puts("3. End a session");
        puts("4. Exit\n");
        printf("Select sth: ");
        int choice;
        scanf("%d", &choice);

        return choice;
    } // int chooseFromMenu

    // add a session to the given session set
    void addSession() {
    
        char sessionName[99];
        printf("enter session's name: ");
        scanf("%s", sessionName);
        sessionsSet->addSession(sessionName);
    
    }   // void addSession

    // print spent time of a session
    void getSessionTime() {
    
        char sessionName[99];
        printf("enter session's name: ");
        scanf("%s", sessionName);
        printf("You've spent %d seconds on %s\n", sessionsSet->getSessionTime(sessionName), sessionName);
    
    } // void getSessionTime

    // end a session
    void endSession() {
    
        char sessionName[99];
        printf("enter session's name: ");
        scanf("%s", sessionName);
        this->sessionsSet->endSession(sessionName);
    
    } // void endSession


    // exit 
    void _66() {
    
        this->sessionsSet->closeFile();
        puts(RED);
        puts("Have a nice day!");
        puts(RESET);
        exit(0);
    
    } // void execOrder66

}; // class Menu

#endif // MENU_H