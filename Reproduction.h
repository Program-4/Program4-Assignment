#pragma once
#include<iostream>
#include"Puzzle.h"
#include "Sudoku.h"
using namespace std;

class Reproduction
{
public:
	virtual Puzzle* makeOffspring(Puzzle&) = 0;
};
