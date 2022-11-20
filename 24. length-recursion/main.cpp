#include <iostream>

using namespace std;

int length(char input[]) {
		
	if (input[0] == '\0')
		return 0;
	return 1 + length(input + 1);
}

int main() {

	auto input = "123456";
	cout << "Input: " << input << ", Length of Input: " << length(const_cast<char*>(input)) << endl;

	return 0;
}