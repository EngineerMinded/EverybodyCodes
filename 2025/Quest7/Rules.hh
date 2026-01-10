#include <iostream>
using namespace std;
#include <vector>
#include <string>

#ifndef RULES_HH
#define RULES_HH    

class Rules {
    char letter;
    vector<char> leadingLetters;

public:
    Rules(string dataToAdd) {
        letter = dataToAdd[0];
        for (size_t i = 2; i < dataToAdd.size(); ++i) {
            if (dataToAdd[i] != ' ' && dataToAdd[i] != '>' && dataToAdd[i] != ',')
            leadingLetters.push_back(dataToAdd[i]);
        }
    }
    void printRule() const {
        cout << letter << " -> ";
        for (const auto& l : leadingLetters) {
            cout << l << " ";
        }
        cout << "\n";
    }
    char getLetter() const {
        return letter;
    }
    vector<char> getSubLetters() const {
        return leadingLetters;
    }
};

#endif