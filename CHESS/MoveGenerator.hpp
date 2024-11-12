#ifndef MOVEGENERATOR_H_INCLUDED
#define MOVEGENERATOR_H_INCLUDED

#include <vector>
#include "Board.hpp"

class MoveGenerator {
public:
    // Constructor
    MoveGenerator(Board& board);

    // Main function to generate all legal moves for a given color
    std::vector<Move> generateAllMoves(Color color);

    // Functions to generate moves for each piece type
    std::vector<Move> generatePawnMoves(Color color);
    std::vector<Move> generateKnightMoves(Color color);
    std::vector<Move> generateBishopMoves(Color color);
    std::vector<Move> generateRookMoves(Color color);
    std::vector<Move> generateQueenMoves(Color color);
    std::vector<Move> generateKingMoves(Color color);

private:
    Board& board; // Reference to the board to access its bitboards and state

    // Helper functions for move generation
    uint64_t getPawnAttacks(Color color, uint64_t pawns);
    uint64_t getSlidingMoves(uint64_t position, uint64_t occupied, const std::vector<int>& directions);

    // Utility function to convert the generated bitboard moves to Move structs
    std::vector<Move> bitboardToMoves(uint64_t fromSquare, uint64_t bitboard, ChessPiece movedPiece);
};

#endif