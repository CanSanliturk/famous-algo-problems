/*

PROBLEM:
	Swap 2 Numbers

DEFINITION:
	Swap the values of two given numbers

COMPLEXITY:
	There are two solutions. Both work in constant time complexity, O(1). Space complexity is also constant
	for both of the approaches. However, whereas naive approach is creating a temporary variable, smarter
	approach only uses math without extra variable.


*/

#include <iostream>

using namespace std;

void naiveApproach(int first, int second) {
	auto temp = first;
	first = second;
	second = first;
	cout << "Swapping with naive approach, first is now " << first << " and second is " << second << endl;
}

void smarterApproach(int first, int second) {
	first += second;
	second = first - second;
	first -= second;
	cout << "Swapping with smarter approach, first is now " << first << " and second is " << second << endl;
}

int main() {

	// get input
	cout << "Enter the first variable: ";
	int first;
	cin >> first;

	cout << "Enter the first variable: ";
	int second;
	cin >> second;

	// call naive approach and smart approach
	naiveApproach(first, second);
	smarterApproach(first, second);

	return 0;
}

