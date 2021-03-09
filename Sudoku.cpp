#include "Sudoku.h"
#include "sudokuFitness.h"

Sudoku::Sudoku()
{
	fitnessScore = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sudoku[i][j] = 0;
			changeable[i][j] = true;
		}
	}
}

Sudoku::~Sudoku()
{
	//for (int i = 0; i < 9; i++) {
	//	delete[] sudoku[i];
	//	delete[] changeable[i];
	//}
	//delete[] sudoku;
	//delete[] changeable;
}

void Sudoku::inputHelper(string input)
{
	int column = 0;
	int row = 0;
	int inputVal = 0;
	while (inputVal < input.length() && row < 9) {
		if (input[inputVal] - 48 > 0 && input[inputVal] - 48 <= 9) {
			sudoku[row][column] = input[inputVal] - 48;
			changeable[row][column] = false;
		}
		inputVal++;
		column++;
		if (column == 9) {
			column = 0;
			row++;

		}
	}
	fitnessScore = fitness.howFit(*this);
	cout << fitnessScore;
}
string Sudoku::outputHelper()
{
	string output;
	output += "+-------+-------+-------+\n";
	for (int i = 0; i < 9; i++) {
		if (i == 3 || i == 6) {
			output += "+-------+-------+-------+\n";
		}
		output += "| ";
		for (int j = 0; j < 9; j++) {
			char a = sudoku[i][j] + '0';
			output.push_back(a);
			output += " ";
			if (j == 2 || j == 5 || j == 8) {
				output += "| ";
			}
		}
		output += "\n";
	}
	output += "+-------+-------+-------+\n";
	return output;
}

istream& operator>>(istream& in, Sudoku& s)
{
	string str;
	in >> str;
	s.inputHelper(str);
	return in;
}

ostream& operator<<(ostream& out, Sudoku& s)
{
	out << s.outputHelper();
	return out;
}
