#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> sortKSortedArrayInDecreasingOrder(vector<int>& original, int k) {

	// k sorted array means that elements are at most k - 1 index away from
	// the position they should actually be in sorted array. aim is to sort
	// such an array. first approach is simply using in-built sort, which
	// nlogn. instead, do something smarter
	priority_queue<int> pq;

	for (auto i : original)
		pq.push(i);

	int s = 0;
	for (int i = k; i < original.size(); ++i) {
		original[s] = pq.top();
		pq.pop();
		s++;
		pq.push(original[i]);
	}

	while (!pq.empty()) {
		original[s] = pq.top();
		pq.pop();
		s++;
	}
	
	return original;
}

int main() {

	auto printVec = [](vector<int>& vec) {
		for (auto i : vec)
			cout << i << " ";
		cout << endl;
	};

	auto testCase = [&printVec](vector<int>&& vec, int k) {
		cout << "_____________________________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Input: ";
		printVec(vec);
		cout << "Actual Output: ";
		auto actual = sortKSortedArrayInDecreasingOrder(vec, k);
		printVec(actual);
		sort(vec.begin(), vec.end(), [](int a, int b){ return a > b; });
		cout << "Expected Output: ";
		printVec(vec);
		auto res = true;
		for (int i = 0; i < actual.size(); ++i) {
			if (actual.at(i) != vec.at(i)) {
				res = false;
				break;
			}
		}
		cout << "Result: " << (res ? "OK" : "NOT OK") << endl;
		cout << "_____________________________" << endl;
	};

	testCase({ 12, 7, 5, 9, 4 }, 3);

	return 0;
}