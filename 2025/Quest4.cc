// Wayne Mack
// Everybody Codes
// Quest 4: PART ONE ONLY 

#include <vector>
#include <fstream>
#include <iostream>

std::vector<int> readNumbersFromFile(const std::string& filename) {
    std::vector<int> numbers;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filename << "\n";
        return numbers; // return empty vector
    }

    int value;
    while (file >> value) {
        numbers.push_back(value);
    }

    return numbers;
}

int getGearRPM(float speed, std::vector<int> gears, int part1) {
    if (part1 == 1) {
        for (int i = gears.size() - 1; i > 0; i--) {
            float gear2 = gears[i - 1]; float gear1 = gears[i];
            float ratio  = gear1 / gear2;
            speed = speed * ratio;
            std::cout << gears[i - 1] << " to " << gears[i] << " ratio: " << ratio << " new speed: " << speed << "\n";   
        }
    }
    else {
        for (int i = 1; i < gears.size(); i++) {
            float gear1 = gears[i - 1]; float gear2 = gears[i];
            float ratio  = gear1 / gear2;
            speed = speed * ratio;
        }
    }

    int returnThis = speed;
    return returnThis;
}

int main() {
    std::vector<int> nums = readNumbersFromFile("p1sample1.txt");
    std::vector<int> nums2 = readNumbersFromFile("p1sample2.txt");
    std::vector<int> nums3 = readNumbersFromFile("puzzle.txt");

    std::cout << "Sample 1: " << getGearRPM(2025, nums,0) << "\n";
    std::cout << "Sample 2: " << getGearRPM(2025, nums2,0) << "\n";
    std::cout << "Puzzle: " << getGearRPM(2025, nums3,0) << "\n";

    /***************************************************************
     * NUMBERS TOO BIG. PART TWO AND PART THREE DONE IN JAVASCRIPT *
     ***************************************************************/

    //std::cout << "Sample 1: " << getGearRPM(10000000000000 , nums,1) << "\n";
    //std::cout << "Sample 2: " << getGearRPM(10000000000000 , nums2,1) << "\n";
    //std::cout << "Puzzle: " << getGearRPM(10000000000000 , nums3,1) << "\n";

    return 0;
}
