/*
 * File: SudokuSolver.cpp
 * This program is heavily influenced by a similar code found in the reader for the Stanford Course CS106B.
 * A rudimentary sudoku solver that uses a back tracking algorithm in order to solve a sudoku puzzle.
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

void printGrid(vector<vector<int> > & sudokuGrid); // printing the sudoku box in grid form
bool solveSudoku(vector<vector<int> > & sudokuGrid); // backtracking function to solve the sudoku with the given hints
bool findUnassignedLocation(vector<vector<int> > & sudokuGrid, int & row, int & col); // checks whether any location is unassigned
bool NoConflicts(vector<vector<int> > & sudokuGrid, int row, int col, int num); // checks for conflicts if a given value is placed in the cell
bool usedInRow(vector<vector<int> > & sudokuGrid, int row, int num); // helper function for NoConflicts(). Checks whether a value is used in a row
bool usedInCol(vector<vector<int> > & sudokuGrid, int col, int num); // helper function for NoConflicts(). Checks whether a value is used in a column
bool usedInBox(vector<vector<int> > & sudokuGrid, int row1, int col1, int num); // helper function for NoConflicts(). Checks whether a value is used in the 3x3 box in which the given cell is present

int main() {
	vector<vector<int> > sudokuGrid(9, vector<int>(9));
	
	cout << "Enter the number of given digits :" << endl;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Enter the two integers corresponding to the position of the cell, followed by the number in the cell: " << endl;
		int x, y;
		cin >> x >> y;
		int hint;
		cin >> hint;
		sudokuGrid[x - 1][y - 1] = hint;
	}

	cout << endl << endl << "The grid provided by you is :" << endl << endl;
	printGrid(sudokuGrid);

	cout << endl << endl << "The solved grid is :" << endl << endl;
	solveSudoku(sudokuGrid);
	cout << endl;

	return 0;
}

void printGrid(vector<vector<int> > & sudokuGrid) {
	// formatting and general aesthetics
	for (int i = 0; i < 9; i++) {
		cout << "+---";
	}
	cout << "+" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudokuGrid[i][j] == 0) {
				cout << "|" << "   ";
			}
			else {
				cout << "|" << right << setw(2) << sudokuGrid[i][j] << " ";
			}
		}
		cout << "|" << endl;
		for (int j = 0; j < 9; j++) {
			cout << "+---";
		}
		cout << "+" << endl;
	}
}

bool solveSudoku(vector<vector<int> > & sudokuGrid) {
	int row;
	int col;

	if (!findUnassignedLocation(sudokuGrid, row, col)) {
		printGrid(sudokuGrid);
		return true;
	}

	for (int num = 1; num <= 9; num++) {
		if (NoConflicts(sudokuGrid, row, col, num)) {
			sudokuGrid[row][col] = num;
			if (solveSudoku(sudokuGrid)) return true;
			sudokuGrid[row][col] = 0;
		}
	}

	return false; // triggering the backtracking process
}

bool findUnassignedLocation(vector<vector<int> > & sudokuGrid, int & row, int & col) {
	// as soon as an unassigned location is found, return true
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			if (sudokuGrid[row][col] == 0) {
				return true;
			}
		}
	}
	return false;
}

bool NoConflicts(vector<vector<int> > & sudokuGrid, int row, int col, int num) {
	// a cell is safe for a given value if the value doesn't appear in the same row, column or the box
	return !usedInRow(sudokuGrid, row, num) && !usedInCol(sudokuGrid, col, num) && !usedInBox(sudokuGrid, row - row % 3, col - col % 3, num);
}

bool usedInRow(vector<vector<int> > & sudokuGrid, int row, int num) {
	// check if any of the other eight cells
	for (int col = 0; col < 9; col++) {
		if (sudokuGrid[row][col] == num) return true;
	}
	return false;
}

bool usedInCol(vector<vector<int> > & sudokuGrid, int col, int num) {
	for (int row = 0; row < 9; row++) {
		if (sudokuGrid[row][col] == num) return true;
	}
	return false;
}

bool usedInBox(vector<vector<int> > & sudokuGrid, int row1, int col1, int num) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (sudokuGrid[row + row1][col + col1] == num) return true;
		}
	}
	return false;
}