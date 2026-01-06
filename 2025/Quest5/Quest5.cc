// Wayne Mack
// Everybody codes
// Quest 5: Fishbone Swords

////////////////////////////////////
// ALL PARTS SOLVED               //
////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Fishbone.hh"
#include "Sword.hh"
#include "SwordList.hh"
using namespace std;

std::vector<std::string> readLines(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

long long part2(string filename) {
    vector<long long> finalValues;
    vector<string> p2Examples = readLines(filename);
    for (const string& line : p2Examples) {
        Sword S = Sword();
        S.manuallyinsertData(line);
        Fishbone F = Fishbone();
        F.add(S);
        finalValues.push_back(F.getStraightValue());
    }
    long long highest = -1, lowest =  9223372036854775800;
    for (long long val : finalValues) {
        if (val > highest) highest = val;
        if (val < lowest ) lowest = val;
    }
    return highest - lowest;
}

SwordList sortByStrength(SwordList unsorted) {
    SwordList sorted = SwordList();
    vector<bool> added(unsorted.swords.size(), false);
    for (int i = 0; i < unsorted.swords.size(); i++) {
        int bestIndex = -1;
        for (int j = 0; j < unsorted.swords.size(); j++) {
            if (added[j]) continue;
            if (bestIndex == -1 || unsorted.fishbones[j].isBetterThan(unsorted.fishbones[bestIndex]) ) {
                bestIndex = j;
            }
        }
        sorted.add(unsorted.swords[bestIndex]);
        added[bestIndex] = true;
    }
    return sorted;
}

long long part3(string filename, int showValues) {
    SwordList SL = SwordList();
    vector<string> p3Examples = readLines(filename);
    for (const string& line : p3Examples) {
        Sword S = Sword();
        S.manuallyinsertData(line);
        SL.add(S);
    }
    if (showValues) SL.print();
    SwordList sorted = sortByStrength(SL);
    if (showValues) cout << "Sorted Swords by Strength:" << endl;
    if (showValues) sorted.print();
    int returnThis = 0;
    for (int i = 0; i < sorted.swords.size(); i++) {
        returnThis += (sorted.swords[i].headValue * (SL.swords[i].headValue));
    }
    return returnThis;
}

int main() {
    //PART1
    Sword part1Sample = Sword("part1Sample.txt");
    Sword part1Puzzle = Sword("part1Puzzle.txt");
    // Execute Sample
    Fishbone p1Sample = Fishbone();
    p1Sample.add(part1Sample);
    cout << p1Sample.getStraightValue() << endl; 
    // Execute Puzzle
    Fishbone p1Puzzle = Fishbone();
    p1Puzzle.add(part1Puzzle);
    cout << p1Puzzle.getStraightValue() << endl;

    //PART2
    cout << "Part 2 Sample " << part2("part2Sample.txt") << endl;
    cout << "Part 2 Puzzle " << part2("part2Puzzle.txt") << endl;

    //PART3
    cout << "Part 3 Sample " << part3("part3Sample.txt",1)<< endl;
    cout << "Part 3 Puzzle " << part3("part3Puzzle.txt",0)<< endl;
}
