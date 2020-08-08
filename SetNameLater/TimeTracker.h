#ifndef TIMETRACKER_H
#define TIMETRACKER_H

#include "TimeCapsule.h"
#include <map>

class TimeTracker {
public:

    TimeTracker() {
        sessions = new std::map<char*, TimeCapsule*>;
    }

    ~TimeTracker() {
        delete sessions;
    }
    // add a session
    void addSession(char sessionName[99]) {
        (*this->sessions)[sessionName] = new TimeCapsule();
    }
    // get session's spent time
    long long getSessionTime(char sessionName[99]) {
        return (*this->sessions)[sessionName]->getSpentTime();
    }

private:
    std::map<char *, TimeCapsule*> *sessions;
    
};

#endif //TIMETRACKER_H