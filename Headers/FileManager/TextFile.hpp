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
        // tmp
        this->open();
        //
        this->fileW.close();

        this->fileW.open(this->fileName, ios::app);
        this->fileW << dataToAppend << std::endl;

        // tmp
        this->close();
        //
    }
   
    // get file data as a string
    string getData() {
        string data;
        this->fileR >> data;

        return data;
    }

};


#endif // TEXTFILE_HPP
