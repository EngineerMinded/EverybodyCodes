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
	int total = 0; int highestOverall = grid.size() * grid[0].size();
	IgnitionList roundList = IgnitionList();
	for (int r = 0; r < rounds; r++) {
		IgnitionList bestThisRound = roundList.makeDuplicate();
		int highestThisRound = 0;
		for (int x = 0; x < grid.size(); x++) {
			for (int y = 0; y < grid[0].size(); y++) {
				if (!roundList.exists(x,y)) {
					//cout << "Testing ignition at (" << x << "," << y << ") ROUND: " << r << endl;
					IgnitionList testList = roundList.makeDuplicate();
					int ignited = testList.ingnitionPathAt(const_cast<GRID&>(grid), x, y);
					if (ignited > highestThisRound) {
						highestThisRound = ignited;
						bestThisRound = testList;
					}
				}
			}
		}
		roundList = bestThisRound.makeDuplicate();
		//roundList.printList();
		total = highestThisRound;
		highestOverall = highestThisRound;
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

	GRID example3b = readIntGrid("example3b.txt");
	cout << "Example 3b Highest Greedy Ignited Cells: " << findHighestGreedyApproach(example3b,3) << endl;

	GRID part3 = readIntGrid("part3.txt");
	cout << "GRAB A COFFEE... THIS ONE TAKES A WHILE TO RUN..." << endl;
	cout << "Part 3 Highest Greedy Ignited Cells: " << findHighestGreedyApproach(part3,3) << endl;

	return 0;
}



