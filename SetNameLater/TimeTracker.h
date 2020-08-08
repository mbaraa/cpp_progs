#ifndef TIMETRACKER_H
#define TIMETRACKER_H

#include "TimeCapsule.h"
#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <string>

class TimeTracker {
public:
    // constructor
    TimeTracker() {
        this->sessions = new std::map<std::string, TimeCapsule*>;
        this->sessionsNames = new std::vector<std::string>;
    }
    // destructor
    ~TimeTracker() {
        delete this->sessions;
        delete this->sessionsNames;
    }
    
    // add a session
    void addSession(std::string sessionName) {
        (*this->sessions)[sessionName] = new TimeCapsule( sessionName );
        this->sessionsNames->push_back(sessionName);
    }

    // get session's spent time
    long long getSessionTime(std::string sessionName) {
        return (*this->sessions)[sessionName]->getSpentTime();
    }

    // list saved sessions with their start time
    void listSessions() {
        puts("Available sessions:\n");
        for(std::string session : *this->sessionsNames) {
            printf("Session %s\n", session.c_str());
            printf("started at %s", (*this->sessions)[session]->getInitialTime() );
            //std::cout << session << std::endl;
        }
        puts("");
    }

private:
    std::map<std::string, TimeCapsule*> *sessions;
    std::vector<std::string> *sessionsNames;    
};

#endif //TIMETRACKER_H