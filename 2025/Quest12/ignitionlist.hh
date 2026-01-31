// ignitionList.hh
#include <vector>
#include <iostream>
using namespace std;

#ifndef IGNITIONLIST_HH
#define IGNITIONLIST_HH

class IgnitionList {
public:
    int x, y;
    IgnitionList* nextItem;

    IgnitionList() {
        x = 0;
        y = 0;
        nextItem = nullptr;
    }

    IgnitionList(int xCoord, int yCoord) {
        x = xCoord;
        y = yCoord;
        nextItem = nullptr;
    }

    void addItem(int xCoord, int yCoord) {
        if (nextItem == nullptr) {
            nextItem = new IgnitionList(xCoord, yCoord);
        } else {
            nextItem->addItem(xCoord, yCoord);
        }           
    }

    bool exists(int xCoord, int yCoord) {
        if (x == xCoord && y == yCoord) {
            return true;
        } else if (nextItem != nullptr) {
            return nextItem->exists(xCoord, yCoord);
        } else {
            return false;
        }
    }   

    void routeIgnitionPath(vector<vector<int>>& grid, int x, int y) {
        
    }
    void routeIgnitionPath(std::vector<std::vector<int>>& grid) {
       routeIgnitionPath(grid, 0, 0);
    }
    
    
};

#endif // IGNITIONLIST_HH