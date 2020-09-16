#ifndef TEXTFILE_HPP
#define TEXTFILE_HPP

#include <string>
#include <fstream>
#include "FileManager.hpp"

using std::ofstream;
using std::string;
using std::ios;
using std::string;

class TextFile: public FileManager {
public:

    TextFile(string fileName): FileManager(fileName) {} // constructor from parent

    ~TextFile() {} // destructor from parent

    // append to file
    void append(std::string dataToAppend) {

        this->fileW.close();

        this->fileW.open(this->fileName, ios::app);
        this->fileW << dataToAppend << std::endl;

    }
   
    // get file data as a string
    string getData() {

    }

};


#endif // TEXTFILE_HPP
