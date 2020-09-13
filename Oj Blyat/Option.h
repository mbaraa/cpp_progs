#ifndef OPTION_H
#define OPTION_H

#include <string>
using std::string;

class Option {
public:

    // constructor blyat
    Option(string name) {

        this->name = name;
        this->isHighlighted = false;

    }

    // highlight by setting color to cyan
    void highlight() {
        
        this->nameUnHighlighted = this->name;
        this->name = "\033[47m\033[30m"  + this->name + "\033[0m";

    }

    // reset color to white
    void unHighlight() {
        
        this->name = this->nameUnHighlighted;

    }

    // name getter
    string getName() {

        return this->name;

    }


private:
    string name;
    string nameUnHighlighted;
    bool isHighlighted;
};



#endif //OPTION_H