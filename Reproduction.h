#pragma once
#include<iostream>
#include"puzzle.h"
#include "sudoku.h"
using namespace std;

class Reproduction
{
public:
	virtual Puzzle makeOffspring(Puzzle) = 0;
};
