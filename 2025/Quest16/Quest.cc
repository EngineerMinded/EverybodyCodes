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
/// PART 2 DONE
/// PART 3 TALLYING NUMBERS INCORRECTLY

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
    for (int i = 0; i < numberOfPointsInList; i++){
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
    for (int i = 1; i < nums.size(); i++){
        if (numberCanBeFactoredOut(nums, i)) {
            for (int j = 1; j < nums.size()  + 1; j ++) {
                if (j % i == 0) {
                    nums[j - 1] -= 1;
                }
            }
            points.push_back(i);
        }
    }
    return points;
}

// USE AN INT FOR PART 1 BECAUSE THE NUMBERS ARE SMALLER
int partOne(NUM_LIST nums, int numberOfPointsInList) {
    NUM_LIST points = generateWall(nums, numberOfPointsInList);
    // INSTRUCTIONS MOVE TO ABOVE FUCTION FOR ERROR CHECKING
    int returnThis = 0;
    for (int n : points) {returnThis += n;}
    return returnThis;
}

// USE A LONG LONG FOR PART 2 BECAUSE THE NUMBERS GET REALLY BIG
long long  partTwo(NUM_LIST nums) {
    NUM_LIST points = generateSpell(nums, nums.size());
    long long returnThis = 1;
    for (int n : points) {returnThis *= n;}
    return returnThis;
}

long long gettotalNumberOfBlocksInWall(NUM_LIST nums) {
    long long total = 0;
    for (long long n = 0; n < nums.size(); n++) {total += nums[n];}
    return total;
}

long long getRemainingWall(NUM_LIST nums, long long totalBlocks) {
    long long totalWallSize = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (totalBlocks < nums[i]) {
            return totalWallSize;
        }
        totalBlocks -= nums[i];
        totalWallSize += 1;
    }
    return totalWallSize;
}

long long part3(NUM_LIST nums, unsigned long long totalBlocks) {
    long long totalBlocksInWall = gettotalNumberOfBlocksInWall(nums);
    // SOMETHING IS WRONG WITH THIS CALCULATION, IT THROWS OFF THE TOTAL
    long long totalWallSize = (totalBlocks / totalBlocksInWall) * nums.size();
    std::cout << " " << (totalBlocks / totalBlocksInWall) << " " << nums.size() << std::endl;
    long long remainingBlocks = totalBlocks % totalBlocksInWall;
    return totalWallSize + getRemainingWall(nums, remainingBlocks);
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
    // PART 3
    NUM_LIST example3 = readCommaSeparated("example2.txt");
    // ALL SAMPLE CASES
    std::cout << "Example 3a: " << part3(example3, 1) << std::endl;
    std::cout << "Example 3b: " << part3(example3, 10) << std::endl;
    std::cout << "Example 3c: " << part3(example3, 100) << std::endl;
    std::cout << "Example 3d: " << part3(example3, 1000) << std::endl;
    std::cout << "Example 3e: " << part3(example3, 10000) << std::endl;

    return 0;
}