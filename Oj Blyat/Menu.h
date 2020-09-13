#ifndef MENU_H
#define MENU_H

#include <vector> // for options list
using std::vector; // for typo
#include <string>
using std::string; // typo
using std::to_string; // typo typo typo
#include "Option.h" // a menu consists of options of course
#include <stdio.h>  // will nothing
#include "kbInput.h" // getch()
#include "shared.h" // clear()
#include <stdlib.h> // exit

class Menu {
public:
    Menu() {
        this->options = new vector<Option*>;
        this->optionIndex = 1;
        this->noOfOptions = 0;
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

    int chooseOption() {

        // default option is the first one
        int nCurrentOption = 1;
        // to hold the pressed key
    	char cKeyStrokeVal;
        // oj blyat classic menu
    	while(1) {
            // hmm
    		this->listOptions(nCurrentOption);

            // blyaaaaaaat
    		cKeyStrokeVal = getch();

            // key handeling:
            /* 
             * (q) for quit program
             * (j) to move down, vim keys
             * (k) to move up, vim keys
             * (g) for selecting
             */

    		if( cKeyStrokeVal == 'q' ){
    			
               	exit(0);
    			
            } else if( cKeyStrokeVal == 'j' ){

   				nCurrentOption++;

   			} else if( cKeyStrokeVal == 'k' ){

   				nCurrentOption--;

   			} else if( cKeyStrokeVal == 'g' ) {

                return nCurrentOption;

            }

            // menu boundries
            /*
             * expected a comment didn't ya :)
             *
             */
    		if( nCurrentOption > this->noOfOptions ){
    		
            	nCurrentOption = 1;

    		} else if( nCurrentOption < 1 ){

    			nCurrentOption = this->noOfOptions;

    		}
    		clear();
		
        }        

        return 0;

    } // int chooseOption()

private: 
    int noOfOptions;
    int optionIndex;

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