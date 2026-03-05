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

    for (DragonDuck& duck : dragonDucks) {

        if (duck.greenValue > duck.redValue && duck.greenValue > duck.blueValue) {
            answer += duck.numericValue;
        }  
    }
    std::cout << "Answer: " << answer << "\n";
 
    return 0;
}