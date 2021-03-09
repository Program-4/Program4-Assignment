#include "SudokuOffspring.h"
#include "Puzzle.h"
#include <stdlib.h>
#include <time.h>
/*
Purpose: The purpose of this method is to return a puzzle object that has changed values at positions where they are not fixed. These 
values are changed based off probability. The probability is at 5% currently, otherwise the number will not change. 
If the probability is 5% then it will generate a new value, before placing it in the puzzle it will check to ensure it is not identical
to the number already in the puzzle. 
*/
Puzzle* SudokuOffspring::makeOffspring(Puzzle &original){
   Puzzle* puz = &original;
	Sudoku& s = *(static_cast<Sudoku*>(puz));

   srand(time(0));

   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
         if(s.changeable[i][j] == true){
            if(produceProb() <= 5){
               int x = newVal();
               /*A while loop to ensure the random new number does not equal the same number that is already in the puzzle.
               It will repeat until the random new number does not equal the original number in the puzzle*/
               while(isEqual(x, i, j, s)){
                  x = newVal();
               }
               s.sudoku[i][j] = x;
            }
         }
         else{
            continue;
         }
      }
   }
   return puz;
}
/*
Purpose: The purpose of this method is to generate values for all positions of the puzzle that have a 0. This method is only called at the 
beginning of the program. Otherwise the makeOffspring method will be called. 
*/
Puzzle* SudokuOffspring::initialPuzzle(Puzzle& p){
   Puzzle* puz = &p;
	Sudoku& s = *(static_cast<Sudoku*>(puz));

   srand(time(0));

   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
         if(s.sudoku[i][j] == 0){
            s.sudoku[i][j] = newVal();
         }
      }
   }
   return puz;
}
/*
Purpose: The purpose of this method is to return an int value for the probability. If the number returns 5 or lower than it will signal
to the puzzle object that the specific position's value is able to be changed now.
*/
int SudokuOffspring::produceProb(){

   int probability = rand() % 100;//produce a number between 0 and 99
   
   return probability;
}
/*
Purpose: The purpose of this method returns an int that represents the new value that is supposed to be placed in the puzzle's current 
position. 
*/
int SudokuOffspring::newVal(){
   
   int newValue = rand() % 10;//produce a number between 0 and 9

   if(newValue == 0){
      newValue = 1;
   }
   return newValue;
}
/*
Purpose: The purpose of this method is to return a boolean. It will return true if the new Value is equal to the current puzzle's position.
It will return false if the new Value is not equal to the current position's number.
*/
bool SudokuOffspring::isEqual(int newVal, int row, int column, Sudoku s){
   if(newVal == s.sudoku[row][column]){
      return true;
   }
   else{
      return false;
   }
}