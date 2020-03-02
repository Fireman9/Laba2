#include <boost/filesystem.hpp> 
#include "real.h"
#include "ssortt.h"

using namespace boost::filesystem;

int main() {
	string filepath;
	vector<string> team;
	vector<int> points;
	string result;
	getline(cin, filepath);
	path direct = filepath;
	for (directory_iterator it(direct), end; it != end; ++it) {
		if (it->path().extension() == ".csv") {
			read_file(it->path().string(), team, points);
		}
	}
	ssort(team, points);
	cout << " Enter name of fail for writing to a CSV fail, in the format 'name.csv' : ";
	getline(cin, result);
	cout << endl;
	outputResult(team, points, result);
	return 0;
}