#include <iostream>

using namespace std;

long sumOfDigits(long number) {

	if (!number)
		return 0;

	auto lastDigit = number - (((long)(number / 10)) * 10);
	return lastDigit + sumOfDigits((number - lastDigit) / 10);
}

int main() {

	long number;
	cout << "Number: ";
	cin >> number;
	cout << "Sum of Digits: " << sumOfDigits(number) << endl;

	return 0;
}