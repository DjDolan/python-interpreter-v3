#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

void read_file(string txt, vector<string>& ins) {

	ifstream file_in;
	string line;

	file_in.open(txt);

	while(getline(file_in, line)) {
		if(line.empty()) continue;
		else
			ins.push_back(line);
	}

	file_in.close();

}