#include <iostream>
#include <string>
#include <vector>

using namespace std;

int evaluate_expression(string exp) {

	int res = 0;

	if(exp.find('+') != string::npos
	|| exp.find('-') != string::npos
	|| exp.find('*') != string::npos
	|| exp.find('/') != string::npos) {
		cout << "need to evaluate expression" << endl;
		return 1;
	}
	else {
		cout << "do not need to evaluate expression" << endl;
		return 2;
	}

}

void process_assignment(string line, vector<string>& var, vector<int>& ints) {

	string new_line;
	string variable;
	string expression;
	int val;

	//clean line
	for(int i = 0; i < line.length(); i++) {
		if(line[i] == ' ') continue;
		else new_line += line[i];
	}

	if(new_line.find('=') != string::npos) {
		int pos = new_line.find('=');

		variable = new_line.substr(0, pos);

		expression = new_line.substr(pos+1, line.find('\n'));

		evaluate_expression(expression);
	}
	else {
		cerr << "does not have assignment operator" << endl;
		exit(1);
	}

}