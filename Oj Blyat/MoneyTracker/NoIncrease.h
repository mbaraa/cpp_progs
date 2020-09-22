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
            scanf("%lf", &this->fuckingBalance);
            // 
            this->initJSONfile();

        
        
            this->initCSVfile();
        }
        
        //  if file exists
        //if( this->permanentCombinedData->load() == 0 ) {
            this->syncJSON();

//        }


    }

    ~NoIncrease() {
        

    }

    double getOriginalMoneyAmmount() {

        // casting required for the "+" operator
        return this->fuckingBalance + 
            (double)this->combinedData[this->spentMoney];
    }

    double getRemaining() {

        return this->combinedData[this->balance];
    }

    double getSafeRemaining() {

        // 20% is a pretty good ammount of money
        return (80 * this->fuckingBalance) / 100; 
    }

    void putMoney(double money, string reason) {
        this->fuckingBalance += money;
        this->combinedData[this->balance] = this->fuckingBalance;

        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->price] = money;

        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->newBalance] = this->fuckingBalance;
        
        this->finalData->append( this->juiceDateOutMMDDYYYY() + ", " // Date
            + reason + ", " // Item
            + to_string(money) + ", " // Price
            + to_string(this->fuckingBalance) + ", " // New Balance
            + to_string(this->getSafeRemaining()) + ", " // Safe Remaining

        );
        this->permanentCombinedData->append();

    }

    void drawMoney(double money, string reason) {
        this->fuckingBalance -= money;
        this->combinedData[this->balance] = this->fuckingBalance;

        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->price] = money; 
        this->combinedData[this->juiceDateOutMMDDYYYY()]
            [reason][this->newBalance] = this->fuckingBalance;

        this->finalData->append( this->juiceDateOutMMDDYYYY() + ", " // Date
            + reason + ", " // Item
            + to_string(money) + ", " // Price
            + to_string(this->fuckingBalance) + ", " // New Balance
            + to_string(this->getSafeRemaining()) + ", " // Safe Remaining

        );

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
    
private: // functions


    void syncJSON() {

        this->fuckingBalance = this->combinedData[this->balance];

    }

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
        /*if(this->permanentCombinedData->load() == 1) {
            return;
        }*/
        this->finalData->append("Name," + 
            (string)this->combinedData[this->spenderName] );
        
        this->finalData->append("Starting Balance," + 
            to_string(this->fuckingBalance) + "\n");
        
        this->finalData->append("Date, Item, Price, New Balance, Safe Remaining\n");

        // this->finalData->close();

      //  this->finalData = new TextFile((string)this->combinedData[spenderName] + "csv");
    }
    
    void initJSONfile() {
        // memory update: weird shits moved to constructor
        this->combinedData[this->startingDate] = this->juiceDateOutMMDDYYYY();
        this->combinedData[this->balance] = this->fuckingBalance;//->getOriginalMoneyAmmount();
        
        // storage update
        this->permanentCombinedData->append();
        // the stupid fucking shit json file has to be closed to write the data :)
        //this->permanentCombinedData->close();

//        this->permanentCombinedData =  new JsonFile(&this->combinedData, this->combinedData[spenderName]);
    }




};

#endif // MONEYTRACKER_NOINCREASE_H
