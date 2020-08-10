#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include "Session.h"
#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include "FileManager.h"
#include "OutputControl.h"

class SessionManager {
public:
    // constructor
    SessionManager() {

        this->sessions = new std::map<std::string, Session*>;
        this->logFiles = new std::map<std::string, FileManager*>;

    }
    // destructor
    ~SessionManager() {

        delete this->sessions;
        delete this->logFiles;

    }

    // add a session
    void addSession(std::string sessionName) {

        // update the map
        if( (*this->sessions)[sessionName] ) {
            puts(RED);
            puts("session exists\n");
            puts(RESET);
            
            return;
        }

        // update maps
        (*this->sessions)[sessionName] = new Session( sessionName );
        // add data to the file
        (*this->logFiles)[sessionName] = new FileManager( sessionName + ".csv" );
        
        (*this->logFiles)[sessionName]->append( 
                sessionName 
                + ", started at: " 
                + (*this->sessions)[sessionName]->getStartTime() );

    } // void addSession

    // end a session
    void endSession(std::string sessionName) {

        if( !(*this->sessions)[sessionName] ) {

            puts(RED);
            puts("session doesn't exists\n");
            puts(RESET);
            
            return;
        }

        // add data to the file
        (*this->logFiles)[sessionName]->append( 
                sessionName 
                + ", ended at: " 
                + (*this->sessions)[sessionName]->getFinalTime() );

        // delete associated objects:
        (*this->sessions)[sessionName] = nullptr;
        (*this->logFiles)[sessionName] = nullptr;


    } // void endSession

    // get session's spent time
    std::string getSessionTime(std::string sessionName) {

        return  ( !(*this->sessions)[sessionName]? "\033[31mSESSION DOESN'T EXIST!!": // check if session exists or not
            (*this->sessions)[sessionName]->getSpentTime() );

    } // long long getSessionTime


private:
    // sessions' map
    std::map<std::string, Session*> *sessions;
    // file to store sessions' details in it
    std::map<std::string, FileManager*> *logFiles;


}; // class TimeTracker

#endif //TIMETRACKER_H
