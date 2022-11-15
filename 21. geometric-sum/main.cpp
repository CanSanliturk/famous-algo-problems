#include <cmath>
#include <iostream>

using namespace std;

double gsum(int k) {
	if (k == 0)
		return 1;

	return (1.0 / pow(2, k)) + gsum(k - 1);
}

int main() {

	cout << "Enter the input: ";
	long input;
	cin >> input;
	cout << "G-Sum(" << input << ") = " << gsum(input) << endl;

	return 0;
}