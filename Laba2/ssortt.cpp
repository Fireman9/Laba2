#include<iostream>
#include<vector>
#include<string>

using namespace std;

int maxEl(vector<int> points, int a, int b);

void ssort(vector<string> team, vector<int> points) {
	int a = points.size();
	int b, c, d;
	string commands1, commands2;
	for (int i = 0;  i < a;  i++)
	{
		b = points[i];
		c = maxEl(points, i, a);
		d = points[c];
		swap(b, d);
		commands1 = team[i];
		commands2 = team[c];
		swap(commands1, commands2);
	}
}

int maxEl(vector<int> points, int a, int b) {
	int max = points[a];
	int indexMax = a;
	for (int i = a; i < b; i++)
	{
		if (max<points[i])
		{
			max = points[i];
			indexMax = i;
		}
	}
	return indexMax;
}
