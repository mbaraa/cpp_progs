#ifndef TIMETRACKER_H
#define TIMETRACKER_H

#include "TimeCapsule.h"
#include <map>

class TimeTracker {
public:

    TimeTracker() {
        sessions = new std::map<char*, TimeCapsule>;
    }

    ~TimeTracker() {
        delete sessions;
    }
    // add a session
    void addSession(char *sessionName) {
        (*this->sessions)[sessionName] = TimeCapsule();
    }
    // 
    long long getSessionTime(char *sessionName) {
        return (*this->sessions)[sessionName].getSpentTime();
    }

private:
    std::map<char *, TimeCapsule> *sessions;
    
};

#endif //TIMETRACKER_H