#ifndef TIMECAPSULE_H
#define TIMECAPSULE_H

#include <time.h>

class TimeCapsule {
public:
    // constructor sets time to current machine time
    TimeCapsule() {
        time(&this->currentRawTime);
        time(&this->initialRawTime);
    }

    // convert the raw time into a readable format and return it
    char *getCurrentTime() {
        return ctime(&this->currentRawTime);
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
    // 


private:
    time_t currentRawTime;
    time_t initialRawTime;
    time_t spentRawTime;
};

#endif //SETTIME_H