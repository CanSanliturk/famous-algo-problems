/*

PROBLEM:
	Reverse the string
*/

#include <iostream>

using namespace std;

int getLength(char* input) {
	auto count = 0;
	while (input[count] != '\0')
		count++;
	return count;
}

void reverse(char* input) {
	auto left = 0;
	auto right = getLength(input) - 1;
	while (left < right) {
		swap(input[left], input[right]);
		left++;
		right--;
	}
}

int gcd(unsigned int a, unsigned int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {

/*
	cout << "Enter the string: ";
	char input[100];
	cin.getline(input, 100);
	::reverse(input);
	cout << "Reversed string: " << input << endl;
*/

	uint32_t a = 16, b = 24;
	cout << "gcd: " << gcd(a, b) << endl;

	return 0;
}

