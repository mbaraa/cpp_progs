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
#include "../OutputControl.h"
#include <math.h> // ceil
#include "../../Headers/FileManager/JsonFile.hpp"
#include "../../Headers/FileManager/TextFile.hpp"

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

    // slave consts "DING"*8
    const string startingDate = "startingDate";
    const string price = "price";
    const string newBalance = "newBalance";
    const string spenderName = "spenderName";
    const string balance = "balance";
    const string spentMoney = "spentMoney";
    const string dates = "dates";
    const string date = "date";


protected: // functions

    virtual void initCSVfile() = 0;
    
    virtual void initJSONfile() = 0;

    virtual double getRemaining() = 0;

    virtual double getSafeRemaining() = 0;

    virtual void updateCSVfile(double, string) = 0;
    
    virtual void updateJSONs(double, string) = 0;

    string juiceDateOutMMDDYYYY() {
        int years = this->rawTime / 31536000;
	    int months = (this->rawTime / 2629800 ) - years*12;
	    double days = (this->rawTime / 86400) - years*365.25 - months*30.5;

	    years += 1970;
	    months += 1;
	    days = ceil(days) + 1;


        return std::to_string(months) 
            + "/"+ std::to_string((int)days) 
            +"/"+ std::to_string(years);
    }

    // useless for now, will be removed if still useless
    virtual void moveJSONdataToCSV() = 0;

private: 

    time_t rawTime; // needed to juice out DDMMYYYY


};

#endif // MONEYTRACKER_MONEYTRACKER_H
