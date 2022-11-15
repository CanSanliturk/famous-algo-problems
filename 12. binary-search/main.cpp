#include <tuple>
#include <iostream>
#include <functional>

using namespace std;

int findIndexUsingBinarySearch(int* arr, unsigned int size, int target) {

	int left = 0, right = size - 1, mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (arr[mid] == target)
			return mid;
		
		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;

	}

	return -1;
}


int main() {

	int arr[] = { 1, 3, 5, 7, 9 };

	auto findAndLog = [&](int target) {
		cout << "Target is " << target;
		auto res = findIndexUsingBinarySearch(arr, sizeof(arr) / sizeof(int), target);
		if (res != -1)
			cout << " and it is found at index " << res;
		else
			cout << " and it could not be found";
		cout << endl;
	};

	findAndLog(2);
	findAndLog(3);

	return 0;
}