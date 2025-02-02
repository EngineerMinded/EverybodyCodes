/* Wayne Mack
 * Everybody Codes
 * Quest 5
 * 
 * ver 1.0 Part One Correct
 * ver 1.5 Part 2 very long to get answer
 */



#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


// universal functions
std::vector<std::vector<int> > readFileTo2DArray(const std::string& );
int nextNumberInSequence(int , int );
void insertNumberInRightPlace(vector<int>& , int);
void stepMove (vector<vector<int>>&, int );
void part1Step(vector<vector<int>>&, int);
void evaluate (vector<vector<int>>);
// part 1 functions
int partAnswer(vector<vector<int>>);
// Part 2 functions
unsigned long long numberHasBeenCountedNthNumberOfTimes(vector<vector<int>>, int) ;
unsigned long long part2Step(vector<vector<int>>& , int);
void insertIntoNumberCounter(vector<vector<int>>& , int);

int main() {
    std::string filename = "p1.txt";  // Example file name
    std::vector<std::vector<int> > data = readFileTo2DArray(filename);

    // Display the contents of the 2D array
    evaluate(data);
    part1Step(data,10);
    filename = "p2.txt";
    vector<vector<int>> part2 = readFileTo2DArray(filename);
    //part1Step(part2,10);
    cout << endl << "Part 2 Answer :" << part2Step(part2, 2024);
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
        else if (targetNumber == rowsize -1 && !goInReverse) {
            goInReverse = true;
        }
        else {
            goInReverse ? targetNumber = targetNumber - 1 : targetNumber = targetNumber + 1;
        }
    }
    return goInReverse? targetNumber + 1 : targetNumber;
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
        cout << "Step: " << n + 1 << " : " << partAnswer(dancers);
        cout << endl;
        evaluate(dancers);
    }
}
unsigned long long numberHasBeenCountedNthNumberOfTimes(vector<vector<int>>numberList, int numberOfTimesToBeCounted) {
    int highestNumber = 0;
    for (vector<int> numberSet : numberList) {
        if (numberSet[1] == numberOfTimesToBeCounted) {
            cout << "Winning Number :" << numberSet[0] << endl;
            return numberSet[0];
        }
        else if (numberSet[1] > highestNumber) {
            highestNumber = numberSet[1];
        }
    }
    cout << endl << "Highest Number " << highestNumber << " List Size" << numberList.size()<< " ";
    return 0;
}

void insertIntoNumberCounter(vector<vector<int>>& numberList, int numberToInsert) {
    bool numberInserted = false;
    for (int x = 0; x < numberList.size() && !numberInserted; x++) {
        if (numberToInsert == numberList[x][0]) {
            numberList[x][1] = numberList[x][1] + 1;
            numberInserted = true;
        }
    }
    if (!numberInserted) {
        vector<int> newEntry = {numberToInsert, 1};
        numberList.push_back(newEntry);
    }
}


unsigned long long part2Step(vector<vector<int>>& dancers, int numberOfTimesAnumberHasToBeCounted) {
    vector<vector<int>> numberCounter;
    // TO DO: start right here
    int n = 0;
    while (numberHasBeenCountedNthNumberOfTimes(numberCounter, numberOfTimesAnumberHasToBeCounted) == 0) {
        int nextStep = n;
        while (nextStep >= dancers.size()) {
            nextStep = nextStep - dancers.size();
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////
        // THE NUMBER LIST HAS TO HAVE A PLACE WHERE THE NUMBER LOOPS ITSELF. FIND OUT WHERE THE NUMBERS //
        // LOOPS ITSELF AND TALLY UP THE NUMBER LIST ONLY BASED ON THA                                   //
        ///////////////////////////////////////////////////////////////////////////////////////////////////
        
        stepMove(dancers,nextStep);
        cout << "Step: " << n + 1 << " : " << partAnswer(dancers);
        cout << endl;
        insertIntoNumberCounter(numberCounter, partAnswer(dancers)); 
        //evaluate(dancers);
        n++;
    }
    return numberHasBeenCountedNthNumberOfTimes(numberCounter, numberOfTimesAnumberHasToBeCounted) * n;
}
int partAnswer(vector<vector<int>> d) {
    int answer = 0;
    for (int x = 0; x < d.size(); x++) {
        int r = d[x][0];
        while ( r > 9) {
            answer = answer * 10;
            answer = answer + r;
            r = r % 10;
        }
        answer = answer * 10;
        answer = answer + r;
    }
    return answer;
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

