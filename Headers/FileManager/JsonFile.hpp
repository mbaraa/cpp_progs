#ifndef JSONFILE_HPP
#define JSONFILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp> // github.com/nlohmann/json
#include "FileManager.hpp"

using nlohmann::json;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;


class JsonFile: FileManager {
public:

	// hmm
	JsonFile(json *jsonData, string jsonName): FileManager(jsonName) {

		this->actualJson = jsonData;

	}

	~JsonFile() {}

	// put json data into a json file, replacing old data
	void append() {

		// json files must be treated as binary files
		this->fileW.open(this->fileName + ".json", ifstream::binary); 

		this->fileW << 
				(*this->actualJson).dump();

	}

	// load json from a file
	void load() {
		string data;
		this->fileR >> data;

		(*this->actualJson) = json::parse(data); 

	}

private:

	json *actualJson;
    +
};

#endif // JSONFILE_HPP