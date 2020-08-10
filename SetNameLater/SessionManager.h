#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include "Session.h"
#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include "FileManager.h"

class SessionManager {
public:
    // constructor
    SessionManager() {

        this->sessions = new std::map<std::string, Session*>;
        this->sessionsNames = new std::vector<std::string>;
    
    }
    // destructor
    ~SessionManager() {
    
        delete this->sessions;
        delete this->sessionsNames;
    
    }
    
    // add a session
    void addSession(std::string sessionName) {

        // update the map and the holding array
        (*this->sessions)[sessionName] = new Session( sessionName );
        this->sessionsNames->push_back(sessionName);
        // add data to the file
        this->logFile << "Session " << sessionName << ":" << std::endl;
        this->logFile << "\tstarted at: " << (*this->sessions)[sessionName]->getStartTime() << std::endl;

    } // void addSession

    // end a session 
    void endSession(std::string sessionName) {

        // add data to the file
        this->logFile << "Session: " << sessionName << std::endl;
        this->logFile << "\tended at: " << (*this->sessions)[sessionName]->getCurrentTime() << std::endl;

        // reset session's time
        (*this->sessions)[sessionName]->resetStartTime();

    } // void endSession

    // get session's spent time
    long long getSessionTime(std::string sessionName) {

        return (*this->sessions)[sessionName]->getSpentTime();

    } // long long getSessionTime

    // list saved sessions with their start time
    void listSessions() {

        puts("Available sessions:\n");
        for(std::string session : *this->sessionsNames) {

            printf("Session %s\n", session.c_str());
            printf("started at %s\n", (*this->sessions)[session]->getStartTime() );;
            
        } // for
        puts("");

    } // void ListSessions

    // close log file
    void closeFile() {

        this->endSessions();
        this->logFile.close();

    } // void closeFile

private:
    void endSessions() {
        
        for(std::string session : *this->sessionsNames) {

            this->logFile << "Session: " << session << std::endl;
            this->logFile << "\tended at: " << (*this->sessions)[session]->getCurrentTime() << std::endl;

        }

    } // void endSessions

private:
    // sessions' map
    std::map<std::string, Session*> *sessions;
    // sessions' names
    std::vector<std::string> *sessionsNames;
    // file to store sessions' details in it
    FileManager logFile;

}; // class TimeTracker

#endif //TIMETRACKER_H