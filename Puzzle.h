#pragma once
#include <iostream>
using namespace std;
class Puzzle
{
	friend istream& operator>>(istream&, Puzzle&);
	friend ostream& operator<<(ostream&, Puzzle&);
};