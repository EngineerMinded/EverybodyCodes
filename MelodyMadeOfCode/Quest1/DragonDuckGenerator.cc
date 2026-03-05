// Wayne Mack
// Everybody Codes
// Story 3 : Quest 1

// This file is the template to read files and create DragonDuck objects.
// It is modified for uses in Parts 1  - 3. This program merely displays the
// information for errorchecking.

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
    for (DragonDuck& duck : dragonDucks) {
        std::cout << "Numeric Value: " << duck.numericValue << "\n";
        std::cout << "Red Binary: " << duck.redBinary << " -> Red Value: " << duck.redValue << "\n";
        std::cout << "Green Binary: " << duck.greenBinary << " -> Green Value: " << duck.greenValue << "\n";
        std::cout << "Blue Binary: " << duck.blueBinary << " -> Blue Value: " << duck.blueValue << "\n";
        std::cout << "-----------------------------\n";
    }
    
   

    return 0;
}