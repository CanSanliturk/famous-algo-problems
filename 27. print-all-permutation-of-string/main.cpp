#include <string>
#include <iostream>

using namespace std;

// fix one element and recurse the rest
void printPermu(char str[], int i = 0) {

	if (str[i] == '\0')
	{
		cout << str << endl;
		return;
	}

	for (int j = i; str[j] != '\0'; ++j)
	{
		swap(str[i], str[j]);
		printPermu(str, i + 1);
		swap(str[j], str[i]);
	}


}

int main()
{
	char str[] = "abc";
	printPermu(str);
	return 0;
}