#include <iostream>
#include <vector>
#include <windows.h>   // WinApi header

#include "puzzle.h"
#include "filereader.h"

// Puzzle codes
#include "day1.h"

class Example : public Puzzle {
	
public :
	Example() : Puzzle("Example puzzle") {}

	bool execute() override {
		std::cout << "This is an example..." << std::endl;
		return true;
	}
};

int main(int argc, char const *argv[])
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// STARTING TEXT
	SetConsoleTextAttribute(hConsole, 13);
	std::cout << "ADVENT OF CODE 2023\n\n";
	SetConsoleTextAttribute(hConsole, 15);
    std::cout << "SELECT A PUZZLE : " << std::endl;

	// ADD PUZZLES
    std::vector<std::unique_ptr<Puzzle>> puzzle_list;
	puzzle_list.push_back(std::make_unique<Example>());
	puzzle_list.push_back(std::make_unique<Day1P1>());

	// PRINT PUZZLES
	int index = 0;
	for (auto& puzzle : puzzle_list) {
		std::cout << index << " : " << puzzle->name << std::endl;
		index++;
	}

	// SELECT PUZZLE
	int selected_puzzle;
	std::cin >> selected_puzzle;

	std::cout << std::endl << std::endl;

	// EXECUTE SELECTED PUZZLE
	try
	{
		bool result = puzzle_list[selected_puzzle]->execute();
		if (result) {
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "The puzzle execution ended with no error" << std::endl;
		}
		else {
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "[WARNING] : The puzzle execution ended with an error" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		SetConsoleTextAttribute(hConsole, 4);
		std::cout << "[ERROR] : The puzzle execution failed with an exception\n" 
			<< e.what() << std::endl;
	}

	SetConsoleTextAttribute(hConsole, 15);

    return 0;
}
