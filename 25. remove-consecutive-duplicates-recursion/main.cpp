#include <string>
#include <iostream>

using namespace std;

void removeConsecutiveDuplicates(string& input, unsigned int currIndex = 0) {

	if (currIndex == input.length() - 1)
		return;

	if (input.at(currIndex) != input.at(currIndex + 1))
	{
		currIndex++;
		removeConsecutiveDuplicates(input, currIndex);
	}

	else {

		auto firstPart = input.substr(0, currIndex);
		auto secondPart = input.substr(currIndex + 1);
		input = firstPart + secondPart;
		removeConsecutiveDuplicates(input, currIndex);
	}
}

int main() {

	auto testAndLog = [&](string input, string expectedOutput) {
		cout << "_________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Input: " << input << endl;
		cout << "Expected Output: " << expectedOutput << endl;
		removeConsecutiveDuplicates(input, 0);
		cout << "Actual Output: " << input << endl;
		cout << "Result: " << (input == expectedOutput ? "" : "NOT ") << "OK" << endl;
		cout << "____________" << endl;
	};

	testAndLog("aabbbcdda", "abcda");
	testAndLog("aaaa", "a");
	testAndLog("abcdef", "abcdef");

	return 0;
}