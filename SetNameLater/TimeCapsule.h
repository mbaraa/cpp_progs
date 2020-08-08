#ifndef TIMECAPSULE_H
#define TIMECAPSULE_H

#include <time.h>

class TimeCapsule {
public:
    // constructor sets time to current machine time
    TimeCapsule() {
        time(&this->rawtime);
    }

    // convert the raw time into a readable format and return it
    char *getCurrentTime() {
        return ctime(&this->rawtime);
    }
    // get raw time for time calculations
    time_t getRawTime() {
        return this->rawtime;
    }
    // set time to current machine time and returns time difference
    long long setTime() {
        time_t tmp = this->rawtime;
        time(&this->rawtime);
        return this->rawtime - tmp;
    }
    // 


private:
    time_t rawtime;

};

#endif //SETTIME_H