#include "Board.hpp"


Board::Board() {

}

void Board::initializeBoard() {
	for (int i = 0; i < 64; i++) {
		pieceList[i] = EMPTY;
	}

	// Initialize white pieces
	this->whitePawn = 0x000000000000FF00ULL; // White pawns on rank 2
	this->whiteKnight = 0x0000000000000042ULL; // White knights on b1 and g1
	this->whiteBishop = 0x0000000000000024ULL; // White bishops on c1 and f1
	this->whiteRook = 0x0000000000000081ULL; // White rooks on a1 and h1
	this->whiteQueen = 0x0000000000000008ULL; // White queen on d1
	this->whiteKing = 0x0000000000000010ULL; // White king on e1

	pieceList[0] = WHITE_ROOK;   pieceList[1] = WHITE_KNIGHT;
	pieceList[2] = WHITE_BISHOP; pieceList[3] = WHITE_QUEEN;
	pieceList[4] = WHITE_KING;   pieceList[5] = WHITE_BISHOP;
	pieceList[6] = WHITE_KNIGHT; pieceList[7] = WHITE_ROOK;
	for (int i = 8; i < 16; ++i) {
		pieceList[i] = WHITE_PAWN;
	}

	// Initialize black pieces
	this->blackPawn = 0x00FF000000000000ULL; // Black pawns on rank 7
	this->blackKnight = 0x4200000000000000ULL; // Black knights on b8 and g8
	this->blackBishop = 0x2400000000000000ULL; // Black bishops on c8 and f8
	this->blackRook = 0x8100000000000000ULL; // Black rooks on a8 and h8
	this->blackQueen = 0x0800000000000000ULL; // Black queen on d8
	this->blackKing = 0x1000000000000000ULL; // Black king on e8

	pieceList[56] = BLACK_ROOK;   pieceList[57] = BLACK_KNIGHT;
	pieceList[58] = BLACK_BISHOP; pieceList[59] = BLACK_QUEEN;
	pieceList[60] = BLACK_KING;   pieceList[61] = BLACK_BISHOP;
	pieceList[62] = BLACK_KNIGHT; pieceList[63] = BLACK_ROOK;
	for (int i = 48; i < 56; ++i) {
		pieceList[i] = BLACK_PAWN;
	}

	this->whitePieces = whiteBishop | whiteKing | whiteKnight | whitePawn | whiteQueen | whiteRook;
	this->blackPieces = blackBishop | blackKing | blackKnight | blackPawn | blackQueen | blackRook;

	this->empty = 0x0000000000000000ULL;
}

// TODO
void Board::makeMove(Move move) {

}

ChessPiece Board::getPieceAt(uint64_t bitboard) {
	// Ensure the bitboard has only one bit set
	if ((bitboard & (bitboard - 1)) != 0) {
		throw std::invalid_argument("Bitboard must have exactly one bit set.");
	}

	// Find the index of the set bit (0 to 63)
	int squareIndex = std::_Countr_zero(bitboard);

	// Return the piece at that index in the pieceArray
	return pieceList[squareIndex];
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
	return true;
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

