#include <iostream>
#include "real.h"

int main() {
	int teamsCount;
	string filepath;
	vector<string> team;
	vector<int> points;
	getline(cin, filepath);
	read_file(filepath, team, points, teamsCount);
	return 0;
}