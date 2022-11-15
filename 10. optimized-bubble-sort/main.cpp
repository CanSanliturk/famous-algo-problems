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
void opitimizedBubbleSort(vector<T>& vec, function<bool(T, T)> func) {
	
	for (int i = 0; i < vec.size() - 1; ++i) {

		auto flag = false;
		for (int j = i + 1; j < vec.size(); ++j) {
			if (func(vec[j], vec[i])) {
				swap(vec[i], vec[j]);
				flag = true;
			}
		}

		if (!flag)
			break;
	}
}

int main() {

	vector<int> vec { 3, 4, 7, 1, 10 };
	
	cout << "Before sorting: ";
	printVector(vec);
	opitimizedBubbleSort<int>(vec, [](int a, int b) { return a < b; });
	
	cout << "After sorting: ";
	printVector(vec);
	
	return 0;
}