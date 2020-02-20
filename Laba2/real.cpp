#include "real.h"

void read_file(string path, vector<string>& team, vector<int>& points, int& teamsCount) {
	int index = 0;
	string line;
	ifstream in(path);
	if (in.is_open()) {
		getline(in, line);
		teamsCount = stoi(line);
		while (getline(in, line)) {
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ',') {
					
				}
			}
		}
		in.close();
	}
	else {
		cout << "File wasn't open" << endl;
	}
}