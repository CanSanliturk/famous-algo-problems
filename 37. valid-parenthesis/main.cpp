#include <unordered_map>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool isBalanced(const string& input) {

	unordered_map<char, char> matcher {
		{ ')', '(' },
		{ '}', '{' },
		{ ']', '[' }
	};

	stack<char> stck;

	for (auto c : input)
		if ((matcher.find(c) != matcher.end()) && (stck.top() == matcher[c]) && !stck.empty())
			stck.pop();
		else
			stck.push(c);

	return stck.empty();
}

int main() {

	auto testCase = [](const string&& input, bool expected) {
		cout << "_______________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Input: " << input << endl;
		cout << "Expected: " << (expected ? "Balanced" : "Not Balanced") << endl;
		auto ans = isBalanced(input);
		cout << "Calculated: " << (ans ? "Balanced" : "Not Balanced") << endl;
		cout << "Result: " << (ans == expected ? "OK" : "NOT OK") << endl;
		cout << "_______________" << endl;
	};

	testCase("()", true);
	testCase("(())", true);
	testCase("{(([]))}", true);
	testCase("{([]))}", false);
	testCase("", true);

	return 0;
}