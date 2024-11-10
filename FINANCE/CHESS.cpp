// FINANCE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Board.hpp"
#include "MoveGenerator.hpp"
#include <vector>
#include<iostream>

int main()
{
   Board board;

   board.initializeBoard();
   uint64_t my_board = board.getBitboard(WHITE_BISHOP);
   
   MoveGenerator moveGen(board);
   moveGen.generatePawnMoves(BLACK);
   moveGen.generatePawnMoves(WHITE);

   board.printBoard(board.getBitboard(WHITE_PAWN));
   board.printBoard(board.getBitboard(BLACK_PAWN));

}
