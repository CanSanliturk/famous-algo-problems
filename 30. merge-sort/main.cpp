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

void mergeSort(vector<int>& arr) {

	if (arr.size() < 2)
		return;

	vector<int> firstPart, secondPart;
	for (int i = 0; i < arr.size() / 2; ++i)
		firstPart.push_back(arr[i]);

	for (int i = arr.size() / 2; i < arr.size(); ++i)
		secondPart.push_back(arr[i]);

	mergeSort(firstPart);
	mergeSort(secondPart);
	auto merged = mergeSortedArrays(firstPart, secondPart);
	arr = merged;
}

int main() {

	vector<int> arr { 2, 5, 1, 6, 6, 3, 10 };
	mergeSort(arr);
	printVector(arr);

	return 0;
}
