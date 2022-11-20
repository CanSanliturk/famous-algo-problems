#include <string>
#include <iostream>

using namespace std;

void printSubs(string input, string output = "") {

	if (input.length() == 0)
	{
		cout << output << endl;
		return;
	}

	printSubs(input.substr(1), output + input[0]);
	printSubs(input.substr(1), output);
}

int main() {

	string input = "abc";
	printSubs(input);

	return 0;
}