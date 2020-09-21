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


class JsonFile: public FileManager {
public:

	// hmm
	JsonFile(json *jsonData, string jsonName): 
		FileManager(jsonName + ".json") {

		this->jsonData = jsonData;
		//this->load();

	}

	~JsonFile() {}

	// put json data into a json file, REPLACING OLD DATA
	void append(string dummyString = "nullptr") {
		// tmp
		this->open();
		//
		
		this->fileW.close();

		// json files must be treated as binary files
		this->fileW.open(this->fileName, ifstream::binary); 

		this->fileW << 
				(*this->jsonData).dump();

		// tmp
		this->close();
		//
	}

	// load json from a file
	int load() {

		string data;
		this->fileR >> data;

		try {
			(*this->jsonData) = json::parse(data); 

			return 0; // normal
			
		} catch(nlohmann::detail::parse_error pe) {

			return 1; // zero file
		}


	}

	string getData() {

		return this->jsonData->dump();

	}

private:

	json *jsonData;

};

#endif // JSONFILE_HPP