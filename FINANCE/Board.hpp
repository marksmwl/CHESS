#include <string>

#ifndef BITBOARD_H_INCLUDED
#define BITBOARD_H_INCLUDED

#include <vector>
#include <string>

class Board {
public:
	Board();
	void initializeBoard();

	uint64_t getWhitePawn() const;
	uint64_t getWhiteKnight();
	uint64_t getWhiteBishop();
	uint64_t getWhiteRook();
	uint64_t getWhiteKing();
	uint64_t getWhiteQueen();

	uint64_t getBlackPawn();
	uint64_t getBlackKnight();
	uint64_t getBlackBishop();
	uint64_t getBlackRook();
	uint64_t getBlackKing();
	uint64_t getBlackQueen();

private:
	uint64_t whitePawn;
	uint64_t whiteKnight;
	uint64_t whiteBishop;
	uint64_t whiteRook;
	uint64_t whiteQueen;
	uint64_t whiteKing;
	
	uint64_t blackPawn;
	uint64_t blackKnight;
	uint64_t blackBishop;
	uint64_t blackRook;
	uint64_t blackQueen;
	uint64_t blackKing;
};


#endif