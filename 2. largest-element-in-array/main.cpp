/*

PROBLEM:
	Largest Element in Array

DEFINITION:
	This is the second easiest problem that you can think of. Just compare numbers

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

	// find the maximum
	int largestElmIndex = 0;
	for (int i = 1; i < n; ++i)
		if (a[largestElmIndex] < a[i])
			largestElmIndex = i;

	// print result
	cout << "Largest element in array is " << a[largestElmIndex] << " at index " << largestElmIndex << endl;

	return 0;
}

