#ifndef MONEYTRACKER_MONEYTRACKER_H
#define MONEYTRACKER_MONEYTRACKER_H

// code sins: 70
/*
 * +1: runInitSetup()
 * +19: god class
 * +2: weird looking constructor
 * +8: slave constants
 * +36: using json as variables container, well it could be good :)
 * +4: constructor is getting weirder
 */

#include <stdio.h> // lol
#include <time.h> // time, ctime, time_t
#include <string> // lol
#include <nlohmann/json.hpp> // github.com/nlohmann/json
#include "../../Headers/OutputControl.hpp"
#include <math.h> // ceil
#include "../../Headers/FileManager/JsonFile.hpp"
#include "../../Headers/FileManager/TextFile.hpp"
#include "../../Headers/TimeFormatter.hpp"

using nlohmann::json;
using std::string;

class MoneyTracker {
public:

    MoneyTracker(string spenderName) {
        // 
        this->combinedData = json();
        this->permanentCombinedData = new 
            JsonFile(&this->combinedData, spenderName);
        this->finalData = new TextFile(spenderName + ".csv");
        this->timeCap = new TimeFormatter(0);

        this->combinedData[this->spenderName] = spenderName;

        time(&this->rawTime);


    }

    ~MoneyTracker() {
        //delete &this->combinedData;
        delete this->permanentCombinedData;
        delete this->finalData;
    
    }

    virtual void listData() = 0;

    virtual void putMoney(double money, string reason) = 0;

    virtual void drawMoney(double money, string reason) = 0;


protected:
    
    json combinedData; // not a pointer for iterating issues :)
    JsonFile *permanentCombinedData;
    TextFile *finalData;
    TimeFormatter *timeCap;

    // slave consts "DING"*8
    const string startingDate = "startingDate";
    const string price = "price";
    const string newBalance = "newBalance";
    const string spenderName = "spenderName";
    const string balance = "balance";
    const string spentMoney = "spentMoney";
    const string dates = "dates";
    const string trackerType = "type";


protected: // functions

    virtual void initCSVfile() = 0;
    
    virtual void initJSONfile() = 0;

    double getRemaining() {

        return this->combinedData[this->balance];
    }

    double getSafeRemaining() {

        // 20% is a pretty good ammount of money
        return (80 * (double)this->combinedData[this->balance]) / 100; 
    }

    virtual void updateCSVfile(double money, string reason) = 0;
    
    virtual void updateJSONs(double money, string reason) {
        // memory update:

        // money update
        this->combinedData[this->spentMoney] = 
            ( (double)this->combinedData[this->spentMoney] -
            (money <= 0? money: 0 ) );
        
        // outcome reason
        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->price] = money; 
        
        
        // storage update:
        this->permanentCombinedData->append();

    }

    string juiceDateOutMMDDYYYY() {
        
        return this->timeCap->getDateMMDDYYYY();
    }

    // useless for now, will be removed if still useless
    virtual void moveJSONdataToCSV() = 0;

private: 

    time_t rawTime; // needed to juice out DDMMYYYY


};

#endif // MONEYTRACKER_MONEYTRACKER_H
