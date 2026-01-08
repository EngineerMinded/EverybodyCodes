#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>
#include "Rules.hh"

#ifndef DATASET_HH
#define DATASET_HH

class Dataset { 
    vector<string> names;
    vector<Rules> rules;
public:
    Dataset() {
        names = {};
        rules = {}; 
    }

    void clearAll() {
        names.clear();
        rules.clear();
    }

    void addNames(const std::string& input) {
        std::vector<std::string> names;
        std::stringstream ss(input);
        std::string name;

        while (std::getline(ss, name, ',')) {
            // Optional: trim whitespace
            if (!name.empty() && name.front() == ' ')
                name.erase(0, 1);

            this->names.push_back(name);
        }
    }

    void addRule(const std::string& input) {
        Rules rule(input);
        rules.push_back(rule);
    }

    void printDataset() const {
        cout << "Names: ";
        for (const auto& name : names) {
            cout << name << " ";
        }
        cout << "\nRules:\n";
        for (const auto& rule : rules) {
            rule.printRule();
        }
    }
private:
/**********************************************************
 * WHY DON'T THIS WORK?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?   *
 **********************************************************/
 
    long long countAllCombinations(char thisLetter) {
        
        long long num = 1;
        for (Rules rule : rules) {
           if (rule.getLetter() == thisLetter) {
            cout << "Expanding letter: " << thisLetter << "\n";
            num = num + 1;
                for (char l : rule.getSubLetters()) {
                    num = num + countAllCombinations(l);
                } 
           }
        }
        cout << num << endl;
        return num;
    }
public:
    long long findAllPossibleNames() {
        long long num = 0;
        for (string name : names) {
            char lastLetter = name[name.size() -1];
            num = num + 1; //count the name itself
            num= num + countAllCombinations(lastLetter);
        }
        return num;
    }    

    string checkNames(int partNumber) {
        int part2Answer = 0;
        int nameNumberCounter = 0;
        for (const auto& name : names) {
            nameNumberCounter += 1;
            int nameIsValid = 1;
            for (int i = 0; i < name.size() -1; ++i) {
                for (const auto& rule : rules) {
                    if (name[i] == rule.getLetter()) {
                        int letterIsValid = 0;
                        for (char l : rule.getSubLetters()) {
                            if (name[i + 1] == l) {
                                letterIsValid = 1;
                            }   
                        }
                        if (letterIsValid == 0) {
                            nameIsValid = 0;
                            break;
                        }
                    }
                }
            }
            if (nameIsValid == 1 && partNumber == 1) {
                return name;
            }
            if (nameIsValid == 1 && partNumber == 2) {
                part2Answer += nameNumberCounter;
            }
        }
        if (partNumber == 2) {
            return to_string(part2Answer);
        }
        return "No valid names found.";
    }
};

#endif
    