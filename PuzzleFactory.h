#pragma once
#include<iostream>
#include"Puzzle.h"
using namespace std;

class PuzzleFactory
{
public:
	virtual Puzzle* createPuzzle(Puzzle&) = 0;
};