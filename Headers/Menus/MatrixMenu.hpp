#ifndef MATRIXMENU_HPP
#define MATRIXMENU_HPP

#include <vector> // for options list
#include <string> // lol
#include <stdio.h> // printf
#include "Option.hpp" // a menu consists of options
#include "Menu.hpp" // parent class
#include "../kbInput.h" // getch
#include "../OutputControl.hpp" // clear

class MatrixMenu: public Menu {
public:
    MatrixMenu(unsigned int columns): Menu(1), columns(columns) {}

    ~MatrixMenu() {}

    void addRowOption(std::string optionName) {
        Menu::addOption(optionName);

    }

    void addColOption(std::string optionName) {
        //if()

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
            
            nCurrentOption = (cKeyStrokeVal == 'l')? nCurrentOption + 1:
                (cKeyStrokeVal == 'h')? nCurrentOption - 1:
                (cKeyStrokeVal == 'j')? nCurrentOption - this->columns:
                (cKeyStrokeVal == 'k')? nCurrentOption + this->columns: nCurrentOption;
                ;

            // menu boundries
            /*
             * expected a comment didn't ya :)
             *
             */
            nCurrentOption = nCurrentOption > this->noOfOptions? 1:
                ( nCurrentOption < 1)? this->noOfOptions: nCurrentOption;

    		OutputControl::clear();
		
        }        

        // exit code
        return 0;

    } // int chooseOption()

private:
    unsigned int columns;

private: // functions

    void listOptions(int currentChoice) {
        for( int i = 0; i < this->options->size(); i++ ) {
            // highlight highlighted
            if( i == currentChoice - 1) {
                options->at(i)->highlight();
            }
            printf(" %s", options->at(i)->getName().c_str());
            if( i == currentChoice - 1) {
                options->at(i)->unHighlight();
            }
            
            if( (i + 1) % this->columns == 0 && i + 1 > 1 )
                printf("\n");

        }

    }


};

#endif // MATRIXMENU_HPP