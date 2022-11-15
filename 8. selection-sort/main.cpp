#include <vector>
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
void printVector(vector<T>& vec) {
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
}

template <typename T>
void selectionSort(vector<T>& vec, function<bool(T, T)> func) {

	for (int currIndex = 0; currIndex < vec.size() - 1; ++currIndex) {
		
		auto rhsMinIndex = currIndex + 1;
		for (int i = rhsMinIndex + 1; i < vec.size(); ++i) 
			if (func(vec[i], vec[rhsMinIndex]))
				rhsMinIndex = i;

		if (func(vec[rhsMinIndex], vec[currIndex]))
			swap(vec[rhsMinIndex], vec[currIndex]);
	}
}

int main() {

	vector<int> vec { 4, 5, 3, 1, 2 };
	
	cout << "Before sorting: ";
	printVector(vec);
	selectionSort<int>(vec, [](int a, int b) { return a < b; });
	
	cout << "After sorting: ";
	printVector(vec);
	
	return 0;
}