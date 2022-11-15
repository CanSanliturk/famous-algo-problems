#include <iostream>

using namespace std;

long multiply(int num1, int num2) {

	if (num2 == 0)
		return 0;

	return num1 + multiply(num1, num2 - 1);
}

int main() {

	long num1, num2;
	cout << "First Number: ";
	cin >> num1;
	cout << "Second Number: ";
	cin >> num2;
	cout << "Multiplication: " << multiply(num1, num2) << endl;

	return 0;
}