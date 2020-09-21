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
#include <map> // lol
#include <nlohmann/json.hpp> // github.com/nlohmann/json
#include "../OutputControl.h"
#include <math.h> // ceil
#include "../../Headers/FileManager/JsonFile.hpp"
#include "../../Headers/FileManager/TextFile.hpp"

using nlohmann::json;
using std::string;
using std::map;

class MoneyTracker {
public:

    MoneyTracker(string spenderName) {
        // 
        this->combinedData = json();
        this->permanentCombinedData = new 
            JsonFile(&this->combinedData, spenderName);
        this->finalData = new TextFile(spenderName + ".csv");
        
        // resetting files ha ha ha
        //this->finalData->del();
        if( this->permanentCombinedData->load() == 1 ) {
          //  this->permanentCombinedData->del();
            printf("ENTER BALANCE: ");
            scanf("%lf", &this->balance);
        }
        //
        this->spendingLog = new map<string, double>;
        this->spendingDates = new map<string, time_t>;
        time(&this->rawTime);        

        //if(this->permanentCombinedData->load() == 0) {
            this->combinedData[this->spentMoney] = 0;
            this->combinedData[this->spenderName] = spenderName;
            // 
          //  this->initCSVfile();
            this->initJSONfile();

//            this->permanentCombinedData->append();
        //}
    }

    ~MoneyTracker() {
        delete this->spendingLog;
        delete this->spendingDates;
        delete &this->combinedData;
        delete this->permanentCombinedData;
        delete this->finalData;
    }

    virtual double getOriginalMoneyAmmount() = 0;

    virtual double getRemaining() = 0;

    virtual double getSafeRemaining() = 0;

    virtual void listData() = 0;

    //virtual void runInitSetup() = 0;

    void setBalance(double balance) {
        this->combinedData[this->balance] = balance;

    }

    virtual void putMoney(double money, string reason) = 0;

    virtual void drawMoney(double money, string reason) = 0;


protected:

//    double ammountOfMoney;
//    double spentMoney;

    //  reason, ammount spent
    map<string, double> *spendingLog;
    //  reason, time spent
    map<string, time_t> *spendingDates;
    
//    string spenderName;
    double startingBalance;
   // double spntMoney;

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


protected:

    int checkJSON() {

        // 1 is an error code
        return (this->permanentCombinedData->load() == 1 );
    }

    void syncJSON() {
        
        this->permanentCombinedData->append();
    }

    void initCSVfile() {
        if(this->permanentCombinedData->load() == 1) {
            return;
        }
        this->finalData->append("Name," + 
            (string)this->combinedData[this->spenderName] );
        
        this->finalData->append("Starting Balance," + 
            to_string(this->getOriginalMoneyAmmount()) + "\n");
        
        this->finalData->append("Date, Item, Price, New Balance, Safe Remaining\n");

        // this->finalData->close();

      //  this->finalData = new TextFile((string)this->combinedData[spenderName] + "csv");
    }
    
    void initJSONfile() {
        // memory update: weird shits moved to constructor
        this->combinedData["starting date"] = this->juiceDateOutMMDDYYYY();
        this->combinedData["balance"] = 123;//this->getOriginalMoneyAmmount();
        this->combinedData["name"] = this->combinedData[this->spenderName];
        
        // storage update
        this->permanentCombinedData->append();
        // the stupid fucking shit json file has to be closed to write the data :)
        //this->permanentCombinedData->close();

//        this->permanentCombinedData =  new JsonFile(&this->combinedData, this->combinedData[spenderName]);
    }

    /*void moveJSONdataToCSV() {
        this->permanentCombinedData = new JsonFile(
            &this->combinedData,
            this->combinedData[this->spenderName]);

        for(auto e: this->combinedData[dates]) {


            
        }

        // the stupid fucking shit json file has to be closed to write the data :)
        delete this->permanentCombinedData;

    }
*/
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

private: 

    time_t rawTime; // needed to juice out DDMMYYYY


};

#endif // MONEYTRACKER_MONEYTRACKER_H
