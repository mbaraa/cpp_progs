#ifndef PROGRAMMENU_H
#define PROGRAMMENU_H

#include "Menu.h" // super slavic scrolable menu
#include "MoneyTracker/AllTrackers.h" // the whole shit
#include <stdlib.h> // exit
#include <stdio.h> // lol
#include <string> // lol
#include <iostream> // cin
#include "../Headers/OutputControl.hpp" // clear, hold

using std::string;
using std::cin;

class ProgramMenu {
public:

    ~ProgramMenu() {
        delete this->moneyTrackers;
        delete this->subMenu;

    }

    static ProgramMenu *getInstance() {

        if( !instance ) {
            instance = new ProgramMenu();

        }


        return instance;
    }

    void selectOption() {
        bool sthSelected = false;
        string sessionName;

        while(true) {

            // it's needed, because of listener business
            if(sthSelected) {
                this->moneyTrackers->selectOption();
            }

            switch( this->moneyTrackers->selectOption() ) {
            
            case 1:
                printf("Enter session name: ");
                std::getline(cin, sessionName);
                this->trackMoney(new NoIncrease(sessionName));
                sthSelected = true;
                break;

            case 2:        
                printf("Enter session name: ");
                std::getline(cin, sessionName);
                this->trackMoney(new MonthlyIncrease(sessionName));
                sthSelected = true;
                break;

            case 3:
                printf("Enter session name: ");
                std::getline(cin, sessionName);
                this->trackMoney(new YearlyIncrease(sessionName));
                sthSelected = true;
                break;

            case 4:
                exit(0);

            default:
                puts("\033[33mOJ BLYAT THIS WON'T BE AVAILABLE DUE TO MY VERY BLYATEFUL MENU :)");

            }
            
        
	    }

    }

    void printWelcomeScreen() {
        OutputControl::clear();
        printf("\n\nSpending Logger\n\n");
        printf("\ncreated @ some date\n\n");
        printf("this program uses vim controls for menu scrolling!!\n");
        printf("'j' to move down\n'k' to move up\n");
        printf("Happy spending!!\n");
        OutputControl::hold();

    }

private:
    Menu *moneyTrackers;
    Menu *subMenu;
    MoneyTracker *tracker;

    static ProgramMenu *instance;

private: // functions

    // singleton reasons :)    
    ProgramMenu() {
        this->moneyTrackers = new Menu();
        this->subMenu = new Menu();
        this->initMenus();
    
    }

    // initalize menus with proper options
    void initMenus() {
        this->moneyTrackers->addOption("Track With No Increase");
        this->moneyTrackers->addOption("Track With Monthly Increase");
        this->moneyTrackers->addOption("Track With Yearly Increase");
        this->moneyTrackers->addOption("Exit");

        this->subMenu->addOption("Put Money");
        this->subMenu->addOption("Draw Money");

    }

    void trackMoney(MoneyTracker *tracker) {
        double money;
        string reason;

        switch( this->subMenu->selectOption() ) {

        case 1:
            printf("enter income reason: ");
            cin >> reason;
            printf("enter ammount of money added: ");
            cin >> money;
            tracker->putMoney(money, reason);
            break;

        case 2:
            printf("enter outcome reason: ");
            cin >> reason;
            printf("enter ammount of money spent: ");
            cin >> money;
            tracker->drawMoney(money, reason);
            break;

        }

        // hahahaha
        delete tracker;
    }


};

// fucking crazy C++ requires initializing statics outside the class
ProgramMenu *ProgramMenu::instance = nullptr;

#endif //PROGRAMMENU_H