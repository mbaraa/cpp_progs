#ifndef TIMETRACKER_H
#define TIMETRACKER_H

#include "TimeCapsule.h"
#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;

class TimeTracker {
public:
    // constructor
    TimeTracker() {
        this->sessions = new std::map<std::string, TimeCapsule*>;
        this->sessionsNames = new std::vector<std::string>;
        // open file in appending mode
        logFile.open("log.txt", std::ios::app);
    }
    // destructor
    ~TimeTracker() {
        delete this->sessions;
        delete this->sessionsNames;
    }
    
    // add a session
    void addSession(std::string sessionName) {
        // update the map and the holding array
        (*this->sessions)[sessionName] = new TimeCapsule( sessionName );
        this->sessionsNames->push_back(sessionName);
        // add data to the file
        this->logFile << "Session " << sessionName << ":" << std::endl;
        this->logFile << "\tstarted at: " << (*this->sessions)[sessionName]->getInitialTime() << std::endl;
    }

    // end a session 
    void endSession(std::string sessionName) {
        // add data to the file
        this->logFile << "Session: " << sessionName << std::endl;
        this->logFile << "\tended at: " << (*this->sessions)[sessionName]->getCurrentTime() << std::endl;
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
            printf("started at %s\n", (*this->sessions)[session]->getInitialTime() );
            //std::cout << session << std::endl;
        }
        puts("");
    }

    // close log file
    void closeFile() {
        this->endSessions();
        this->logFile.close();
    }

private:
    void endSessions() {
        
        for(std::string session : *this->sessionsNames) {
            
            this->logFile << "Session: " << session << std::endl;
            this->logFile << "\tended at: " << (*this->sessions)[session]->getCurrentTime() << std::endl;
            /*
            
            
            printf("Session %s\n", session.c_str());
            printf("started at %s\n", (*this->sessions)[session]->getInitialTime() );
            //std::cout << session << std::endl;*/
        }

    }

private:
    // sessions' map
    std::map<std::string, TimeCapsule*> *sessions;
    // sessions' names
    std::vector<std::string> *sessionsNames;
    // file to store sessions' details in it
    ofstream logFile;

};

#endif //TIMETRACKER_H