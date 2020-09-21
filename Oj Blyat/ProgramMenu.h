#ifndef PROGRAMMENU_H
#define PROGRAMMENU_H

// this file needs heavy refactoring

#include "Menu.h"
#include "MoneyTracker/AllTrackers.h"
#include <stdlib.h> // exit
#include <stdio.h> // lol
#include <string> // lol
#include <iostream> // cin
#include "OutputControl.h" // clear, hold
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
        this->initProgram();
    
    }

    ~ProgramMenu() {
        delete this->moneyTrackers;
        delete this->tracker1;

    }

    void selectOption() {
 
        while(1) {
  
            switch( this->moneyTrackers->selectOption() ) {
            
            case 1:
                this->track1();
                break;

            case 2:
                this->track2();
                break;

            case 3:
                this->track3();
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
        printf("\n\nMoney tracker or something\n\n");
        OutputControl::hold();

    }

private:

    Menu *moneyTrackers;
    NoIncrease *tracker1;
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
    }

    void cleanTempVars() {
        this->sessionName = "";
        this->ammountOfMoney = 0;
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
        
        this->tracker1 = new NoIncrease(sessionName);

        Menu subMenu1;
        subMenu1.addOption("put money");
        subMenu1.addOption("draw money");

        double money;
        string reason;
    
        switch( subMenu1.selectOption() ){

        case 1:
            printf("enter income reason: ");
            cin >> reason;
            printf("enter ammount of money added: ");
            cin >> money;
            tracker1->putMoney(money, reason);

            break;

        case 2:
            printf("enter income reason: ");
            cin >> reason;
            printf("enter ammount of money added: ");
            cin >> money;
            cin >> reason >> money;
            tracker1->drawMoney(money, reason);

            break;

        }

        /*// the later from private vars :)
        this->rawData = new JsonFile(&tracker1->combinedData, this->sessionName);
        
        if( this->rawData->load() == 1) { // 1 is an error code
            tracker1->runInitSetup();
            this->rawData->append();

        //    return;
        }
        delete this->rawData;
        this->initCSVfile(sessionName, tracker1->getOriginalMoneyAmmount());
        //this->tracker1->listData();
*/
        this->cleanTempVars();

        //delete this->tracker1;

    }

    void track2() {

    }

    void track3() {

    }



};

#endif //PROGRAMMENU_H