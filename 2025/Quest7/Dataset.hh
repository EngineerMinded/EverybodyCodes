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

    void removeExtensions(vector<string>& words) {
        vector<string> result;

        for (size_t i = 0; i < words.size(); ++i) {
            bool isExtension = false;

            for (size_t j = 0; j < words.size(); ++j) {
                if (i != j &&
                    words[i].size() > words[j].size() &&
                    words[i].substr(0, words[j].size()) == words[j]) {
                    isExtension = true;
                    break;
                }
            }

            if (!isExtension) {
                result.push_back(words[i]);
            }
        }

        words = move(result);
    }


    void addRule(const string& input) {
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

    void addNames(const string& input) {
        vector<string> names;
        stringstream ss(input);
        string name;

        while (getline(ss, name, ',')) {
            // Optional: trim whitespace
            if (!name.empty() && name.front() == ' ')
                name.erase(0, 1);

            this->names.push_back(name);
            removeExtensions(this->names);
        }
    }


private: 

    int countAllCombinations(char thisLetter, int depth, int displayName, string name) {
        if (displayName) cout << name << endl;
        if (depth >= 11) {
            return 1;
        }
        int num = 0;
        for (Rules rule : rules) {
           if (rule.getLetter() == thisLetter) {
                for (char l : rule.getSubLetters()) {
                    num +=countAllCombinations(l , depth + 1,displayName, name + l);
                }
           }
        }
        return (depth < 7 ) ? num : num + 1;
    }

    int twoLettersSatisfiesTheRules(char letter1, char letter2) {
        for (Rules rule : rules) {
            if (rule.getLetter() == letter1) {
                for(char c : rule.getSubLetters()) {
                    if (c == letter2) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
public:
    int findAllPossibleNames(int displayName) {
        int num = 0;
        for (string name : names) {
            int wordIsSatisfied = 1;
            for (int k = 1; k < name.size() ; k++) {
                char letter1 = name[k - 1], letter2 = name[k];
                if (twoLettersSatisfiesTheRules(letter1,letter2) == 0) { 
                    //cout << name << " " << letter1 << " " << letter2 << endl;
                    wordIsSatisfied = 0;
                    break;
                }
            }
            if (wordIsSatisfied && name.size() <= 10) {
                char lastLetter = name[name.size() - 1];
                num += countAllCombinations(lastLetter,name.size(),displayName,name);
            }
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
    