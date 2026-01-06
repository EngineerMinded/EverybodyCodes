#include <iostream>
#include <vector>
#include "Sword.hh"
#include "Fishbone.hh"
using namespace std;

#ifndef SWORDLIST_HH
#define SWORDLIST_HH 
class SwordList {
    public:
    vector<Sword> swords;
    vector<Fishbone> fishbones;
    SwordList() {
        this->swords = vector<Sword>();
        this->fishbones = vector<Fishbone>();
    }
    void add(Sword S) {
        this->swords.push_back(S);
        Fishbone F = Fishbone();
        F.add(S);
        this->fishbones.push_back(F);
    }

    void print() {
        for (int i = 0; i < this->swords.size(); i++) {
            cout << "Sword " << i+1 << ": Head Value = " << this->swords[i].headValue << ", Values = ";
            for (int val : this->swords[i].values) {
                cout << val << " ";
            }
            vector<long long> strengthValues = this->fishbones[i].getSwordStrengthValue();
            cout << "| Fishbone Straight Value = " ;
            for (long long sv : strengthValues) {
                cout << sv << " ";
            }
            cout << endl; 
        }
    }
};

#endif
