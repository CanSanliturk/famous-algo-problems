/*

PROBLEM:
	Sum of the Elements in an Array

DEFINITION:
	This is the easiest problem that you can think of. Sum of the integers in an array. No easy way, just go and sum them.

COMPLEXITY:
	For this solution, space complexity is O(1) and time complexity is O(n)

*/

#include <iostream>

using namespace std;

int main() {

	// get array as input from the user via command line
	cout << "Enter the number of the elements ";
	int n;
	cin >> n;

	// validate the input
	if (n < 0) {
		cout << "n should be positive..." << endl;
		return 0;
	}

	if (n > (((1 << 30) - 1) << 1)) {
		cout << "n is out of bound..." << endl;
		return 0;
	}

	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	// sum the elements
	long sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i];

	// print result
	cout << "Sum of the elements: " << sum << endl;

	return 0;
}

