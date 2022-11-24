#include <stack>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

string removeAdjacentDuplicates(const string& input) {

	stack<pair<char, int>> chars;

	for (int i = 0; i < input.length(); ++i) {

		auto currChar = input.at(i);

		if (chars.empty() || (chars.top().first != currChar))
			chars.push({ currChar, i });
		else
			chars.pop();
	}

	stack<char> reverse;
	while (!chars.empty()) {
		reverse.push(chars.top().first);
		chars.pop();
	}

	ostringstream oss;
	while (!reverse.empty()) {
		oss << reverse.top();
		reverse.pop();
	}

	return oss.str();	
}

int main() {

	auto testCase = [](const string&& input, const string&& expected) {
		cout << "_______________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Input: " << input << endl;
		cout << "Expected: " << expected << endl;
		auto ans = removeAdjacentDuplicates(input);
		cout << "Calculated: " << ans << endl;
		cout << "Result: " << (ans == expected ? "OK" : "NOT OK") << endl;
		cout << "_______________" << endl;
	};

	testCase("aab", "b");
	testCase("aaabccddd", "abd");
	testCase("aa", "");
	testCase("baab", "");
	testCase("mississippi", "m");

	return 0;
}
