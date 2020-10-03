#ifndef MENU_H
#define MENU_H

#include <vector> // for options list
#include <string> // lol
#include <stdio.h> // printf
#include "Option.h" // a menu consists of options
#include "../Headers/kbInput.h" // getch
#include "../Headers/OutputControl.hpp" // clear

using std::vector; // for typo
using std::string; // typo
using std::to_string; // typo typo typo

class Menu {
public:
    Menu() {
        this->options = new vector<Option*>;
        this->optionIndex = 1;
        this->noOfOptions = 0;
        this->setIsVisited(false);

    }

    ~Menu() {
        delete this->options;
    }

    void addOption(string optionName) {

        this->options->push_back( new Option( 
            to_string(this->optionIndex) + ") " + optionName)
        );
            
        this->optionIndex++;
        this->noOfOptions++;

    }

    int selectOption() {

        OutputControl::clear();
        this->setIsVisited(true);
        // default option is the first one
        int nCurrentOption = 1;
        // to hold the pressed key
    	char cKeyStrokeVal;
        // oj blyat classic menu
    	while(true) {
            // hmm
    		this->listOptions(nCurrentOption);

            // blyaaaaaaat
    		cKeyStrokeVal = getch();

            // key handeling:
            /* 
             * (j) to move down, vim keys
             * (k) to move up, vim keys
             * (return'\n') for selecting
             */

    		if( cKeyStrokeVal == '\n' ) {
                return nCurrentOption;

            } 
            
            nCurrentOption = cKeyStrokeVal == 'j'? nCurrentOption + 1:
                (cKeyStrokeVal == 'k'? nCurrentOption - 1: nCurrentOption );

            // menu boundries
            /*
             * expected a comment didn't ya :)
             *
             */
            nCurrentOption = nCurrentOption > this->noOfOptions? 1:
                ( nCurrentOption < 1? this->noOfOptions: nCurrentOption);

    		OutputControl::clear();
		
        }        

        // exit code
        return 0;

    } // int chooseOption()

    Menu *setIsVisited(bool isVisited) {
        this->isVisited = isVisited;


        return this;
    }

    bool getIsVisited() {

        return this->isVisited;
    }

private: 
    int noOfOptions;
    int optionIndex;
    bool isVisited;
    vector<Option*> *options;
    
private: // functions:
    
    void listOptions(int currentChoice) {
        for( int i = 0; i < options->size(); i++ ) {

            // highlight highlighted
            if( i == currentChoice - 1) {
                options->at(i)->highlight();
            }
            printf("%s\n", options->at(i)->getName().c_str());
            if( i == currentChoice - 1) {
                options->at(i)->unHighlight();
            }

        }
    }


};


#endif //MENU_H