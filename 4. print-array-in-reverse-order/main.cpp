/*

PROBLEM:
	Print Array in Reverse Order

DEFINITION:
	Is it getting even easier?

COMPLEXITY:
	Just start traversing from the end, no space required and time is linear
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

	// print in order
	cout << "In order: ";
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;

	// print in reverse order
	cout << "In reverse order: ";
	for (int i = n - 1; -1 < i; --i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
