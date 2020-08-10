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

    }
    // destructor
    ~SessionManager() {

        delete this->sessions;
        delete this->sessionsNames;

    }

    // add a session
    void addSession(std::string sessionName) {

        // update the map
        if( (*this->sessions)[sessionName] == nullptr ) {

            (*this->sessions)[sessionName] = new Session( sessionName );

        }

        // add data to the file
        /*this->logFile << "Session " << sessionName << ":" << std::endl;
        this->logFile << "\tstarted at: " << (*this->sessions)[sessionName]->getStartTime() << std::endl;*/

    } // void addSession

    // end a session
    void endSession(std::string sessionName) {

        // add data to the file
        /*this->logFile << "Session: " << sessionName << std::endl;
        this->logFile << "\tended at: " << (*this->sessions)[sessionName]->getCurrentTime() << std::endl;
*/
        // reset session's time
        (*this->sessions)[sessionName]->resetStartTime();

    } // void endSession

    // get session's spent time
    std::string getSessionTime(std::string sessionName) {

        return (*this->sessions)[sessionName]->getSpentTime();

    } // long long getSessionTime


    void endSessions() {

        /*for(std::string session : *this->sessionsNames) {

            this->logFile << "Session: " << session << std::endl;
            this->logFile << "\tended at: " << (*this->sessions)[session]->getCurrentTime() << std::endl;

        }*/

    } // void endSessions

private:
    // sessions' map
    std::map<std::string, Session*> *sessions;
    // sessions' names
    std::vector<std::string> *sessionsNames;
    // file to store sessions' details in it
    std::vector<FileManager*> logFiles;

}; // class TimeTracker

#endif //TIMETRACKER_H
