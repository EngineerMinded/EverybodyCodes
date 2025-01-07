/* Wayne Mack
 * Everybody Codes
 * Quest 3
 */

// FOR THOSE READING THIS, I HAVE THE BEST WIFE IN THE WORLD!
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>
using namespace std;

/**************************************************************************
 * Read data from file and create data array from them                    *
 **************************************************************************/
std::vector<std::string> readWordsFromFile(const std::string& filename) {
    std::ifstream file(filename);  // Open the file
    std::vector<std::string> words;  // Vector to store the words
    std::string word;

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return words;  // Return empty vector if file can't be opened
    }
    // Read the file word by word
    while (file >> word) {
        words.push_back(word);  // Add each word to the vector
    }

    file.close();  // Close the file
    return words;  // Return the vector of words
}
/************************************************************************
 * For Part One: Create a two dimensional integer vector from the input *
 * and tally the numbers.                                               *
 ************************************************************************/
int puzzleNumeration(vector<string> puzzle, bool isPart3) {
    vector<vector<int>> numPuzzle;
    for (string line: puzzle) {
        vector<int> newPuzzleLine;
        for (char c : line) {
            if (c == '#') newPuzzleLine.push_back(1);
            if (c == '.') newPuzzleLine.push_back(0);
        }
        numPuzzle.push_back(newPuzzleLine);
    }
    bool changesMade = true; int changeNum = 0; 
    while (changesMade)  {
        changesMade = false; 
        changeNum++;
        for (int u = 0; u < numPuzzle.size(); u++) {
            for (int v = 0; v < numPuzzle[u].size(); v++) {
                if (numPuzzle[u][v] == changeNum) {
                    bool validChange = true;
                    if ((v == 0) || (u == 0) || (u == numPuzzle.size() - 1) || (v == numPuzzle[u].size() - 1)) validChange = false;
                    if ((u > 0)) {
                        if (numPuzzle[u - 1][v] < changeNum) {
                            validChange = false;
                        } 
                    } 
                    if (u < numPuzzle.size() - 1) {
                        if (numPuzzle[u + 1][v] < changeNum ) {
                            validChange = false;
                        }
                    }
                    if (v > 0) {
                        if (numPuzzle[u][v + 1] < changeNum ) {
                            validChange = false;
                        }
                    } 
                    if (v < numPuzzle[u].size() - 1) {
                        if (numPuzzle[u][v - 1] < changeNum ) {
                            validChange = false;
                        }
                    }
                    if (isPart3 ) {
                        if ((u > 0) && (v < numPuzzle[u].size() - 1)) {
                            if (numPuzzle[u - 1][v + 1] < changeNum ) {
                                validChange = false;
                            }
                        }
                        if ((u > 0) && (v > 0)) {
                            if (numPuzzle[u - 1][v - 1] < changeNum) {
                                validChange = false;
                            }
                        }
                        if (((u < numPuzzle.size() - 1) && (v < numPuzzle[u].size() - 1))) {
                            if (numPuzzle[u + 1][v + 1] < changeNum) {
                                validChange = false;
                            }
                        }
                        if (((u < numPuzzle.size() - 1) && (v > 0))) {
                            if (numPuzzle[u + 1][v - 1] < changeNum) {
                                validChange = false;
                            } 
                        }
                    }
                    if (validChange) {
                        changesMade = true;
                        numPuzzle[u][v] = changeNum + 1;
                    }
                }
            }
        }
    }
    int count = 0; 
    for (vector<int> d : numPuzzle) {
        for (int e : d) {
            count = count + e; 
        }
    }
   
    return count;
}

/*******************************************************************
 * The Main Function                                               *
 *******************************************************************/

int main() {
    // PART ONE
    cout << "Part One: " << puzzleNumeration(readWordsFromFile("p1.txt"), 0) << endl;
    cout << "part Two:"  << puzzleNumeration(readWordsFromFile("p2.txt"), 0) << endl;
    cout << "Part Three: "<< puzzleNumeration(readWordsFromFile("p3.txt"), 1) << endl;
    return 0;
}
