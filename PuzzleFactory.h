#pragma once
#include<iostream>
#include"puzzle.h"
using namespace std;

class PuzzleFactory
{
public:
	virtual Puzzle createPuzzle(Puzzle) = 0;
};