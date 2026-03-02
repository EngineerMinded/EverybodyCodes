// Wayne Mack
// Everybody Codes
// Quest 16

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#define NUM_LIST std::vector<int>

/// PART 1 DONE 
// PART 2 PRACTICAL IS WRONG`

NUM_LIST readCommaSeparated(const std::string& filename) {
    std::vector<int> nums;
    std::ifstream file(filename);
    if (!file.is_open()) return nums;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            if (!token.empty()) {
                nums.push_back(std::stoi(token));
            }
        }
    }
    return nums;
}

NUM_LIST generateWall(NUM_LIST nums, int numberOfPointsInList) {
    NUM_LIST newList;
    for (int i = 0; i < numberOfPointsInList; i++)
    {
        newList.push_back(0);
    }
    for (int nextNum : nums) {
        for (int i = 0; i < numberOfPointsInList; i++) {
            if ((i + 1) % nextNum == 0) {
                newList[i] += 1;
            }
        }
    }
    return newList;
}

bool numberCanBeFactoredOut(NUM_LIST numberList, int numberToTest) {
    int counter = numberToTest - 1;
    while (counter < numberList.size()) {
        if (numberList[counter] < 1) {
            return false;
        }
        counter += numberToTest;
    }
    return true;
}

NUM_LIST generateSpell(NUM_LIST nums, int numberOfPointsInList) {
    NUM_LIST points;
    for (int i = 1; i < nums.size(); i++)
    {
        if (numberCanBeFactoredOut(nums, i)) {
           
            for (int j = 1; j < nums.size()  + 1; j ++) {
                if (j % i == 0) {
                    nums[j - 1] -= 1;
                }
            }
            std::cout << "Number " << i << " can be factored out.";
      
            std::cout << std::endl;
            points.push_back(i);
        }
    }
    return points;
}

int partOne(NUM_LIST nums, int numberOfPointsInList) {
    NUM_LIST points = generateWall(nums, numberOfPointsInList);
    // INSTRUCTIONS MOVE TO ABOVE FUCTION FOR ERROR CHECKING
    int returnThis = 0;
    for (int n : points) {returnThis += n;}
    return returnThis;
}

int partTwo(NUM_LIST nums) {
    NUM_LIST points = generateSpell(nums, nums.size());

    NUM_LIST errorCheck = generateWall(points, nums.size());
    for (int n = 0; n < errorCheck.size(); n++) {
        std::cout << errorCheck[n] << "-" << nums[n] << " "; 
        
    }

    int returnThis = 1;
    for (int n : points) {returnThis *= n;}
    return returnThis;
}

int main() {
    // PART 1
    NUM_LIST example1 = readCommaSeparated("example1.txt");
    std::cout << "Example 1: " << partOne(example1, 90) << std::endl;
    NUM_LIST part1 = readCommaSeparated("part1.txt");
    std::cout << "Part 1: " << partOne(part1, 90) << std::endl;
    // PART 2
    NUM_LIST example2 = readCommaSeparated("example2.txt");
    std::cout << "Example 2: " << partTwo(example2) << std::endl;  
    NUM_LIST part2 = readCommaSeparated("part2.txt");
    std::cout << "Part 2: " << partTwo(part2) << std::endl; 
    
    return 0;
}