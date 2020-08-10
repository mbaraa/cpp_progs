#ifndef TIMEFORMATTER_H
#define TIMEFORMATTER_H

#include <string>
using std::to_string;
#include <time.h>

class TimeFormatter {
public:
    // constructor
    TimeFormatter(time_t noOfSeconds) {
        this->days = 0;
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
        this->formatTime(noOfSeconds);
    } // TimeFormat

    // get formated time
    std::string getTime() {
        return (this->days > 0? to_string(this->days) + " Days\n": "")
            + (this->hours < 10? "0": "" )
            + to_string(this->hours) // add hours to string format with < 10 checker
            + ":" // hours:minutes seperator
            + (this->minutes < 10? "0": "" )
            + to_string(this->minutes) // add minutes to string format with < 10 checker
            + ":" // minutes:seconds seperator
            + (this->seconds < 10? "0": "" )
            + to_string(this->seconds); // add seconds to string format with < 10 checker

    } // std::string getTime

    void formatTime(time_t secs) {

        for(int k = 0 ;k < secs; k++) {
            tick();
        } // for

    } // void formatTime

private:
    time_t days;
    time_t hours;
    time_t minutes;
    time_t seconds;

private:

    // increase total time 1 second
    void tick() {

        this->seconds++;
        if(this->seconds >= 60) {
            this->seconds = 0;
            this->minutes++;

            if(this->minutes >= 60) {
                this->minutes = 0;
                this->hours++;


                if(this->hours >= 24) {
                    this->hours = 0;
                    this->days++;
                
                } // if3
            
            } // if2
        
        } // if1

    } // void tick

}; // class TimeFormatter

#endif //  TIMEFORMATTER_H
