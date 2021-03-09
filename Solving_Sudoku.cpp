// Solving_Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include"Sudoku.h"
#include "SudokuFitness.h"
#include "SudokuOffspring.h"
#include "SudokuFactory.h"

using namespace std;

int main()
{
    Sudoku s1;
    cin >> s1;
    cout << s1;

    SudokuFactory test;

    cout << "\n";
    cout << "Filling up 0's" << endl;
    test.createPuzzle(s1);
    cout << s1 << endl;

    cout << "\n";
    cout << "New Puzzle being made" << endl;

    test.createPuzzle(s1);

    cout << s1 << endl;
}