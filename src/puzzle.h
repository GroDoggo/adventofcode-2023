#include <string>

class Puzzle {
public :
	std::string name;

	virtual bool execute() = 0;
};