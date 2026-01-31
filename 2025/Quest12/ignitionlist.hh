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
private:
    int countItems() {
        if (nextItem == nullptr) {
            return 0;
        } else {
            return 1 + nextItem->countItems();
        }
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
        cout << "Igniting cell: (" << x << ", " << y << ") with value " << grid[x][y] << endl;
        addItem(x,y);
        // Check all 4 directions
        const vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            // Check bounds
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()) {
                // Check if the cell is ignitable and not already in the list
                if ((grid[newX][newY] ==  grid[x][y] || grid[newX][newY] < grid[x][y] )&& !exists(newX, newY)) {
                    routeIgnitionPath(grid, newX, newY);
                }
            }
        }
    }
public:
    int routeIgnitionPath(std::vector<std::vector<int>>& grid) {
       routeIgnitionPath(grid, 0, 0);
       return countItems();
    }
    
    
};

#endif // IGNITIONLIST_HH