#include <iostream>

using namespace std;

long countZeroes(int num) {

	if (!num)
		return 0;

	auto lastDigit = num - ((num / 10) * 10);
	return (lastDigit ? 0 : 1) + countZeroes((num - lastDigit) / 10);
}

int main() {

	long num;
	cout << "Enter Number: ";
	cin >> num;
	cout << "Number of Zeroes: " << countZeroes(num) << endl;

	return 0;
}