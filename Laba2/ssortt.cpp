#include<iostream>
#include<vector>
#include<string>

using namespace std;

int maxEl(vector<int> points, int a, int b);

void ssort(vector<string> team, vector<int> points) {
	int a = points.size();
	int b, c, d;
	for (int i = 0;  i < a;  i++)
	{
		
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