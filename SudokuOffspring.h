#pragma once
#include "Reproduction.h"
#include "Puzzle.h"

class SudokuOffspring : public Reproduction
{
	friend class Sudoku;
	public:
	Puzzle* makeOffspring(Puzzle&) override;
   Puzzle* initialPuzzle(Puzzle& p);
	int produceProb();
	int newVal();
	bool isEqual(int newVal, int row, int column, Sudoku s);
};
