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

int findHighestGreedyApproach(const GRID &grid) {
	IgnitionList il = IgnitionList();
	int highest1 = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			IgnitionList blank = IgnitionList();
			int ignited = il.ingnitionPathAt(const_cast<GRID&>(grid), i, j, blank);
			if (ignited > highest1) {
				highest1 = ignited;
			}
		}
	}
	int highest2 = 0; /*
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (!il.exists(i, j)) {
				int ignited = il.ingnitionPathAt(const_cast<GRID&>(grid), i, j, il);
				if (ignited > highest2 && ignited < highest1) {
					highest2 = ignited;
				}
			}
		}
	} */
	int highest3 = 0; /*
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (!il.exists(i, j)) {
				int ignited = il.ingnitionPathAt(const_cast<GRID&>(grid), i, j, il);
				if (ignited > highest3 && ignited < highest2) {
					highest3 = ignited;
				}
			}
		}
	}
		*/
	cout << "Top three ignited counts: " << highest1 << ", " << highest2 << ", " << highest3 << endl;
	return (highest1 + highest2 + highest3);
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
	cout << "Example 3a Highest Greedy Ignited Cells: " << findHighestGreedyApproach(example3a) << endl;

	GRID example3b = readIntGrid("example3b.txt");
	cout << "Example 3b Highest Greedy Ignited Cells: " << findHighestGreedyApproach(example3b) << endl;

	return 0;
}



