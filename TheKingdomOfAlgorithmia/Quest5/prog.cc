/* Wayne Mack
 * Everybody Codes
 * Quest 5
 * 
 * ver 1.0 Part One Correct
 */



#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


// Part 1 functions
std::vector<std::vector<int> > readFileTo2DArray(const std::string& );
int nextNumberInSequence(int , int );
void insertNumberInRightPlace(vector<int>& , int);
void stepMove (vector<vector<int>>&, int );
void part1Step(vector<vector<int>>&, int);
void evaluate (vector<vector<int>>);
void partAnswer(vector<vector<int>>);

int main() {
    std::string filename = "p1.txt";  // Example file name
    std::vector<std::vector<int> > data = readFileTo2DArray(filename);

    // Display the contents of the 2D array
    evaluate(data);
    part1Step(data,10);
    return 0;
}

/*****************************************
 * Read the file data                    *
 *****************************************/
std::vector<std::vector<int> > readFileTo2DArray(const std::string& filename) {
    std::ifstream file(filename);  // Open the file
    std::vector<std::vector<int> > result;  // 2D vector to store the numbers
    std::string line;
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return result;  // Return empty 2D array in case of error
    }
    while (std::getline(file, line)) {  // Read each line from the file
        std::stringstream ss(line);  // Use stringstream to parse the line
        std::vector<int> row;
        int num;

        while (ss >> num) {  // Extract each number in the line
            row.push_back(num);
        }
        result.push_back(row);  // Add the row to the result 2D vector
    }
    file.close();  // Close the file after reading
    vector<vector<int> > revised;
    for (int x = 0; x < result[0].size(); x++) {
        vector<int> newLine;
        newLine.push_back(result[0][x]);
        for (int y = 1; y < result.size(); y++) {
            newLine.push_back(result[y][x]);
        }
        revised.push_back(newLine);
    }
    evaluate (result);
    return revised;  // Return the 2D array

}

int nextNumberInSequence(int rowsize, int thisNumber) {
    bool goInReverse = false;
    int targetNumber = 0;
    for (int x = 1; x < thisNumber; x++) {
        if (targetNumber == 0 && goInReverse) {
            goInReverse = false;
        }
        else if (targetNumber == rowsize && !goInReverse) {
            goInReverse = true;
        }
        else {
            goInReverse ? targetNumber = targetNumber - 1 : targetNumber = targetNumber + 1;
        }
    }
    return (targetNumber > rowsize) ? targetNumber - 1: targetNumber;
}

void insertNumberInRightPlace(vector<int>& row, int valueToInsert) {
    // insert the number in the specific row and pass it by reference
    row.insert(row.begin() + nextNumberInSequence(row.size(), valueToInsert), valueToInsert);
}

void stepMove (vector<vector<int>>& dancer, int stepToTake ) {
    // find the first value of the row you want and set it as an integer
    int nextValue = dancer[stepToTake][0];
    // remove that item from the dataset
    dancer[stepToTake].erase(dancer[stepToTake].begin() + 0);
    // designate next row as the row to add the value too. if at the end, add it to the first one.
    int nextRow = (stepToTake < dancer.size() - 1) ? stepToTake + 1 : 0;
    // determine where to insert it in the next row and, insert it.
    insertNumberInRightPlace(dancer[nextRow],nextValue);

}

void part1Step(vector<vector<int>>& dancers, int numberOfSteps) {
    for (int n = 0; n < numberOfSteps; n++) {
        int nextStep = n;
        while (nextStep >= dancers.size()) {
            nextStep = nextStep - dancers.size();
        }
        
        stepMove(dancers,nextStep);
        cout << "Step: " << n + 1 << " : ";
        partAnswer(dancers);
        cout << endl;
        evaluate(dancers);
    }
}

void partAnswer(vector<vector<int>> d) {
    int answer = 0;
    for (int x = 0; x < d.size(); x++) {
        answer = answer * 10;
        answer = answer + d[x][0];
    }
    cout << answer;
}

void evaluate (vector<vector<int>> data) {
    for (const auto& row : data) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    cout << endl;
}

