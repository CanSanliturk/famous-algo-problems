#include <vector>
#include <string>
#include <iostream>

using namespace std;

// this is "Edit Distance" problem of leetcode
// two strings are given. what is the minimum number of operations
// it takes to make given strings same?
// permitted operations are:
// 1: insert a character
// 2: delete a character
// 3: replace a character

namespace Recursive {
	int minDistance(string str1, string str2, int m = -1, int n = -1) {

		if (m == -1) {
			m = str1.length();
			n = str2.length();
		}

		if (m == 0)
			return n;

		if (n == 0)
			return m;

		if (str1[m - 1] == str2[n - 1])
			return minDistance(str1, str2, m - 1, n - 1);

		auto insert = minDistance(str1, str2, m, n - 1);
		auto del = minDistance(str1, str2, m - 1, n);
		auto replace = minDistance(str1, str2, m - 1, n - 1);
		return 1 + min(insert, min(del, replace));
	}
}

namespace DP {
	int minDistance(string str1, string str2) {

		int m = str1.length();
		int n = str2.length();

		int dp[m + 1][n + 1];

		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (i == 0)
					dp[i][j] = j;
				else if (j == 0)
					dp[i][j] = i;
				else if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else {
					int insert = dp[i][j - 1];
					int del = dp[i - 1][j];
					int replace = dp[i - 1][j - 1];
					dp[i][j] = 1 + min(insert, min(del, replace));
				}
			}
		}

		return dp[m][n];
	}
}

int main(){

	auto testCase = [](string input1, string input2, int expected) {
		cout << "__________________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Inputs: " << input1 << ", " << input2 << endl;
		cout << "Expected: " << expected << endl;
		auto recursiveAns = Recursive::minDistance(input1, input2);
		cout << "Recursive Result: " << recursiveAns << endl;
		cout << "Recursive Status: " << (recursiveAns != expected ? "NOT OK" : "OK") << endl;
		auto dpAns = DP::minDistance(input1, input2);
		cout << "DP Result: " << dpAns << endl;
		cout << "DP Status: " << (dpAns != expected ? "NOT OK" : "OK") << endl;
		cout << "__________________" << endl;
	};

	// for apple, example subsequences are ape, ae, ppe, ale, pl, etc

	testCase("horse", "ros", 3);
	testCase("intention", "execution", 5);

	return 0;
}