#include <iostream>

using namespace std;

int powFunction(int base, int power) {
	if (power == 1)
		return base;

	if (base == 0)
		return 1;

	return base * powFunction(base, power - 1);
}

int main() {

	auto calcAndLog = [](int base, int power) { 
		cout << base << "^" << power << " = " << powFunction(base, power) << endl; 
	};

	calcAndLog(2, 3);

	return 0;
}