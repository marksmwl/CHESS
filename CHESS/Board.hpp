﻿#ifndef BITBOARD_H_INCLUDED
#define BITBOARD_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

enum ChessPiece {
	WHITE_PAWN,
	WHITE_KNIGHT,
	WHITE_BISHOP,
	WHITE_ROOK,
	WHITE_QUEEN,
	WHITE_KING,
	BLACK_PAWN,
	BLACK_KNIGHT,
	BLACK_BISHOP,
	BLACK_ROOK,
	BLACK_QUEEN,
	BLACK_KING,
	EMPTY
};

enum Color {
	BLACK,
	WHITE,
	NONE
};

struct Move {
	uint64_t fromSquare; // Used to erase old position
	uint64_t toSquare; // Used to mark new position
	ChessPiece movedPiece;
	ChessPiece capturedPiece;
};


class Board {
public:
	Board();
	void initializeBoard();
	void printBoard(uint64_t board);

	uint64_t getBitboard(ChessPiece piece);
	uint64_t getWhitePieces();
	uint64_t getBlackPieces();
	uint64_t getOccupied();
	uint64_t getUnoccupied();
	uint64_t getEmpty();
	void makeMove(Move);
	ChessPiece getPieceAt(uint64_t bitboard);
	bool updateBoard(ChessPiece piece, uint64_t newBoard);

	const uint64_t FILE_MASKS[8] = {
		0x0101010101010101ULL, // FILE_A
		0x0202020202020202ULL, // FILE_B
		0x0404040404040404ULL, // FILE_C
		0x0808080808080808ULL, // FILE_D
		0x1010101010101010ULL, // FILE_E
		0x2020202020202020ULL, // FILE_F
		0x4040404040404040ULL, // FILE_G
		0x8080808080808080ULL  // FILE_H
	};

	const uint64_t RANK_MASKS[8] = {
		0x00000000000000FFULL, // RANK_1
		0x000000000000FF00ULL, // RANK_2
		0x0000000000FF0000ULL, // RANK_3
		0x00000000FF000000ULL, // RANK_4
		0x000000FF00000000ULL, // RANK_5
		0x0000FF0000000000ULL, // RANK_6
		0x00FF000000000000ULL, // RANK_7
		0xFF00000000000000ULL  // RANK_8
	};

	const uint64_t KNIGHT_MASKS[8] = {
		(FILE_MASKS[0] | FILE_MASKS[1] | RANK_MASKS[0]), // LeftDown -10
		(FILE_MASKS[0] | FILE_MASKS[1] | RANK_MASKS[7]), // LeftUp, +6
		(RANK_MASKS[7] | RANK_MASKS[6] | FILE_MASKS[0]), // UpLeft, +15
		(RANK_MASKS[7] | RANK_MASKS[6] | FILE_MASKS[7]), // UpRight, +17
		(FILE_MASKS[7] | FILE_MASKS[6] | RANK_MASKS[7]), // RightUp, +10
		(FILE_MASKS[7] | FILE_MASKS[6] | RANK_MASKS[0]), // RightDown -6
		(RANK_MASKS[0] | RANK_MASKS[1] | FILE_MASKS[7]), // DownRight -15
		(RANK_MASKS[0] | RANK_MASKS[1] | FILE_MASKS[0])  // DownLeft -17
	};


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

	uint64_t empty;

	uint64_t blackPieces;
	uint64_t whitePieces;
	bool whitePiecesDirty = false;
	bool blackPiecesDirty = false;
	ChessPiece pieceList[64];

};

#endif