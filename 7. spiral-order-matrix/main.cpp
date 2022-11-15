/*

PROBLEM:
	Print the matrix in the spiral order
*/

#include <vector>
#include <iostream>

using namespace std;

void printSpiralMatrix(const vector<vector<int>>& mat) {

	auto nRow = mat.size();
	auto nCol = mat.at(0).size();

	auto left = 0;
	auto right = nCol - 1;
	auto top = 0;
	auto bot = nRow - 1;

	while ((left < right) && (top < bot)) {

		// print top row
		for (int i = left; i < right; ++i)
			cout << mat[top][i] << " ";

		// print left col
		for (int i = top; i < bot; ++i)
			cout << mat[i][right] << " ";

		// print bot row
		for (int i = right; left < i; --i)
			cout << mat[bot][i] << " ";

		// print right col
		for (int i = bot; top < i; --i)
			cout << mat[i][left] << " ";


		left++;
		right--;

		bot--;
		top++;
	}

	if (left < right && (top == bot))
		for (int i = left; i <= right; ++i)
			cout << mat[top][i] << " ";

	if (top < bot && (left == right))
		for (int i = top; i <= bot; ++i)
			cout << mat[i][left] << " ";

	if ((left == right) && (bot == top))
		cout << mat[top][left] << " ";

	cout << endl;
}


int main() {

	vector<vector<int>> squareMat {
		{ 1,  2,  3,  4 },
		{ 5,  6,  7,  8 },
		{ 9,  10, 11, 12 },
		{ 13, 14, 15, 16 }
	};
	squareMat = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	cout << "Square Matrix: ";
	printSpiralMatrix(squareMat);


	vector<vector<int>> rectMat {
		{ 1,  2,  3,  4,  5 },
		{ 6,  7,  8,  9,  10 },
		{ 11, 12, 13, 14, 15 },
	};
	rectMat = {
		{ 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 },
		{ 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }
	};
	cout << "Rectangular Matrix: ";
	printSpiralMatrix(rectMat);

	vector<vector<int>> rowMat { 
		{ 1, 2, 3, 4 } 
	};
	cout << "Row Matrix: ";
	printSpiralMatrix(rowMat);

	vector<vector<int>> colMat {
		{ 1 },
		{ 2 },
		{ 3 },
		{ 4 }
	};
	cout << "Column Matrix: ";
	printSpiralMatrix(colMat);

	return 0;
}

