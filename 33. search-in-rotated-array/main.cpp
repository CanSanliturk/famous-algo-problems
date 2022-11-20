#include <array>
#include <vector>
#include <iostream>

using namespace std;

int searchInRotatedArray(vector<int>& nums, int target) {
	int ans = -1;

	int left = 0;
	int right = nums.size() - 1;
	int mid = -1;

	while ( left <= right ) {

		mid = (left + right) / 2;

		if (nums[mid] == target)
			return mid;

		if (nums[left] <= nums[mid]) {
			if (target >= nums[left] && target <= nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else {
			if (target >= nums[mid] && target <= nums[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}

	return -1;
}

int main() {

	auto testCase = [](vector<int>&& nums, int target, int expected) {
		cout << "___________________________________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Input Array: ";
		for (auto i : nums)
			cout << " ";
		cout << endl;
		cout << "Target: " << target << endl;
		cout << "Expected Result: " << expected << endl; 
		auto ans = searchInRotatedArray(nums, target);
		cout << "Calculated Result: " << ans << endl;
		cout << "RESULT: " << (ans == expected ? "OK" : "NOT OK") << endl;;
		cout << endl << "___________________________________" << endl;
	};

	testCase({ 4, 5, 6, 7, 0, 1, 2 }, 0, 4);
	testCase({ 4, 5, 6, 7, 0, 1, 2 }, 3, -1);


	return 0;
}