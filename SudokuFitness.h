#pragma once
#include "Fitness.h"
#include "Puzzle.h"
using namespace std;

class Sudoku;

class SudokuFitness : public Fitness
{
	friend class Sudoku;
public:
	int howFit(const Puzzle&);
	int checkRow(const Sudoku&);
	int checkColumn(const Sudoku&);
	int checkBox(int, int, const Sudoku&);
};
