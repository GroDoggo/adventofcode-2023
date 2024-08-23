#pragma once
#include <string>

class Puzzle {
public :
	std::string name;

	virtual bool execute() = 0;

	Puzzle(std::string n) : name(n) {}
};