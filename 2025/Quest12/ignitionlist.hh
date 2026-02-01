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
        x = 0; y = 0;
        nextItem = nullptr;
    }

    IgnitionList(int xCoord, int yCoord) {
        x = xCoord; y = yCoord;
        nextItem = nullptr;
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
private:
    int countItems() {
        if (nextItem == nullptr) { return 0;} 
        return 1 + nextItem->countItems();
    }               

    void addItem(int xCoord, int yCoord) {
        if (nextItem == nullptr) {
            nextItem = new IgnitionList(xCoord, yCoord);
        } else {
            nextItem->addItem(xCoord, yCoord);
        }           
    }

    bool complimentaryGridIsTheSame(vector<vector<int>>& grid, int x1, int y1) {
        int x2 = grid.size() -1 - x1;
        int y2 = grid[0].size() -1 - y1;
        return (grid[x1][y1] == grid[x2][y2]);

    }
    void routeIgnitionPath(vector<vector<int>>& grid, int x, int y, IgnitionList& il) {
        //cout << "Igniting cell: (" << x << ", " << y << ") with value " << grid[x][y] << endl;

        addItem(x,y);
    
        // Check all 4 directions
        const vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            // Check bounds
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()) {
                // Check if the cell is ignitable and not already in the list
                if ((grid[newX][newY] ==  grid[x][y] || grid[newX][newY] < grid[x][y] )&& !exists(newX, newY) && il.exists(newX, newY) == false) {
                    routeIgnitionPath(grid, newX, newY, il);
                }
            }
        }
    }

public:
    int routeIgnitionPath(std::vector<std::vector<int>>& grid, bool complimentary = false) {
       IgnitionList blank = IgnitionList();
       routeIgnitionPath(grid, 0, 0, blank);
       if (complimentary) {
           routeIgnitionPath(grid, grid.size() - 1, grid[0].size() - 1, blank);
       }
       return countItems();
    }
    
    int ingnitionPathAt(std::vector<std::vector<int>>& grid, int x, int y, IgnitionList il) {
       routeIgnitionPath(grid, x, y, il);
       return countItems();
    }

};

#endif // IGNITIONLIST_HH