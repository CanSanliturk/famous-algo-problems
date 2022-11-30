#include <iostream>

using namespace std;

// each time, we can climb 1 or 2 stairs. how many distinct ways
// do we have to climb n stairs?

namespace Recursive {

	int climbingStairs(int n) {

		if (n < 2)
			return 1;

		return climbingStairs(n - 1) + climbingStairs(n - 2);
	}

}

namespace DP {
	int climbingStairs(int n) {

		auto arr = new int[n + 1];
		arr[0] = 1;
		arr[1] = 1;

		for (int i = 2; i < n + 1; ++i)
			arr[i] = arr[i - 1] + arr[i - 2];

		auto ans = arr[n];
		delete[] arr;
		return ans;
	}
}

int main(){

	auto testCase = [](int input, int expected) {
		cout << "__________________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Input: " << input << endl;
		cout << "Expected: " << expected << endl;
		auto recursiveAns = Recursive::climbingStairs(input);
		cout << "Recursive Result: " << recursiveAns << endl;
		cout << "Recursive Status: " << (recursiveAns != expected ? "NOT OK" : "OK") << endl;
		auto dpAns = DP::climbingStairs(input);
		cout << "DP Result: " << dpAns << endl;
		cout << "DP Status: " << (dpAns != expected ? "NOT OK" : "OK") << endl;
		cout << "__________________" << endl;
	};

	testCase(2, 2);
	testCase(3, 3);

	return 0;
}