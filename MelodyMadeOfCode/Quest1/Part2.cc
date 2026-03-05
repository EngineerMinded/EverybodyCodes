// Wayne Mack
// Everybody Codes
// Story 3 : Quest 1 - PART TWO

// This program is modified from the DragonDuckGenerator.cc
// This program solves Part Two

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dragonduck.hh"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    const char* filename = argv[1];
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file '" << filename << "'\n";
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    // process DragonDuck objects
    std::vector<DragonDuck> dragonDucks;
    for (const std::string& line : lines) {
        dragonDucks.emplace_back(DragonDuck(line));
    }

    int answer = 0;
    int brightestShineValue = 0;
    int highestNumericValue = 0;

    for (DragonDuck& duck : dragonDucks) {
        if (duck.shineValue >= brightestShineValue) {
            if (duck.shineValue > brightestShineValue) {
                highestNumericValue = 0; // reset highest numeric value if we find a brighter shine
                answer = 0; // reset answer as well
            }
            brightestShineValue = duck.shineValue;
            int currentNewValue = duck.redValue + duck.greenValue + duck.blueValue;
            cout << "Shine Value: " << duck.shineValue << " Current Duck: " << currentNewValue << " Answer: " << duck.numericValue << " Highest Value " << highestNumericValue << " " << answer <<"\n";
            if (currentNewValue < highestNumericValue || highestNumericValue == 0) {
                highestNumericValue = currentNewValue;
                answer = duck.numericValue;
            }   
        } 
    }
    std::cout << "Answer: " << answer << "\n";
 
    return 0;
}