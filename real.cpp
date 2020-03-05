#include "real.h"

void read_file(string path, vector<string>& team, vector<int>& points) {
	int point = 0, index = 0, teamsCount;
	double t1, t2;
	string line, teamName, goals1, goals2;
	ifstream in(path);
	int lapki = 0;
	if (in.is_open()) {
		getline(in, line);
		teamsCount = stoi(line);
		while (getline(in, line)) {
			line += ',';
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == '"') {
					lapki++; 
				}
				if (lapki % 2 == 0) {
					if (line[i] == ',') {
						if (index == 0) {
							teamName.assign(line, index, i - index);
							for (int j = 0; j < teamName.size(); j++)
							{
								if (teamName[j] == '"')
								{
									teamName.erase(j, j + 1);
								}
							}
							team.push_back(teamName);
							index = i;
						}
						else {
							for (int f = index; f < i; f++) {
								if (line[f] == ':') {
									goals1.assign(line, index + 1, f - index - 1);
									goals2.assign(line, f + 1, i - f - 1);
									break;
								}
							}
							t1 = stod(goals1);
							t2 = stod(goals2);
							if (t1 > t2)point += 3;
							else if (t1 == t2)point++;
							index = i;
						}
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