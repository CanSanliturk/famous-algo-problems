#include <vector>
#include <string>
#include <iostream>

using namespace std;

namespace Recursive {
	int longestCommonSubsequence(string str1, string str2, int i = 0, int j = 0) {

		if (i == str1.length() || j == str2.length())
			return 0;

		if (str1[i] == str2[j])
			return 1 + longestCommonSubsequence(str1, str2, i + 1, j + 1);

		return max(
			longestCommonSubsequence(str1, str2, i + 1, j), 
			longestCommonSubsequence(str1, str2, i, j + 1)
			);
	}
}

namespace DP {
	int longestCommonSubsequence(string str1, string str2) {

		int m = str1.length();
		int n = str2.length();

		int dp[m + 1][n + 1];

		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (i == 0 || j == 0)
					dp[i][j] = 0;
				else if (str1[i] == str2[j])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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
		auto recursiveAns = Recursive::longestCommonSubsequence(input1, input2);
		cout << "Recursive Result: " << recursiveAns << endl;
		cout << "Recursive Status: " << (recursiveAns != expected ? "NOT OK" : "OK") << endl;
		auto dpAns = DP::longestCommonSubsequence(input1, input2);
		cout << "DP Result: " << dpAns << endl;
		cout << "DP Status: " << (dpAns != expected ? "NOT OK" : "OK") << endl;
		cout << "__________________" << endl;
	};

	// for apple, example subsequences are ape, ae, ppe, ale, pl, etc

	testCase("apple", "mango", 1);
	testCase("apple", "ample", 4);
	testCase("apple", "maengo", 2);

	return 0;
}