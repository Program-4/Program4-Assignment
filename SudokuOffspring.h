#pragma once
#include "Reproduction.h"

class SudokuOffspring : public Reproduction
{
	Puzzle makeOffspring(Puzzle) override;
};
