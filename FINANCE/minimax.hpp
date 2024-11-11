#ifndef MINIMAX_H_INCLUDED
#define MINIMAX_H_INCLUDED

#include "Board.hpp"

class minimax {
public:
	minimax();

	Move run(Board board, int depth);

};

#endif