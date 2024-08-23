#include <string>
#include <fstream>
#include <sstream>
#include <assert.h>

class Filereader {

protected :
	std::stringstream buffer;

public: 
	bool read(std::string filepath) {
		std::ifstream inputfile(filepath);

		if (inputfile) {
			buffer << inputfile.rdbuf();

			inputfile.close();
		}

		return bool(inputfile);
	}

	std::string getLine() {
		assert(!buffer.eof());

		std::string line;
		std::getline(buffer, line);
		return line;
	}

	bool eof() {
		return buffer.eof();
	}
};