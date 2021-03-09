#include "SudokuFactory.h"

Puzzle* SudokuFactory::createPuzzle(Puzzle& original){
   Puzzle* puz = &original;
	Sudoku& s = *(static_cast<Sudoku*>(puz));

   int iterated = 0;

   /*A for loop to check to see if this is an initial puzzle*/
   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
         if(s.sudoku[i][j] == 0){
            mutate.initialPuzzle(s);
            break;
         }
         iterated++;
      }
   }
   if(iterated == 81){  
      mutate.makeOffspring(s);//passes the for loop it means it is not an initial puzzle and that we need to mutate based off probability
   }
   return puz;
}