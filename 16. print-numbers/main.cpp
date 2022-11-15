#include <iostream>

using namespace std;

// aim is to print array using recursion

void print(int n) {

	if (n < 0)
		return;

	/*
	print(n - 1);
	if recursive call is made before doing anything, it is called
	head recursion. operation of the function with initial call argument
	will be executed lastly. for this function, this means printing in ascending order
	*/
	cout << n << " ";
	/*
	if recursive call is made after doing something, it is called
	tail recursion. operation of the function with initial call argument
	will be executed firstly. for this function, this means printing in descending order
	*/
	print(n - 1);
}

int main() {
	print(5);
	cout << endl;
	return 0;
}