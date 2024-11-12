// FINANCE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Board.hpp"
#include "MoveGenerator.hpp"
#include <vector>
#include<iostream>

std::string pieceToString(ChessPiece piece) {
    switch (piece) {
    case WHITE_PAWN: return "WHITE_PAWN";
    case WHITE_KNIGHT: return "WHITE_KNIGHT";
    case WHITE_BISHOP: return "WHITE_BISHOP";
    case WHITE_ROOK: return "WHITE_ROOK";
    case WHITE_QUEEN: return "WHITE_QUEEN";
    case WHITE_KING: return "WHITE_KING";
    case BLACK_PAWN: return "BLACK_PAWN";
    case BLACK_KNIGHT: return "BLACK_KNIGHT";
    case BLACK_BISHOP: return "BLACK_BISHOP";
    case BLACK_ROOK: return "BLACK_ROOK";
    case BLACK_QUEEN: return "BLACK_QUEEN";
    case BLACK_KING: return "BLACK_KING";
    case EMPTY: return "EMPTY";
    default: return "UNKNOWN_PIECE";
    }
}


int main()
{
   Board board;

   board.initializeBoard();
   uint64_t my_board = board.getBitboard(WHITE_BISHOP);

   board.printBoard(my_board - 1);
   board.printBoard(my_board & (my_board - 1));
   
   //MoveGenerator moveGen(board);
   //for (const Move move : moveGen.generatePawnMoves(BLACK)) {
   //    std::cout << pieceToString(move.capturedPiece) << '\n';
   //    board.printBoard(move.fromSquare);
   //    std::cout << pieceToString(move.movedPiece) << '\n';
   //    board.printBoard(move.toSquare);
   //}
   //moveGen.generatePawnMoves(WHITE);

   board.printBoard(0x40000ULL);
   board.printBoard(0x40000ULL >> 10);

}


