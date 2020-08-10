#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;
#include <stdio.h> // for file managment
#include <stdlib.h> // for some mangaments

class FileManager {
public:

    FileManager(std::string fileName) {
        
        this->fileName = fileName;
        file.open(fileName, std::ios::in);

    }

private:

    
    ofstream file;
    std::string fileName;

};


#endif // FILEMANAGER_H