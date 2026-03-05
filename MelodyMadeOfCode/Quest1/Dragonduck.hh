// Wayne Mack
// Everybody Codes
// Story 3 : Quest 1 - DRAGONDUCK OBJECT CLASS

// This program creates the DragonDuck class and processes 
// the input line to create the object with the appropriate values. 
// It is used in Parts 1 - 3.

#include <iostream>
using namespace std;
#include <string>
#include <sstream>

#ifndef DRAGONDUCK_HH
#define DRAGONDUCK_HH

class DragonDuck {
public:
    int numericValue;
    string redBinary, greenBinary, blueBinary, shineBinary;
    int redValue, greenValue, blueValue, shineValue;

    int parseBinaryValues(string binaryString) {
        string reversedString(binaryString.rbegin(), binaryString.rend());

        int value = 0;
        int multiplier = 1;
        for (char bit : reversedString) {
            if (bit == 'R' || bit == 'G' || bit == 'B' || bit == 'S') {
                value += multiplier;
            }
            multiplier *= 2;
        }
        return value;
    }

    DragonDuck(string line) { 
        size_t colonPos = line.find(':');
        numericValue = std::stoi(line.substr(0, colonPos));

        // Extract the rest after the colon
        std::string rest = line.substr(colonPos + 1);

        // Use a stringstream to split by spaces
        std::stringstream ss(rest);
        ss >> redBinary >> greenBinary >> blueBinary >> shineBinary;

        redValue = parseBinaryValues(redBinary);
        greenValue = parseBinaryValues(greenBinary);
        blueValue = parseBinaryValues(blueBinary);
        if (shineBinary != "") {
            shineValue = parseBinaryValues(shineBinary);
        } else {
            shineValue = 0;
        }
    }
};  

#endif // DRAGONDUCK_HH