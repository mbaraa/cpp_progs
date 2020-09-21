#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::string;
using std::ios;
using std::string;

class FileManager {
public:

    FileManager(std::string fileName) {

        this->fileName = fileName;
        openFile(fileName);

    }

    ~FileManager() {

        this->close();
        
    }

    // append to file
    virtual void append(std::string dataToAppend) = 0; 

    // delete file
    void del() {
        remove(this->fileName.c_str());

    }
    
    // get file data as a string
    virtual string getData() = 0;

protected: 

    ofstream fileW;
    ifstream fileR;

    string fileName;

protected: // shady functions used only in constructor and destructor

    // open file in reading/writing modes
    void openFile(string fileName) {

        // opern in appending mode to prevent file overwriting
        this->fileW.open(fileName, ios::app);
        // open file in reading mode
        this->fileR.open(fileName, ios::in);

    }

    void open() {
        this->openFile(this->fileName);
    }

    // close file, already called in the destructor :)
    void close() {

        this->fileR.close();
        this->fileW.close();

    }

};


#endif // FILEMANAGER_HPP