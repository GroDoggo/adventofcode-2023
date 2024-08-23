cmake_minimum_required(VERSION 3.0...3.30.2)
project(advent_of_code_2023)

file(GLOB PROJECT_CPP_FILES
    "src/main.cpp"
)

file(GLOB PROJECT_INCLUDE_FILES
    "src/puzzle.h"
)

add_executable( adventofcode2023
    ${PROJECT_CPP_FILES}
    ${PROJECT_INCLUDE_FILES}
)