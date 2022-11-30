#include <vector>
#include <iostream>
#include <unordered_map>

using namespace  std;

// aim is to reach 1, with 3 allowed operations
// 1: Decrement by 1
// 2: Divide by 2
// 3: Divide by 3

namespace BruteForce {

	int getMinNumberOfStepsTo1(int n) {

		if (n < 2)
			return 0;

		if (n < 4)
			return 1;

		int ans = getMinNumberOfStepsTo1(n - 1);

		if (n % 2 == 0) {
			auto res = getMinNumberOfStepsTo1(n / 2);
			if (res < ans)
				ans = res;
		}

		if (n % 3 == 0) {
			auto res = getMinNumberOfStepsTo1(n / 3);
			if (res < ans)
				ans = res;
		}

		++ans;
		return ans;
	}
};

namespace TopDownWithMemorization {

	unordered_map<int, int> cache;

	int getMinNumberOfStepsTo1(int n) {

		if (cache.count(n))
			return cache[n];

		if (n < 2)
			return 0;

		if (n < 4)
			return 1;

		int ans = getMinNumberOfStepsTo1(n - 1);

		if (n % 2 == 0) {
			auto res = getMinNumberOfStepsTo1(n / 2);
			if (res < ans)
				ans = res;
		}

		if (n % 3 == 0) {
			auto res = getMinNumberOfStepsTo1(n / 3);
			if (res < ans)
				ans = res;
		}

		++ans;

		cache[n] = ans;

		return ans;
	}
};


namespace BottomUp {
	int getMinNumberOfStepsTo1(int n) {

		auto arr = new int[n + 1];

		arr[1] = 0;
		arr[2] = 1;
		arr[3] = 1;

		for (int i = 4; i < n + 1; ++i)
			arr[i] = 1 + min(arr[i - 1], min(arr[i - 2], arr[i - 3]));

		auto ans = arr[n];
		delete[] arr;
		return ans;
	}
};

int main() {

	auto testCase = [](int input, int expected) {
		cout << "__________________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Input: " << input << endl;
		cout << "Expected: " << expected << endl;
		auto bruteForceRes = BruteForce::getMinNumberOfStepsTo1(input);
		cout << "Brute Force Result: " << bruteForceRes << endl;
		cout << "Brute Force Status: " << (bruteForceRes != expected ? "NOT OK" : "OK") << endl;
		auto memorizationRes = TopDownWithMemorization::getMinNumberOfStepsTo1(input);
		cout << "Top-Down with Memorization Result: " << memorizationRes << endl;
		cout << "Top-Down with Memorization Status: " << (memorizationRes != expected ? "NOT OK" : "OK") << endl;
		auto buttomUpRes = BottomUp::getMinNumberOfStepsTo1(input);
		cout << "Bottom-Up Result: " << buttomUpRes << endl;
		cout << "Bottom-Up Status: " << (buttomUpRes != expected ? "NOT OK" : "OK") << endl;
		cout << "__________________" << endl;
	};

	testCase(7, 3);
	testCase(10, 3);
	testCase(11, 4);


	return 0;
}
