// Wayne Mack
// Everybody Codes
// Quest 7

#include <iostream>
#include <fstream>
#include <string>
#include "Dataset.hh"
#include <vector>
#include <algorithm>



Dataset getNewDataset(const string& filename) {
    Dataset newDataset = Dataset();
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file: " << filename << "\n";
        return newDataset;
    }

    string line;
    while (getline(file, line)) {
        if (line.find('>') != string::npos) {
            newDataset.addRule(line);
        } else if (line.find(',') != string::npos) {
            newDataset.addNames(line);
        }   
    }

    file.close();
    return newDataset;
}

int main() {
    Dataset test = getNewDataset("sample1.txt");
    //sample1.printDataset();
    cout << "Example 1: " << test.checkNames(1);
    Dataset puzzle = getNewDataset("puzzle1.txt");
    //puzzle1.printDataset();
    cout << "\nPuzzle 1: " << puzzle.checkNames(1);
    test.clearAll();
    test = getNewDataset("sample2.txt");
    //sample2.printDataset();
    cout << "\nExample 2: " << test.checkNames(2);
    puzzle.clearAll();
    puzzle = getNewDataset("puzzle2.txt");
    //puzzle2.printDataset();   
    cout << "\nPuzzle 2: " << puzzle.checkNames(2) << "\n";
    test.clearAll();
    test = getNewDataset("sample3a.txt");
    //test.printDataset();
    cout << "Sample 3a combinations: " << test.findAllPossibleNames(0) << "\n";
    test.clearAll();
    test = getNewDataset("sample3b.txt");
    //test.printDataset();
    cout << "Sample 3b combinations: " << test.findAllPossibleNames(0) << "\n";
    puzzle.clearAll();
    puzzle = getNewDataset("puzzle3.txt");
    cout << "Puzzle 3 combinations: " << puzzle.findAllPossibleNames(0) << "\n";

    return 0;
}
