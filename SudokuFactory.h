#pragma once
#include "PuzzleFactory.h"
#include "SudokuOffspring.h"
class SudokuFactory : public PuzzleFactory
{
public:
	Puzzle* createPuzzle(Puzzle&) override;
private:
	SudokuOffspring mutate;
};