/*

PROBLEM:
	Reverse Array

DEFINITION:
	Start from left end and right end, swap the values of indices. Increment left element index and decrement right element index.

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

	// print array
	cout << "Array before reverse: ";
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;

	// reverse the array
	int leftIndex = 0, rightIndex = n - 1;
	while ( leftIndex < rightIndex) {
		a[leftIndex] += a[rightIndex];
		a[rightIndex] = a[leftIndex] - a[rightIndex];
		a[leftIndex] -= a[rightIndex];

		++leftIndex;
		--rightIndex;
	}

	// print the reversed array
	cout << "Array after reverse: ";
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}

