#include <iostream>
#include <vector>

#include "puzzle.h"

class day1 : public Puzzle {
	
public :
	day1() {
		name = "Day 1";
	}

	bool execute() override {
		std::cout << "Day 1" << std::endl;
		return true;
	}
};

int main(int argc, char const *argv[])
{
	// STARTING TEXT
    std::cout << "ADVENT OF CODE 2023"
        << "SELECT A PUZZLE : " << std::endl;

	// ADD PUZZLES
    std::vector<std::unique_ptr<Puzzle>> puzzle_list;
	puzzle_list.push_back(std::make_unique<day1>());

	// PRINT PUZZLES
	int index = 0;
	for (auto& puzzle : puzzle_list) {
		std::cout << index << " : " << puzzle->name << std::endl;
		index++;
	}

	// SELECT PUZZLE
	int selected_puzzle;
	std::cin >> selected_puzzle;

	// EXECUTE SELECTED PUZZLE
	puzzle_list[selected_puzzle]->execute();

    return 0;
}
