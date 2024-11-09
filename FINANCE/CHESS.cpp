// FINANCE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Board.hpp"
#include <vector>
#include<iostream>

int main()
{
   Board board;

   board.initializeBoard();
   uint64_t my_board = board.getBitboard(WHITE_BISHOP);
   
   board.printBoard(board.FILE_MASKS[7]);
}
