#include "Board.hpp"


Board::Board() {

}

void Board::initializeBoard() {
	// Initialize white pieces
	this->whitePawn = 0x000000000000FF00ULL; // White pawns on rank 2
	this->whiteKnight = 0x0000000000000042ULL; // White knights on b1 and g1
	this->whiteBishop = 0x0000000000000024ULL; // White bishops on c1 and f1
	this->whiteRook = 0x0000000000000081ULL; // White rooks on a1 and h1
	this->whiteQueen = 0x0000000000000008ULL; // White queen on d1
	this->whiteKing = 0x0000000000000010ULL; // White king on e1

	// Initialize black pieces
	this->blackPawn = 0x00FF000000000000ULL; // Black pawns on rank 7
	this->blackKnight = 0x4200000000000000ULL; // Black knights on b8 and g8
	this->blackBishop = 0x2400000000000000ULL; // Black bishops on c8 and f8
	this->blackRook = 0x8100000000000000ULL; // Black rooks on a8 and h8
	this->blackQueen = 0x0800000000000000ULL; // Black queen on d8
	this->blackKing = 0x1000000000000000ULL; // Black king on e8

	this->whitePieces = whiteBishop | whiteKing | whiteKnight | whitePawn | whiteQueen | whiteRook;
	this->blackPieces = blackBishop | blackKing | blackKnight | blackPawn | blackQueen | blackRook;

	this->empty = 0x0000000000000000ULL;
}

void Board::printBoard(uint64_t board) {
	for (int rank = 7; rank >= 0; --rank) { // Start from rank 7 to print top-down
		for (int file = 0; file < 8; ++file) {
			// Calculate the bit position (rank * 8 + file)
			int position = rank * 8 + file;

			// Check if the bit at `position` is set
			if ((board >> position) & 1ULL) {
				std::cout << "1";
			}
			else {
				std::cout << "0";
			}
		}
		std::cout << std::endl; // New line after each rank
	}
	std::cout << std::endl;

}

bool Board::updateBoard(ChessPiece piece, uint64_t newBoard) {
	switch (piece) {
		case WHITE_PAWN:   whitePawn = newBoard; break;
		case WHITE_KNIGHT: whiteKnight = newBoard; break;
		case WHITE_BISHOP: whiteBishop = newBoard; break;
		case WHITE_ROOK:   whiteRook = newBoard; break;
		case WHITE_QUEEN:  whiteQueen = newBoard; break;
		case WHITE_KING:   whiteKing = newBoard; break;

		case BLACK_PAWN:   blackPawn = newBoard; break;
		case BLACK_KNIGHT: blackKnight = newBoard; break;
		case BLACK_BISHOP: blackBishop = newBoard; break;
		case BLACK_ROOK:   blackRook = newBoard; break;
		case BLACK_QUEEN:  blackQueen = newBoard; break;
		case BLACK_KING:   blackKing = newBoard; break;

		default: return false; // Invalid piece
	}
}

uint64_t Board::getWhitePieces() {
	if (this->whitePiecesDirty) { 
		this->whitePiecesDirty = false;
		this->whitePieces = whiteBishop | whiteKing | whiteKnight | whitePawn | whiteQueen | whiteRook; 
	}
	return this->whitePieces;
}

uint64_t Board::getBlackPieces() {
	if (this->blackPiecesDirty) { 
		this->blackPiecesDirty = false; 
		this->blackPieces = blackBishop | blackKing | blackKnight | blackPawn | blackQueen | blackRook; }
	return this->blackPieces;
}

uint64_t Board::getUnoccupied() {
	return ~getOccupied();
}

uint64_t Board::getOccupied() {
	return (whiteBishop | whiteKing | whiteKnight | whitePawn | whiteQueen | whiteRook
		| blackBishop | blackKing | blackKnight | blackPawn | blackQueen | blackRook);
}

uint64_t Board::getEmpty() {
	return empty;
}

uint64_t Board::getBitboard(ChessPiece piece) {
	switch (piece) {
		case WHITE_PAWN:   return whitePawn;
		case WHITE_KNIGHT: return whiteKnight;
		case WHITE_BISHOP: return whiteBishop;
		case WHITE_ROOK:   return whiteRook;
		case WHITE_QUEEN:  return whiteQueen;
		case WHITE_KING:   return whiteKing;

		case BLACK_PAWN:   return blackPawn;
		case BLACK_KNIGHT: return blackKnight;
		case BLACK_BISHOP: return blackBishop;
		case BLACK_ROOK:   return blackRook;
		case BLACK_QUEEN:  return blackQueen;
		case BLACK_KING:   return blackKing;

		default:           return 0; 
	}
}

