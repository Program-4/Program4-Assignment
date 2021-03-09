#include "SudokuFitness.h"
#include "Puzzle.h"
#include "Sudoku.h"

int SudokuFitness::howFit(const Puzzle &p)
{
	const Puzzle* puz = &p;
	const Sudoku& s = *(static_cast<const Sudoku*>(puz));
	int fitnessNumber = 0;
	fitnessNumber += checkRow(s);
	fitnessNumber += checkColumn(s);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			fitnessNumber += checkBox(i, j, s);
		}
	}

	return fitnessNumber;
}

int SudokuFitness::checkRow(const Sudoku &s)
{
	int fitnessNumber = 0;
	int row = 0;
	while (row < 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = i + 1; j < 9; j++) {
				if (s.sudoku[row][j] == s.sudoku[row][i]) {
					fitnessNumber++;
				}
			}
		}
		row++;
	}
	return fitnessNumber;
}

int SudokuFitness::checkColumn(const Sudoku& s)
{
	int fitnessNumber = 0;
	int column = 0;
	while (column < 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = i + 1; j < 9; j++) {
				if (s.sudoku[j][column] == s.sudoku[i][column]) {
					fitnessNumber++;
				}
			}
		}
		column++;
	}
	return fitnessNumber;
}

int SudokuFitness::checkBox(int X, int Y, const Sudoku& s)
{
	int box[9];
	int fitnessNumber = 0;
	int x = X * 3;
	int y = Y * 3;
	int count = 0;
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			box[count] = s.sudoku[row + x][column + y];
			count++;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (box[i] == box[j]) {
				fitnessNumber++;
			}
		}
	}
	return fitnessNumber;
}
