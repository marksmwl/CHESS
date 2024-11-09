#include <string>
#include <iostream>
#include <Windows.h>

#ifndef BITBOARD_H_INCLUDED
#define BITBOARD_H_INCLUDED

#include <vector>
#include <string>

enum PieceType { NONE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum Color { WHITE, BLACK, NO_COLOR };

struct Piece {
	PieceType type;
	Color color;

	Piece(PieceType t = NONE, Color c = NO_COLOR) : type(t), color(c) {}
};

class Board {
public:
	Board();
	void initializeBoard();
	Piece getPieceAt(int row, int col) const;
	void setPieceAt(int row, int col, Piece piece);
	void printBoard() const;

private:
	std::vector<std::vector<Piece>> board;
	


};


#endif