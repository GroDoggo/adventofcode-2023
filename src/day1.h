#pragma once
#include "filereader.h"
#include "puzzle.h"

class Day1P1 : public Puzzle {
public :
	Day1P1() : Puzzle("Day 1 - Part 1 - Trebuchet?!") {}

	bool execute() override {
		std::cout << "This is an example..." << std::endl;
		return true;
	}
};