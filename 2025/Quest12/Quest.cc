// Wayne Mack
// Everybody Codes
// Quest12

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cctype>

#include "ignitionlist.hh"
using namespace std;

#define GRID vector<vector<int>>	

vector<vector<int>> readIntGrid(const string &path) {
	ifstream in(path);
	if (!in) throw runtime_error("failed to open file: " + path);

	vector<vector<int>> grid;
	string line;
	while (std::getline(in, line)) {
		vector<int> ve;
		for (char &c : line) {
			ve.push_back(c - '0');
		}
		grid.push_back(ve);
	}
	return grid;
}

int findHighestGreedyApproach(const GRID &grid, int rounds) {
	int total = 0;
	int highest = grid.size() * grid[0].size(); // minimum ignitable is starting cell only
	IgnitionList standing = IgnitionList();
	for (int m = 0; m < rounds; m++) {
		IgnitionList nextStanding = IgnitionList();
		int currentHighest = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (!standing.exists(i,j)) {
					IgnitionList il = standing.makeDuplicate();
					int ignited = il.ingnitionPathAt(const_cast<GRID&>(grid), i, j);
					if (ignited > currentHighest && ignited < highest) {
						currentHighest = ignited;
						nextStanding = il.makeDuplicate();
					}
				}
			}
		}
		highest = currentHighest;
		total += currentHighest;
		standing = nextStanding.makeDuplicate();
	}

	return total;
}

int main() {
	// PART ONE
	GRID example1 = readIntGrid("example1.txt");
	IgnitionList ex1 = IgnitionList();
	cout << "Example 1 Ignited Cells: " << ex1.routeIgnitionPath(example1) << endl;	

	GRID part1 = readIntGrid("part1.txt");
	IgnitionList p1 = IgnitionList();
	cout << "Part 1 Ignited Cells: " << p1.routeIgnitionPath(part1) << endl;

	// PART TWO
	GRID example2 = readIntGrid("example2.txt");
	IgnitionList ex2 = IgnitionList();
	cout << "Example 2 Ignited Cells: " << ex2.routeIgnitionPath(example2, true) << endl;

	GRID part2 = readIntGrid("part2.txt");
	IgnitionList p2 = IgnitionList();		
	cout << "Part 2 Ignited Cells: " << p2.routeIgnitionPath(part2, true) << endl;

	// PART THREE : GREEDY APPROACH
	GRID example3a = readIntGrid("example3a.txt");
	cout << "Example 3a Highest Greedy Ignited Cells: " << findHighestGreedyApproach(example3a,3) << endl;

	return 0;
}



