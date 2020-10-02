#ifndef MONEYTRACKER_YEARLYINCREASE_H
#define MONEYTRACKER_YEARLYINCREASE_H

#include "MoneyTracker.h"

class YearlyIncrease: public MoneyTracker {
public:

    YearlyIncrease(string spenderName): 
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

            this->startYear = this->timeCap->getYear();

        }

    }

    ~YearlyIncrease() {}

    int getYears() {

        return this->startYear - this->timeCap->getYear();
    }

    void putMoney(double money, string reason) {
        this->combinedData[this->balance] = (
            (double)this->combinedData[this->balance] 
            + this->getYears() * this->growth
        );
        this->updateJSONs(money, reason);
        this->updateCSVfile(money, reason);

    }

    void drawMoney(double money, string reason) {
        this->updateJSONs(-1*money, reason);
        this->updateCSVfile(-1*money, reason);

    }


private:

    double growth;
    int startYear;
    const string thisType = "yearly";

    
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
        // money update
        this->combinedData[this->spentMoney] = 
            ( (double)this->combinedData[this->spentMoney] -
            (money <= 0? money: 0 ) );
        
        // outcome reason
        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->price] = money; 

        this->combinedData[this->balance] = 
            ( (double)this->combinedData[this->balance] + money );
        
        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->newBalance] = this->combinedData[this->balance];

        // storage update:
        this->permanentCombinedData->append();

    }

    // I tried to generalize it but nothing :(
    void updateCSVfile(double money, string reason) {
        this->finalData->append( this->juiceDateOutMMDDYYYY() + "," // Date
            + reason + "," // Item
            + to_string(money) + "," // Price
            + to_string(this->combinedData[this->balance] ) + "," // New Balance
            + (this->getSafeRemaining() > 0? to_string(this->getSafeRemaining()): to_string(0)) + "," // Safe Remaining
            + to_string(this->combinedData[this->spentMoney]) // total spendings
        );

    }


};


#endif // MONEYTRACKER_YEARLYNCREASE_H