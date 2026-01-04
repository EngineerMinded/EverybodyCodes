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
private:
    int power(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

    long long _getStraightValue(long long accumulated) {
        int exponent = 1, counter = this->value;
        while (counter > 9) {
            exponent++;
            counter /= 10;
        }
        accumulated = (accumulated * (power(10,exponent))) + this->value;
        if (this->next != nullptr) {
            return this->next->_getStraightValue(accumulated);
        } else {
            return accumulated;
        }
    }
public:
    long long getStraightValue() {
        return _getStraightValue(0);
    }

    void print() {
        cout << "Value: " << this->value << ", Left: " << this->left << ", Right: " << this->right << endl;
        if (this->next != nullptr) {
            this->next->print();
        }
    }   

};

#endif /* FISHBONE_HH */