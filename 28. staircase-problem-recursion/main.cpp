#include <iostream>

using namespace std;

int numOfWays(int n) {

	if (n < 0)
		return 0;

	if (n < 2)
		return 1;

	return numOfWays(n - 1) + numOfWays(n - 2) + numOfWays(n - 3);
}

int main() {

	auto testAndLog = [](int n) {
		cout << "_________" << endl;
		cout << "TEST CASE" << endl;
		cout << "INPUT: " << n << endl;
		cout << "RESULT: " << numOfWays(n) << endl;
		cout << "_________" << endl;
	};

	testAndLog(3);
	testAndLog(4);

	return 0;
}