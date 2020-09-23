#ifndef MONEYTRACKER_NOINCREASE_H
#define MONEYTRACKER_NOINCREASE_H

#include "MoneyTracker.h"
#include <iostream> // cin

/* 
 * code sins: 1
 * +1: the first time initializer in the constructor
 */

using std::cin;
using std::to_string;
class NoIncrease: public MoneyTracker {
public:

    NoIncrease(string spenderName):
        MoneyTracker(spenderName) {
        
        this->combinedData[this->spentMoney] = 0;
        this->combinedData[this->spenderName] = spenderName;

        // let's call it first time initalizer
        if( this->permanentCombinedData->load() == 1 ) {
            printf("ENTER BALANCE: ");
            cin >> this->combinedData[this->balance];
            // 
            this->initJSONfile();
            this->initCSVfile();

        }
        

    }

    ~NoIncrease() {
        

    }


    double getRemaining() {

        return this->combinedData[this->balance];
    }

    double getSafeRemaining() {

        // 20% is a pretty good ammount of money
        return (80 * (double)this->combinedData[this->balance]) / 100; 
    }

    void putMoney(double money, string reason) {
        this->updateJSONs(money, reason);
        this->updateCSVfile(money, reason);

    }

    void drawMoney(double money, string reason) {
        this->updateJSONs(-1*money, reason);
        this->updateCSVfile(-1*money, reason);

    }
    

    // 
    void listData() {
        // looooooooooooool
    }

    
private: // functions

    // useless for now, will be removed if still useless
    void moveJSONdataToCSV() {
        this->permanentCombinedData = new JsonFile(
            &this->combinedData,
            this->combinedData[this->spenderName]);

        for(auto e: this->combinedData[dates]) {


            
        }

        // the stupid fucking shit json file has to be closed to write the data :)
        delete this->permanentCombinedData;

    }

    void initCSVfile() {
        this->finalData->append("Date,Item,Balance Change,New Balance,Safe Remaining,Total Spendings");

    }
    
    void initJSONfile() {
        // memory update: weird shits moved to constructor
        this->combinedData[this->startingDate] = this->juiceDateOutMMDDYYYY();
        
        // storage update
        this->permanentCombinedData->append();

    }

    void updateJSONs(double money, string reason) {
        // memory update:

        // money update
        this->combinedData[this->spentMoney] = 
            ( (double)this->combinedData[this->spentMoney] -
            (money <= 0? money: 0 ) );
        this->combinedData[this->balance] = 
            ( this->getRemaining() + money );
        // outcome reason
        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->price] = money; 
        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->newBalance] = this->getRemaining();
        
        // storage update:
        this->permanentCombinedData->append();

    }

    void updateCSVfile(double money, string reason) {
        this->finalData->append( this->juiceDateOutMMDDYYYY() + "," // Date
            + reason + "," // Item
            + to_string(money) + "," // Price
            + to_string(this->getRemaining() ) + "," // New Balance
            + (this->getSafeRemaining() > 0? to_string(this->getSafeRemaining()): to_string(0)) + "," // Safe Remaining
            + to_string(this->combinedData[this->spentMoney]) // total spendings
        );

    }


};

#endif // MONEYTRACKER_NOINCREASE_H
