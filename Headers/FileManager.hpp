#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>

using std::ofstream;
using std::string;
using std::ios;

class FileManager {
public:

    FileManager(std::string fileName) {

        this->fileName = fileName;
        openFile(fileName);

    }

    void append(std::string dataToAppend) {

        this->file << dataToAppend << std::endl;

    }

    void close() {

        this->file.close();

    }

private: // variables

    ofstream file;
    std::string fileName;

private: // functions

    void openFile(std::string fileName) {

        // if file exists overwrite it
        this->file.open(fileName, ios::out);
        this->file.close();
        // reopen the file in appending mode
        this->file.open(fileName, ios::app);

    }

};


#endif // FILEMANAGER_H
