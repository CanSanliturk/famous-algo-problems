#include <vector>
#include <iostream>

using namespace std;

#define NONE -123456

int majorityElement(const vector<int>& nums) {

	int ans = nums[0];
	int count = 1;

	for (int i = 1; i < nums.size(); ++i) {
		if (ans == nums[i]) {
			count++;
		}
		else {
			count--;
			if (count == 0)
			{
				ans = nums[i];
				count++;
			}
		}
	}

	return count < 1 ? NONE : ans;

}

int main() {


	auto testCase = [](vector<int>&& nums, int expected) {
		cout << "___________________________________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Input Array: ";
		for (auto i : nums)
			cout << " ";
		cout << endl;
		cout << "Expected Result: " << expected << endl; 
		auto ans = majorityElement(nums);
		cout << "Calculated Result: " << ans << endl;
		cout << "RESULT: " << (ans == expected ? "OK" : "NOT OK") << endl;;
		cout << endl << "___________________________________" << endl;
	};

	testCase({ 3, 2, 3 }, 3);
	testCase({ 2, 2, 1, 1, 1, 2, 2 }, 2);
	testCase({ 4, 7, 4, 4, 7, 4, 4, 4, 4, 3 }, 4);
	testCase({ 1, 1, 1, 2, 2, 2 }, NONE);

	return 0;
}