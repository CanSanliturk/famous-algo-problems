#include <iostream>

using namespace std;

unsigned int fact(unsigned int n) {
	return (n < 2) ? 1 : n * fact(n - 1);
}

int main() {

	auto calcAndLog = [](int n) { 
		cout << "Input is " << n << " and n! = " << fact(n) << endl;
	};

	for (int i = 0; i <= 10; ++i)
		calcAndLog(i);

	return 0;
}