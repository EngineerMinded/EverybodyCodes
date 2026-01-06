#include <iostream>
#include "Sword.hh"
using namespace std;

#ifndef FISHBONE_HH
#define FISHBONE_HH 

class Fishbone {
    int value;
    int left;
    int right;
    Fishbone* next;
public:
    Fishbone() {
        this->value = -1;
        this->left = -1;
        this->right = -1;
        this->next = nullptr;
    }
    Fishbone(int value) {
        this->value = value;
        this->left = -1;
        this->right = -1;
        this->next = nullptr;
    }
    void add(Sword S) {
        for (int val : S.values) {
            this->add(val);
        }
    }
    void add(int newValue) {
        if (this->value == -1) {
            this->value = newValue;
            return;
        }
        if (newValue < this->value) {
            if (this->left == -1) {
                this->left = newValue;
            } else {
                if (this->next == nullptr) {
                    this->next = new Fishbone(newValue);
                } else {
                    this->next->add(newValue);
                }
            }
        } else if (newValue > this->value) {
            if (this->right == -1) {
                this->right = newValue;
            } else {
                if (this->next == nullptr) {
                    this->next = new Fishbone(newValue);
                } else {
                    this->next->add(newValue);
                }
            }
        } else if(newValue == this->value) {
            if (this->next == nullptr) {
                this->next = new Fishbone(newValue);
            } else {
                this->next->add(newValue);
            }
        }
    }

    int isBetterThan(Fishbone other) {
        vector<long long> myValues = this->getSwordStrengthValue();
        vector<long long> otherValues = other.getSwordStrengthValue();
        // Step 1: Determine by longer length
        if (myValues.size() > otherValues.size()) return 1;
        if (myValues.size() < otherValues.size()) return 0;
        // Step 2: If lengths are equal, compare straight values
        long long myStraight = this->getStraightValue();
        long long otherStraight = other.getStraightValue();
        if (myStraight > otherStraight) return 1;
        if (myStraight < otherStraight) return 0;
        // Step 3: Compare values one by one
        for (int i = 0; i < min(myValues.size(), otherValues.size()); i++) {
            if (myValues[i] > otherValues[i]) return 1;
            if (myValues[i] < otherValues[i]) return 0;
        }
        // at this point they are equal and neither is better
        return 1;
    }
private:
    int power(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

    long long accumulatedNumber(long long currentValue, long long next) {
        int exponent = 1, counter = next;
        while (counter > 9) {
            exponent++;
            counter /= 10;
        }   
        return (currentValue * (power(10,exponent))) + next;
    }

    long long getStraightValue(long long accumulated) {
        accumulated = accumulatedNumber(accumulated, this->value);
        if (this->next != nullptr) {
            return this->next->getStraightValue(accumulated);
        } else {
            return accumulated;
        }
    }

    void getSwordStrengthValue(vector<long long>& values) {
        long long currentValue = 0;
        if (this->left != -1) currentValue = accumulatedNumber(currentValue, this->left);
        if (this->value != -1) currentValue = accumulatedNumber(currentValue, this->value);
        if (this->right != -1) currentValue = accumulatedNumber(currentValue, this->right);
        values.push_back(currentValue);
        if (this->next != nullptr) this->next->getSwordStrengthValue(values);
    }

public:
    long long getStraightValue() {
        return getStraightValue(0);
    }

    vector <long long> getSwordStrengthValue() {
        vector<long long> values;
        getSwordStrengthValue(values);
        return values;
    }

    void print() {
        cout << "Value: " << this->value << ", Left: " << this->left << ", Right: " << this->right << endl;
        if (this->next != nullptr) {
            this->next->print();
        }
    }   
};

#endif /* FISHBONE_HH */