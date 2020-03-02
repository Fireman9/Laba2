#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

int findMaxIndex(vector<int>& points, int a, int b);

void ssort(vector<string>& team, vector<int>& points) {
	int maxIndex;
	string commands1, commands2;
	for (int i = 0;  i < points.size();  i++) {
		maxIndex = findMaxIndex(points, i, points.size());
		swap(points[i], points[maxIndex]);
		swap(team[i], team[maxIndex]);
	}
}

int findMaxIndex(vector<int>& points, int curIndex, int size) {
	int maxEl = points[curIndex];
	int indexMax = curIndex;
	for (int i = curIndex; i < size; i++) {
		if (maxEl < points[i]) {
			maxEl = points[i];
			indexMax = i;
		}
	}
	return indexMax;
}

void outputResult(vector<string>& team, vector<int>& points) {
	ofstream out("result.csv");
	if (out.is_open()) {
		for (int i = 0; i < team.size(); i++) {
			out << team[i] << "," << points[i] << endl;
		}
		out.close();
	}
	else {
		cout << "File wasn't created" << endl;
	}
}
