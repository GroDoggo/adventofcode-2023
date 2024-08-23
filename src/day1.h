#pragma once
#include "filereader.h"
#include "puzzle.h"

class Day1P1 : public Puzzle {
public :
	Day1P1() : Puzzle("Day 1 - Part 1 - Trebuchet?!") {}

	std::string execute() override {
		std::size_t sum_all_line_two_digit_numbers = 0;

		Filereader fr;
		fr.read("../data/day1-train.txt");
		while (!fr.eof()) {

			std::string line = fr.getLine();
			std::size_t line_length = line.length();

			int first_digit_of_line = -1;
			int last_digit_of_line = -1;

			for (int index = 0; index < line_length; index++) {
				char c = line[index];
				if (c >= '0' && c <= '9') //it's a number
				{
					if (first_digit_of_line < 0)
						first_digit_of_line = c - '0';
					last_digit_of_line = c - '0';
				}
			}

			int two_digit_final_number = first_digit_of_line * 10 + last_digit_of_line;
			sum_all_line_two_digit_numbers += two_digit_final_number;

			std::cout << "Line number " << two_digit_final_number << "\n";
			std::cout << "\n";
		}

		return std::to_string(sum_all_line_two_digit_numbers);
	}
};