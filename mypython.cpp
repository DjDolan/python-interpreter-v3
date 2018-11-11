#include <iostream>
#include <stdlib.h>
#include <vector>
#include "readfile.h"
#include "readinstructions.h"

using namespace std;

int main(int argc, char** argv) {

	string text = "code.py";

	vector<string> instructions;
	vector<int> integers;
	vector<string> variables;
	vector<string> if_statement;
	vector<string> def_function;

	read_file(text, instructions);

	read_instructions(instructions, variables, integers, if_statement, def_function);

	return 0;
}