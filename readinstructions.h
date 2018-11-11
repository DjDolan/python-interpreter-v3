#include <iostream>
#include <vector>
#include "ifstatements.h"
#include "assignment.h"

using namespace std;

void parse_if_statement(vector<string>& ins, vector<string>& ifs, vector<string>& var, vector<int>& ints) {

	//base case
	//something to signify end of if statement
	if((ins[0][0] != ' ') && (ins[0][1] != ' ') && (ins[0][2] != ' ')) {
		return;
	}
	else {
		ifs.push_back(ins[0]);
		ins.erase(ins.begin());
		parse_if_statement(ins, ifs, var, ints);
	}
}

void read_instructions(vector<string>& ins, vector<string>& var, vector<int>& ints, vector<string>& ifs, vector<string>& defs) {

	//base case
	//if there are no more instructions
	if(ins.empty()) {
		return;
	}

	//if its an if statement then parse
	else if(ins[0].find("if") != string::npos) {
		ifs.push_back(ins[0]);
		ins.erase(ins.begin());
		parse_if_statement(ins, ifs, var, ints);
		process_ifs(ifs);
		read_instructions(ins, var, ints, ifs, defs);
	}
	//if its an assignment then perform assignment
	else if(ins[0].find("=") != string::npos) {
		process_assignment(ins[0], var, ints);
		ins.erase(ins.begin());
		read_instructions(ins, var, ints, ifs, defs);
	}

	else {
		ins.erase(ins.begin());
		read_instructions(ins, var, ints, ifs, defs);
	}

} 