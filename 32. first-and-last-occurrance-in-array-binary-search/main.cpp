#include <array>
#include <vector>
#include <iostream>

using namespace std;

int getFirst(vector<int>& nums, int target) {

	int left = 0;
	int right = nums.size() - 1;
	int ans = -1;
	
	while ( left <= right ) {

		int mid = (left + right) / 2;

		if (nums[mid] == target) {
			ans = mid;
			// continue searching left part for the first occurance
			right = mid - 1;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}	

	return ans;
}

int getLast(vector<int>& nums, int target) {

	int left = 0;
	int right = nums.size() - 1;
	int ans = -1;
	
	while ( left <= right ) {

		int mid = (left + right) / 2;

		if (nums[mid] == target) {
			ans = mid;
			// continue searching right part for the last occurance
			left = mid + 1;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}	

	return ans;
}

array<int, 2> searchRange(vector<int>& nums, int target) {
	return { getFirst(nums, target), getLast(nums, target) };
} 

int main() {

	auto testCase = [](vector<int>&& nums, int target, array<int, 2>&& expected) {

		cout << "______________________________________________________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Input Array: ";
		for (auto i : nums)
			cout << " ";
		cout << endl;
		cout << "Target: " << target << endl;
		cout << "Expected First and Last Occurance Indices: " << expected[0] << ", " << expected[1] << endl;; 
		auto ans = searchRange(nums, target);
		cout << "Calculated First and Last Occurance Indices: " << ans[0] << ", " << ans[1] << endl;
		cout << "RESULT: ";
		if ((ans[0] == expected[0]) && (ans[1] == expected[1]))
			cout << "OK";
		else
			cout << "NOT OK";
		cout << endl << "______________________________________________________" << endl;

	};

	testCase({ 5, 7, 7, 8, 8, 10 }, 8, { 3, 4 });
	testCase({ 5, 7, 7, 8, 8, 10 }, 6, { -1, -1 });

	return 0;
}