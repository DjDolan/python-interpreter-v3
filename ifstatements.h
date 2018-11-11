#include <iostream>
#include <stdlib.h>

using namespace std;

void process_ifs(vector<string> ifs) {

	if(ifs.empty()) {
		return;
	}

	else {
		//perform actions on each instruction of if
		ifs.erase(ifs.begin());
		process_ifs(ifs);
	}
}