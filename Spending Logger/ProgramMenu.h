#ifndef PROGRAMMENU_H
#define PROGRAMMENU_H

// this file needs heavy refactoring

#include "Menu.h"
#include "MoneyTracker/AllTrackers.h"
#include <stdlib.h> // exit
#include <stdio.h> // lol
#include <string> // lol
#include <iostream> // cin
#include "../Headers/OutputControl.hpp" // clear, hold
#include "../Headers/FileManager/JsonFile.hpp" // hmm
#include "../Headers/FileManager/TextFile.hpp"
#include <iomanip>
#include <unistd.h>

using std::string;
using std::cin;
using std::setprecision;
using std::to_string;
using std::fixed;
using std::endl;

class ProgramMenu {
public:

    ProgramMenu() {
        this->moneyTrackers = new Menu();
        this->subMenu = new Menu();
        this->initProgram();
    
    }

    ~ProgramMenu() {
        delete this->moneyTrackers;
        delete this->subMenu;

    }

    void selectOption() {

        bool sthSelected = false;

        while(1) {

            // it's needed, because of listener business
            if(sthSelected) {
                this->moneyTrackers->selectOption();
            }

            switch( this->moneyTrackers->selectOption() ) {
            
            case 1:
                this->track1();
                sthSelected = true;
                break;

            case 2:
                this->track2();
                sthSelected = true;
                break;

            case 3:
                this->track3();
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
        printf("\ncreated @ well some date\n\n");
        printf("this program uses vim controls for menu scrolling!!\n");
        printf("'j' to move down\n'k' to move up\n");
        printf("Happy spending!!\n");
        OutputControl::hold();

    }

private:

    Menu *moneyTrackers;
    Menu *subMenu;
    NoIncrease *tracker1;
    MonthlyIncrease *tracker2;
    YearlyIncrease *tracker3;

    double ammountOfMoney;
    string sessionName;

    JsonFile *rawData; // not initialized in constructor, well you'll see later
    TextFile *finalData; // same here

private: // functions

    // initalize menu with proper options
    void initProgram() {
        this->moneyTrackers->addOption("Track With No Increase");
        this->moneyTrackers->addOption("Track With Monthly Increase");
        this->moneyTrackers->addOption("Track With Yearly Increase");
        this->moneyTrackers->addOption("Exit");

        this->subMenu->addOption("Put Money");
        this->subMenu->addOption("Draw Money");

    }

    // options, and now the smelly code begins
    /*
     * track1 = no increase
     * track2 = monthly
     * track3 = yearly 
     */
    
    void track1() {
        OutputControl::clear();

        printf("Enter session name: ");
        cin >> this->sessionName;
        // move to constructor or do something non idiot with it because when 
        // a new obect is created balance becomes 0 lol
        this->tracker1 = new NoIncrease(sessionName);
        
        double money;
        string reason;
        // it's needed, because of listener business
        this->subMenu->selectOption();

        switch( this->subMenu->selectOption() ) {

        case 1:
            printf("enter income reason: ");
            cin >> reason;
            printf("enter ammount of money added: ");
            cin >> money;
            tracker1->putMoney(money, reason);

            break;

        case 2:
            printf("enter outcome reason: ");
            cin >> reason;
            printf("enter ammount of money spent: ");
            cin >> money;
            tracker1->drawMoney(money, reason);

            break;

        }

        delete this->tracker1;

    }

    void track2() {
        OutputControl::clear();

        printf("Enter session name: ");
        cin >> this->sessionName;
        // move to constructor or do something non idiot with it because when 
        // a new obect is created balance becomes 0 lol
        this->tracker2 = new MonthlyIncrease(sessionName);
        
        double money;
        string reason;
        bool sthSelected = false;
        // it's needed, because of listener business
        this->subMenu->selectOption();

        switch( this->subMenu->selectOption() ) {

        case 1:
            printf("enter income reason: ");
            cin >> reason;
            printf("enter ammount of money added: ");
            cin >> money;
            tracker2->putMoney(money, reason);

            break;

        case 2:
            printf("enter outcome reason: ");
            cin >> reason;
            printf("enter ammount of money spent: ");
            cin >> money;
            tracker2->drawMoney(money, reason);

            break;

        }

        delete this->tracker2;
    }

    void track3() {
        OutputControl::clear();

        printf("Enter session name: ");
        cin >> this->sessionName;
        // move to constructor or do something non idiot with it because when 
        // a new obect is created balance becomes 0 lol
        this->tracker3 = new YearlyIncrease(sessionName);
        
        double money;
        string reason;
        // it's needed, because of listener business
        this->subMenu->selectOption();

        switch( this->subMenu->selectOption() ) {

        case 1:
            printf("enter income reason: ");
            cin >> reason;
            printf("enter ammount of money added: ");
            cin >> money;
            tracker3->putMoney(money, reason);

            break;

        case 2:
            printf("enter outcome reason: ");
            cin >> reason;
            printf("enter ammount of money spent: ");
            cin >> money;
            tracker3->drawMoney(money, reason);

            break;

        }

        delete this->tracker3;
    }



};

#endif //PROGRAMMENU_H