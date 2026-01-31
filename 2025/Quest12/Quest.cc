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

int main() {
	GRID example1 = readIntGrid("example1.txt");
	IgnitionList ex1 = IgnitionList();
	cout << "Example 1 Ignited Cells: " << ex1.routeIgnitionPath(example1) << endl;	

}



