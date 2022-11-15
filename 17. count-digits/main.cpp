#include <iostream>

using namespace std;

int count(long number) {
	return number ? 1 + count(number /= 10) : 0;
}

int main() {

	long number;
	cout << "Number: ";
	cin >> number;
	cout << "Number of Digits: " << count(number) << endl;

	return 0;
}