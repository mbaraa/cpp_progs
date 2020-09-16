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
	JsonFile(json *jsonData, string jsonName): FileManager(jsonName + ".json") {

		this->jsonData = jsonData;

	}

	~JsonFile() {}

	// put json data into a json file, REPLACING OLD DATA
	void append(string dummyString = "nullptr") {

		this->fileW.close();

		// json files must be treated as binary files
		this->fileW.open(this->fileName, ifstream::binary); 

		this->fileW << 
				(*this->jsonData).dump();


	}

	// load json from a file
	void load() {
		string data;
		this->fileR >> data;

		try {
			(*this->jsonData) = json::parse(data); 
		
		} catch(nlohmann::detail::parse_error pe) {

			puts("\033[31m");
			puts("ZERO FILE!!");
			puts("\033[0m");
		}
	}

	string getData() {

		this->jsonData->dump();

	}

private:

	json *jsonData;

};

#endif // JSONFILE_HPP