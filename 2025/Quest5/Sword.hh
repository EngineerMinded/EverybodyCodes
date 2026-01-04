#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#ifndef SWORD_HH
#define SWORD_HH    

class Sword {
    public:
    int headValue;
    vector<int> values;

    Sword() {
        this->headValue = -1;
        this->values = vector<int>();
    }

    Sword(const std::string& filename) {
        std::vector<int> numbers;
        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string token;

            // Split by both ',' and ':'
            for (char& c : line) {
                if (c == ',' || c == ':') c = ' ';
            }

            std::stringstream parts(line);
            while (parts >> token) {
                numbers.push_back(std::stoi(token));
            }
        }

        this->headValue = numbers[0];
        for (int m = 1; m < numbers.size(); m++) {
            this->values.push_back(numbers[m]);
        }

    }

    std::vector<int> parseCommaNumbers(const std::string& input) {
        std::vector<int> values;

        // Make a copy so we can replace commas
        std::string cleaned = input;
        for (char& c : cleaned) {
            if (c == ',' || c == ':') c = ' ';
        }

        std::stringstream ss(cleaned);
        int num;
        while (ss >> num) {
            values.push_back(num);
        }

        return values;
    }


    void manuallyinsertData(string metaData) {
        //cout << "Inserting Data: " << metaData << endl;
        vector<int> data = parseCommaNumbers(metaData);
        this->headValue = data[0];
        for (int m = 1; m < data.size(); m++) {
            this->values.push_back(data[m]);
        }
        //for (int val : this->values) {
        //    cout << val << " ";
        //}   cout << endl;

    }

};

#endif /* SWORD_HH */