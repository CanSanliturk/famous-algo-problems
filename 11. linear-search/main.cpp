#include <tuple>
#include <iostream>

using namespace std;

template <typename T>
tuple<bool, unsigned int> findIndexUsingLinearSearch(T* arr, unsigned int size, T target) {
	for (unsigned int i = 0; i < size; ++i)
		if (arr[i] == target)
			return { true, i };
	return { false, 0 };
}


int main() {

	int arr[] = { 1, 3, 5, 7, 9 };

	auto findAndLog = [&](int target) {
		cout << "Target is " << target;
		auto res = findIndexUsingLinearSearch(arr, sizeof(arr) / sizeof(int), target);
		if (get<0>(res))
			cout << " and it is found at index " << get<1>(res);
		else
			cout << " and it could not be found";
		cout << endl;
	};

	findAndLog(2);
	findAndLog(3);

	return 0;
}