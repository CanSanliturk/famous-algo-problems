#include <iostream>

using namespace std;

unsigned int fib(unsigned int n) {
	return (n < 2) ? 1 : fib(n - 1) + fib(n - 2);
}

int main() {

	auto calcAndLog = [](int n) { 
		cout << "fib(" << n << " ) = " << fib(n) << endl;
	};

	for (int i = 0; i <= 10; ++i)
		calcAndLog(i);

	return 0;
}