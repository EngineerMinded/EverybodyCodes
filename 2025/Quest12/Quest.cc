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
using namespace std;

vector<vector<int>> readIntGrid(const string &path) {
	ifstream in(path);
	if (!in) throw runtime_error("failed to open file: " + path);

	vector<vector<int>> grid;
	string line;
	while (std::getline(in, line)) {
		bool all_ws = true;
		for (char c : line) if (!isspace((unsigned char)c)) { all_ws = false; break; }
		if (all_ws) continue;

		istringstream iss(line);
		vector<int> row;
		int val;
		while (iss >> val) row.push_back(val);
		if (!row.empty()) grid.push_back(move(row));
	}
	return grid;
}



