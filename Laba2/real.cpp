#include "real.h"

void read_file(string path, vector<string>& team, vector<int>& points, int& teamsCount) {
	int point = 0, t1, t2, index = 0;
	string line, teamName, goals1, goals2;
	ifstream in(path);
	if (in.is_open()) {
		getline(in, line);
		teamsCount = stoi(line);
		while (getline(in, line)) {
			line += ',';
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ',') {
					if (index == 0) {
						teamName.assign(line, index, i - index);
						team.push_back(teamName);
						index = i;
					}
					else {
						goals1.assign(line, index + 1, 1);
						goals2.assign(line, index + 3, 1);
						t1 = stoi(goals1);
						t2 = stoi(goals2);
						if (t1 > t2)point += 3;
						else if (t1 == t2)point++;
						index = i;
					}
				}
			}
			points.push_back(point);
			index = 0, point = 0;
		}
		in.close();
	}
	else {
		cout << "File wasn't open" << endl;
	}
}