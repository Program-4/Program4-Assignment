#pragma once
#include <iostream>
#include "puzzle.h"
using namespace std;
class Fitness
{
public:
	virtual int howFit(const Puzzle&) = 0;
};
