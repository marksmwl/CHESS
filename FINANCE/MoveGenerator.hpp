#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H

#include "Board.hpp"

class MoveGenerator {
public:
	Board generatePawnMoves();
	Board generateKnightMoves();
	Board generateBishopMoves();
	Board generateRookMoves();
	Board generateKingMoves();
	Board generateQueenMoves();
};

#endif