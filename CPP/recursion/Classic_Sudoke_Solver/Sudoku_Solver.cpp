#include <iostream>
#include <cmath>
#include <vector>

constexpr auto size = 9;

// Function for unsolved sudoku input.
void take_inp(std::vector<std::vector<int>>& arr, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cin >> arr[i][j];
		}
	}
}

// Function to print solved sudoku.
void print_vec(std::vector<std::vector<int>>& arr) {
	int r_digit = 0, c_digit = 0;

	std::cout << "-----------------------\n";
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			std::cout << arr[i][j] << " ";
			++c_digit;
			if (c_digit == 3) {
				std::cout << "| ";
				c_digit = 0;
			}
		}
		std::cout << std::endl;
		++r_digit;
		if (r_digit == 3) {
			std::cout << "-----------------------\n";
			r_digit = 0;
		}
	}
}

bool value_canbe_placed(std::vector<std::vector<int>>& arr, int size, int i, int j, int val) {
	// horizontal linear check
	for (int l = 0; l < size; ++l) {
		if (arr[i][l] == val) {
			return false;
		}
	}

	// vertical linear check
	for (int m = 0; m < size; ++m) {
		if (arr[m][j] == val) {
			return false;
		}
	}

	// checking inside 3X3 maTRix of 9X9 sudoku
	int root = sqrt(size);
	int mrow = (i / root) * root;
	int mcol = (j / root) * root;

	for (int r = mrow; r <= mrow + 2; ++r) {
		for (int c = mcol; c <= mcol + 2; ++c) {
			if (arr[r][c] == val) {
				return false;
			}
		}
	}

	// value not present
	return true;
}

bool solveSudoku(std::vector<std::vector<int>>& arr, int size, int i, int j) {
	// --> base case
	// when row become equal to size, print
	// solved sudoku matrix and return to main.
	if (i == size) {
		std::cout << "\nSolved Sudoku matrix:\n";
		print_vec(arr);
		// sudoku solved, return true
		return true;
	}


	// --> recursive case
	// Case: if value can be filled

	// check column
	// if value of j is reached to 9 i.e, > 8 in range 0 to 8 for 9 values
	// increment the value of i to check for next row
	if (j == size) {
		return solveSudoku(arr, size, i + 1, 0);
	}

	// if value of arr[i][j] is not equal to 0 then
	// check for next column element of that row
	if (arr[i][j] != 0) {
		return solveSudoku(arr, size, i, j + 1);
	}

	// if value of arr[i][j] equal to 0 then
	// check if the num ranging from 1 to 9 can be placed at those index
	// if number can be placed at those index then place that number
	// again check for next column element of that row
	// if next element can be placed return true else reset value at those index
	else {
		for (int num = 1; num <= size; ++num) {
			if (value_canbe_placed(arr, size, i, j, num)) {
				arr[i][j] = num;
				bool nextValue = solveSudoku(arr, size, i, j + 1);
				if (nextValue) {
					return true;
				}
				else {
					arr[i][j] = 0;
				}
			}
		}
	}

	// --> If value can't be filled return false
	return false;
}

int main() {
	// 2d vector inp for storing sudoku.
	// Size 9X9.
	std::vector<int> col(size);
	std::vector<std::vector<int>> inp(size, col);

	// Function to take unsolved sudoku matrix.
	std::cout << "Enter Unsolved Sudoku Matrix:\n";
	take_inp(inp, size);

	// Solve sudoku matrix and print it.
	// Arguments passed are : 2D input matrix
	//                      : Size of board.
	//                      : Starting row.
	//                      : Starting column.
	if (!solveSudoku(inp, size, 0, 0)) {
		std::cout << "Input Unsolved Sudoku have no solution. ";
	}

	return 0;
}
