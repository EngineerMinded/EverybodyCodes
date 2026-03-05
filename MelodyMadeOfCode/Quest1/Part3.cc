// Wayne Mack
// Everybody Codes
// Story 3 : Quest 1 - PART THREE

// This program is modified from the DragonDuckGenerator.cc
// This program solves Part Three

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dragonduck.hh"

string determineDominantColor(DragonDuck&);

vector<DragonDuck> biggerList(vector<DragonDuck>& , vector<DragonDuck>& );

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
    vector<DragonDuck> redShiny, redmatte, greenShiny, greenmatte, blueShiny, bluematte;

    for (DragonDuck& duck : dragonDucks) {
        string status = "--";
        if (duck.shineValue >= 33) {
            status = "shiny";
        } else  if (duck.shineValue <= 30) {
            status = "matte";
        }
        string dominantColor = determineDominantColor(duck);
        if (dominantColor == "red") {
            if (status == "shiny") {
                redShiny.push_back(duck);
            } else if (status == "matte") {
                redmatte.push_back(duck);
            }
        } else if (dominantColor == "green") {
            if (status == "shiny") {
                greenShiny.push_back(duck);
            } else if (status == "matte") {
                greenmatte.push_back(duck);
            }
        } else if (dominantColor == "blue") {
            if (status == "shiny") {
                blueShiny.push_back(duck);
            } else if (status == "matte") {
                bluematte.push_back(duck);
            }
        }
    }
    vector<DragonDuck> biggestClass = biggerList(redShiny, redmatte);
    biggestClass = biggerList(biggestClass, greenShiny);
    biggestClass = biggerList(biggestClass, greenmatte);
    biggestClass = biggerList(biggestClass, blueShiny);
    biggestClass = biggerList(biggestClass, bluematte);


    for (DragonDuck& duck : biggestClass) {
        answer += duck.numericValue;
    }
    std::cout << "Answer: " << answer << "\n";
    return 0;
}

string determineDominantColor(DragonDuck& thisDuck) {
    if (thisDuck.redValue > thisDuck.greenValue && thisDuck.redValue > thisDuck.blueValue) {
        return "red";
    } else if (thisDuck.greenValue > thisDuck.redValue && thisDuck.greenValue > thisDuck.blueValue) {
        return "green";
    } else if (thisDuck.blueValue > thisDuck.redValue && thisDuck.blueValue > thisDuck.greenValue) {
        return "blue";
    } else {
        return "none"; // In case of a tie or no dominant color
    }
}

vector<DragonDuck> biggerList(vector<DragonDuck>& list1, vector<DragonDuck>& list2) {
    if (list1.size() > list2.size()) {
        return list1;
    } else {
        return list2;
    }
}