/* Wayne Mack
 * Everybody Codes
 * Quest 5
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

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
    for (int x = 0; x < result.size(); x++) {
        vector<int> newLine;
        newLine.push_back(result[0][x]);
        for (int y = 1; y < result[x].size(); y++) {
            newLine.push_back(result[y][x]);
        }
        revised.push_back(newLine);
    }
    return revised;  // Return the 2D array

}

void newRound(vector<vector<int> > dancers, int round ) {
    // Prevent segmentation faults
    while (round > dancers.size()) {
        round -= dancers.size();
    }



}

int main() {
    std::string filename = "p1example.txt";  // Example file name
    std::vector<std::vector<int> > data = readFileTo2DArray(filename);

    // Display the contents of the 2D array
    for (const auto& row : data) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}