#include "MoveGenerator.hpp"

MoveGenerator::MoveGenerator(Board& board) : board(board){

}
/*
std::vector<Move> MoveGenerator::generateAllMoves(Color color) {

}
*/
std::vector<Move> MoveGenerator::generatePawnMoves(Color color) {
	uint64_t pawnBoard;
	uint64_t movedPawns;
	uint64_t unmovedPawns;
	uint64_t pawnAttacks = 1;
	uint64_t unnocupied = board.getUnoccupied();

	if (color == NONE) {
		exit(EXIT_FAILURE);
	}
	if (color == BLACK) {
		pawnBoard = board.getBitboard(BLACK_PAWN);
		unmovedPawns = pawnBoard & board.RANK_MASKS[6];
		movedPawns = pawnBoard ^ unmovedPawns;

		pawnBoard >>= 8;
		unmovedPawns >>= 16;
	}
	else {
		pawnBoard = board.getBitboard(WHITE_PAWN);
		unmovedPawns = pawnBoard & board.RANK_MASKS[1];

		pawnBoard <<= 8;
		unmovedPawns <<= 16;
	}

	pawnBoard = (pawnBoard | unmovedPawns) & unnocupied;
	pawnBoard |= pawnAttacks;

	board.printBoard(pawnBoard);

	
	return std::vector<Move>();
}
/*
std::vector<Move> MoveGenerator::generateKnightMoves(Color color) {

}

std::vector<Move> MoveGenerator::generateBishopMoves(Color color) {

}

std::vector<Move> MoveGenerator::generateKingMoves(Color color) {

}

std::vector<Move> MoveGenerator::generateQueenMoves(Color color) {

}

std::vector<Move> MoveGenerator::generateRookMoves(Color color) {

}
*/

uint64_t MoveGenerator::getPawnAttacks(Color color, uint64_t pawns) {
	uint64_t opponentPieces;
	uint64_t leftAttacks;
	uint64_t rightAttacks;
	
	if (color == NONE) {
		exit(EXIT_FAILURE);
	}
	if (color == WHITE) {
		opponentPieces = board.getBlackPieces();
		leftAttacks = (pawns << 7);
		rightAttacks = (pawns << 9);
	}
	else { 
		opponentPieces = board.getWhitePieces();
		leftAttacks = (pawns >> 9);
		rightAttacks = (pawns >> 7);
	}

	return (leftAttacks | rightAttacks) & opponentPieces;
}

uint64_t MoveGenerator::getSlidingMoves(uint64_t position, uint64_t occupied, const std::vector<int>& directions)
{
	return 0;
}

std::vector<Move> MoveGenerator::bitboardToMoves(uint64_t fromSquare, uint64_t bitboard, ChessPiece movedPiece)
{
	return std::vector<Move>();
}