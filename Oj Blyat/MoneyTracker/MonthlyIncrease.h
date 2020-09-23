#ifndef MONEYTRACKER_MONTHLYNCREASE_H
#define MONEYTRACKER_MONTHLYNCREASE_H

#include "MoneyTracker.h"

class MonthlyIncrease: public MoneyTracker {
public:

    MonthlyIncrease(string spenderName): 
        MoneyTracker(spenderName) {

        // let's call it first time initalizer
        if( this->permanentCombinedData->load() == 1 ) {
            printf("ENTER BALANCE: ");
            cin >> this->combinedData[this->balance];
            this->combinedData[this->spentMoney] = 0;
            printf("ENTER GROWTH: ");
            cin >>  this->growth;
            // 
            this->initJSONfile();
            this->initCSVfile();

        }

    }

    ~MonthlyIncrease() {}

    int getMonths() {

    }

    void putMoney(double money, string reason) {
        /*this->combinedData[this->balance] = (
            this->getRemaining() + this->getMonths() * this->growth;
        );*/
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


private:

    double growth;

    const string thisType = "monthly";

    
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
        //this->combinedData[this->trackerType] = this->thisType;
        // storage update
        this->permanentCombinedData->append();

    }

    void updateJSONs(double money, string reason) {
        MoneyTracker::updateJSONs(money, reason);

        this->combinedData[this->balance] = 
            ( this->getRemaining() + money );
        
        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->newBalance] = this->getRemaining();

    }

    // I tried to generalize it but nothing :(
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

#endif // MONEYTRACKER_MONTHLYNCREASE_H