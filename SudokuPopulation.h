#pragma once
#include"Population.h"
#include "Puzzle.h"
#include "Reproduction.h"
#include <vector>
using namespace std;

class SudokuPopulation : public Population
{
public:
	SudokuPopulation();
	void cull() override;
	void newGeneration();
	int bestFitness();
	Sudoku* bestIndividual(); 
private:
	vector<Sudoku*> population;
	int populationSize;
	int generationLimit;
};
