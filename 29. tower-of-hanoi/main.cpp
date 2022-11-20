#include <cmath>
#include <iostream>

using namespace std;

#define LOG(x)  cout << x << endl

int numOfSteps(int n) {

	if (n < 1)
		return 0;

	return numOfSteps(n - 1) + 1 + numOfSteps(n - 1);
}



int main() {


	auto testAndLog = [](int input) {
		LOG("_________");
		LOG("TEST CASE");
		LOG("INPUT: " << input);
		LOG("EXPECTED OUTPUT: " << ((int)pow(2, input)) - 1);
		LOG("ACTUAL OUTPUT: " << numOfSteps(input));
		LOG(((((int)pow(2, input)) - 1) == numOfSteps(input) ? "OK" : "NOT OK"));
		LOG("_____");
	};

	testAndLog(1);
	testAndLog(2);
	testAndLog(3);
	testAndLog(4);
	testAndLog(5);


	return 0;
}