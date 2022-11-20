#include <vector>
#include <iostream>

using namespace std;

void printVector(const vector<int>& arr) {
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
}

vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
	vector<int> merged;

	unsigned int smallerSize = min(arr1.size(), arr2.size());
	unsigned int firstIndex = 0, secondIndex = 0;

	while ((firstIndex < arr1.size()) && (secondIndex < arr2.size())) {
		auto elemFromFirstArray = arr1[firstIndex];
		auto elemFromSecondArray = arr2[secondIndex];

		if (elemFromFirstArray < elemFromSecondArray) {
			merged.push_back(elemFromFirstArray);
			firstIndex++;
		}
		else {
			merged.push_back(elemFromSecondArray);
			secondIndex++;
		}
	}

	while (firstIndex < arr1.size()) {
		merged.push_back(arr1[firstIndex]);
		firstIndex++;
	}

	while (secondIndex < arr2.size()) {
		merged.push_back(arr2[secondIndex]);
		secondIndex++;
	}

	return merged;
}

void quickSort(vector<int>& arr) {

	if (arr.size() < 2)
		return;

	vector<int> smaller, larger;
	for (int i = 0; i < arr.size() - 1; ++i) {
		if (arr[i] < arr[arr.size() - 1])
			smaller.push_back(arr[i]);
		else
			larger.push_back(arr[i]);
	}

	quickSort(smaller);
	quickSort(larger);
	smaller.push_back(arr[arr.size() - 1]);
	arr = mergeSortedArrays(smaller, larger);
}

int main() {

	vector<int> arr { 2, 5, 1, 6, 6, 3, 10 };
	quickSort(arr);
	printVector(arr);

	return 0;
}