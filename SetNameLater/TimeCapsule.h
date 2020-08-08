#ifndef TIMECAPSULE_H
#define TIMECAPSULE_H

#include <time.h>
#include <string>
class TimeCapsule {
public:
    // constructor sets time to current machine time
    TimeCapsule(std::string sessionName) {

        time(&this->currentRawTime);
        time(&this->initialRawTime);
        this->sessionName = sessionName;
    
    }

    // convert the raw time into a readable format and return it
    char *getCurrentTime() {
    
        return ctime(&this->currentRawTime);
    
    } // char *getCurrentTime

    // get initial time in a realable form
    char *getInitialTime() {

        return ctime(&this->initialRawTime);

    } // char *getInitialTime

    // get raw time for time calculations
    time_t getRawTime() {
    
        return this->currentRawTime;
    
    } // time_t getRawTime

    // set time to current machine time
    void updateCurrentTime() {
    
        time(&this->currentRawTime);
    
    } // void updateCurrentTime
    
    // reset initial time
    void setInitialTime() {
    
        time(&this->initialRawTime);
    
    } // void setInitialTime

    // return spent time since the initial time
    time_t getSpentTime() {
    
        updateCurrentTime();
        this->spentRawTime = this->currentRawTime - this->initialRawTime;
        return this->spentRawTime;

    } // time_t getSpentTime

    // set & get session's name
    void setSessionName(std::string sessionName) {
 
        this->sessionName = sessionName;
 
    } // void setSessionName
 
    std::string getSessionName() {
 
        return this->sessionName;
 
    } // std::string getSessionName


private:
    std::string sessionName;
    time_t currentRawTime;
    time_t initialRawTime;
    time_t spentRawTime;
};

#endif //SETTIME_H