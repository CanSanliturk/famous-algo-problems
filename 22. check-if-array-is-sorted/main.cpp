#include <vector>
#include <iostream>

using namespace std;

bool checkIfSorted(const vector<int>& vec, unsigned int idx = 0) {

	if (vec.size() < 2)
		return true;

	if (idx == (vec.size() - 1))
		return true;

	if (vec.at(idx) > vec.at(idx + 1))
		return false;

	return checkIfSorted(vec, idx + 1);
}

int main() {

	vector<int> vec { 1, 20, 3, 4, 5 };
	cout << "Array is " << (checkIfSorted(vec) ? "" : "NOT ") << "sorted" << endl;
	return 0;
}