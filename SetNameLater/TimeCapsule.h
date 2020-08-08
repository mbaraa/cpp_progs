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
    }
    // get initial time in a realable form
    char *getInitialTime() {
        return ctime(&this->initialRawTime);
    }
    // get raw time for time calculations
    time_t getRawTime() {
        return this->currentRawTime;
    }
    // set time to current machine time
    void updateCurrentTime() {
        time(&this->currentRawTime);
    }

    // return spent time since the initial time
    long long getSpentTime() {
        updateCurrentTime();
        this->spentRawTime = this->currentRawTime - this->initialRawTime;
        return this->spentRawTime;
    }

/*    // set & get session's name
    void setSessionName(char sessionName[99]) {
        this->sessionName = sessionName;
    }
    char *getSessionName() {
        return this->sessionName;
    }
*/

private:
    std::string sessionName;
    time_t currentRawTime;
    time_t initialRawTime;
    time_t spentRawTime;
};

#endif //SETTIME_H