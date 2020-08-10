#ifndef SESSION_H
#define SESSION_H

#include <time.h>
#include <string>
#include "TimeFormatter.h"

class Session {
public:
    // constructor sets time to current machine time
    Session(std::string sessionName) {

        time(&this->startRawTime);
        this->sessionName = sessionName;
        this->humanReadableFormat = new TimeFormatter(0); // Spent Time is 0

    }

    ~Session() {
        delete this->humanReadableFormat;
    }

    // convert the raw time into a readable format and return it
    char *getCurrentTime() {

        time(&this->finalRawTime);
        return ctime(&this->finalRawTime);

    } // char *getCurrentTime

    // get initial time in a realable form
    char *getStartTime() {

        return ctime(&this->startRawTime);

    } // char *getInitialTime

    // get raw time for time calculations
    time_t getRawTime() {

        return this->finalRawTime;

    } // time_t getRawTime

    // reset initial time
    void resetStartTime() {

        time(&this->startRawTime);

    } // void setInitialTime

    // return spent time since the initial time
    std::string getSpentTime() {

        TimeFormatter spentTime(time(&this->finalRawTime) - this->startRawTime);

        return spentTime.getTime();

    } // time_t getSpentTime

/*    // set & get session's name
    void setSessionName(std::string sessionName) {

        this->sessionName = sessionName;

    } // void setSessionName
*/
    std::string getSessionName() {

        return this->sessionName;

    } // std::string getSessionName


private:
    std::string sessionName;
    time_t finalRawTime;
    time_t startRawTime;
    TimeFormatter *humanReadableFormat;

}; // class Session

#endif // SESSION_H
