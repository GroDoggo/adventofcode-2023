#pragma once
#include <string>

class Puzzle {
public :
	std::string name;

	virtual std::string execute() = 0;

	Puzzle(std::string n) : name(n) {}
};