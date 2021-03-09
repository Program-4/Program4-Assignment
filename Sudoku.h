#pragma once
#include <iostream>
#include "puzzle.h"
#include "SudokuFitness.h"
#include "string"
class Sudoku : public Puzzle
{
	friend istream& operator>>(istream&, Sudoku&);
	friend ostream& operator<<(ostream&, Sudoku&);
	friend class sudokuFitness;
public:
	Sudoku();
	~Sudoku();
	void inputHelper(string input);
	string outputHelper();
	bool changeable[9][9];
	int sudoku[9][9];
private:
	int fitnessScore;
	SudokuFitness fitness;
};