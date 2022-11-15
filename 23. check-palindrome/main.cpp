#include <iostream>

using namespace std;

bool checkPalindrome(const char* str, int n, int idx = 0) {

	if (!str)
		return false;

	if (n < 2)
		return true;

	if ((n & 1) && (idx == n / 2))
		return true;

	if (str[idx] != str[n - 1 - idx])
		return false;

	return checkPalindrome(str, idx + 1);
}

int main() {

	const char* palindrome = "abcba"; 
	const char* notPalindrome = "abc";

	cout << palindrome << ": " << (checkPalindrome(palindrome, 5) ? "palindrome" : "not palindrome") << endl;
	cout << notPalindrome << ": " << (checkPalindrome(notPalindrome, 3) ? "palindrome" : "not palindrome") << endl;

	return 0;
}