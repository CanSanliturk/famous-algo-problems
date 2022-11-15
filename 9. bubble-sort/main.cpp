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
void bubbleSort(vector<T>& vec, function<bool(T, T)> func) {
	for (int i = 0; i < vec.size() - 1; ++i)
		for (int j = i + 1; j < vec.size(); ++j)
			if (func(vec[j], vec[i]))
				swap(vec[i], vec[j]);
}

int main() {

	vector<int> vec { 5, 4, 3, 1, 2 };
	
	cout << "Before sorting: ";
	printVector(vec);
	bubbleSort<int>(vec, [](int a, int b) { return a < b; });
	
	cout << "After sorting: ";
	printVector(vec);
	
	return 0;
}