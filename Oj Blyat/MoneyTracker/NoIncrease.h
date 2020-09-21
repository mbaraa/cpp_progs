#ifndef MONEYTRACKER_NOINCREASE_H
#define MONEYTRACKER_NOINCREASE_H

#include "MoneyTracker.h"
#include <iostream> // cin


using std::cin;

class NoIncrease: public MoneyTracker {
public:

    NoIncrease(string spenderName):
        MoneyTracker(spenderName) {

    }

    ~NoIncrease() {
        

    }

    double getOriginalMoneyAmmount() {

        // casting required for the "+" operator
        return (double)this->combinedData[this->balance] + 
            (double)this->combinedData[this->spentMoney];
    }

    double getRemaining() {

        return this->combinedData[this->balance];
    }

    double getSafeRemaining() {

        // 20% is a pretty good ammount of money
        return (80 * (int)this->combinedData[this->balance]) / 100; 
    }

    void putMoney(double money, string reason) {
        this->startingBalance += money;
        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->price] = money;

        this->permanentCombinedData->append();

    }

    void drawMoney(double money, string reason) {
        this->startingBalance -= money;
        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->price] = -1*money; 

        this->permanentCombinedData->append();

    }
    

    // 
    void listData() {
   /*     printf("Starting Date: %s\n", 
                    ctime(&this->startingDate));
        printf("Starting Ammount of Money: %lf\n",
                    this->getOriginalMoneyAmmount());
        printf("Remaining Money: %lf\n",
                    this->getRemaining());
        printf("Safe Remaining Money: %lf\n", 
                    this->getSafeRemaining());

        OutputControl::hold();
*/    
    }
/*

    // should have been done in the constructor but....
    void runInitSetup() {
        
        printf("enter session name: ");
        cin >> this->spenderName;

        printf("enter starting balance: ");
        cin >> this->ammountOfMoney;

        time(&this->startingDate);

    
        //this->updateJSON();

    }*/

    NoIncrease setCombinedData(json combinedData) {
        this->combinedData = combinedData;
        
        return *this;
    }

    json *getCombinedData() {
        
        return &this->combinedData;
    }



};

#endif // MONEYTRACKER_NOINCREASE_H
