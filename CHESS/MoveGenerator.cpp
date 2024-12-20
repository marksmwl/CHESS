#include "MoveGenerator.hpp"

MoveGenerator::MoveGenerator(Board& board) : board(board){

}

//Returns a list of all possible Moves for the pawns on the board
std::vector<Move> MoveGenerator::generatePawnMoves(Color color) {
	std::vector<Move> moves;
	uint64_t pawnBoard;
	uint64_t movedPawns;
	uint64_t unmovedPawns;
	uint64_t unoccupied = board.getUnoccupied();

	if (color == NONE) {
		exit(EXIT_FAILURE);
	}
    if (color == BLACK) {
        pawnBoard = board.getBitboard(BLACK_PAWN);
        unmovedPawns = pawnBoard & board.RANK_MASKS[6];

        //Pawn attacks (left and right)
        uint64_t leftAttacks = ((pawnBoard & ~board.FILE_MASKS[7]) >> 9) & board.getWhitePieces();
        uint64_t rightAttacks = ((pawnBoard & ~board.FILE_MASKS[0]) >> 7) & board.getWhitePieces();

        //Add capture moves
        for (uint64_t move = leftAttacks; move; move &= (move - 1)) {
            int to = std::_Countr_zero(move);
            int from = to + 9;
            ChessPiece capturedPiece = board.getPieceAt(1ULL << from);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 (to);
            moves.push_back({ 1ULL << from, 1ULL << to, BLACK_PAWN, capturedPiece });
        }

        for (uint64_t move = rightAttacks; move; move &= (move - 1)) {
            int to = std::_Countr_zero(move);
            int from = to + 7;
            ChessPiece capturedPiece = board.getPieceAt(1ULL << to);
            moves.push_back({ 1ULL << from, 1ULL << to, BLACK_PAWN, capturedPiece });
        }

        //Single and double moves
        uint64_t singleMoves = (pawnBoard >> 8) & unoccupied;
        uint64_t doubleMoves = ((singleMoves & board.RANK_MASKS[5]) >> 8) & unoccupied;

        //Add single and double moves
        for (uint64_t move = singleMoves; move; move &= (move - 1)) {
            int to = std::_Countr_zero(move);
            int from = to + 8;
            moves.push_back({ 1ULL << from, 1ULL << to, BLACK_PAWN, EMPTY });
        }

        for (uint64_t move = doubleMoves; move; move &= (move - 1)) {
            int to = std::_Countr_zero(move);
            int from = to + 16;
            moves.push_back({ 1ULL << from, 1ULL << to, BLACK_PAWN, EMPTY });
        }
    }
    else {
        pawnBoard = board.getBitboard(WHITE_PAWN);
        unmovedPawns = pawnBoard & board.RANK_MASKS[1];

        //Pawn attacks (left and right)
        uint64_t leftAttacks = (pawnBoard << 9) & board.getBlackPieces() & ~board.FILE_MASKS[0];
        uint64_t rightAttacks = (pawnBoard << 7) & board.getBlackPieces() & ~board.FILE_MASKS[7];

        //Add capture moves
        for (uint64_t move = leftAttacks; move; move &= (move - 1)) {
            int to = std::_Countr_zero(move);
            int from = to - 9;
            ChessPiece capturedPiece = board.getPieceAt(to);
            moves.push_back({ 1ULL << from, 1ULL << to, WHITE_PAWN, capturedPiece });
        }

        for (uint64_t move = rightAttacks; move; move &= (move - 1)) {
            int to = std::_Countr_zero(move);
            int from = to - 7;
            ChessPiece capturedPiece = board.getPieceAt(to);
            moves.push_back({ 1ULL << from, 1ULL << to, WHITE_PAWN, capturedPiece });
        }

        //Single and double moves
        uint64_t singleMoves = (pawnBoard << 8) & unoccupied;
        uint64_t doubleMoves = ((singleMoves & board.RANK_MASKS[2]) << 8) & unoccupied;

        //Add single and double moves
        for (uint64_t move = singleMoves; move; move &= (move - 1)) {
            int to = std::_Countr_zero(move);
            int from = to - 8;
            moves.push_back({ 1ULL << from, 1ULL << to, WHITE_PAWN, EMPTY });
        }

        for (uint64_t move = doubleMoves; move; move &= (move - 1)) {
            int to = std::_Countr_zero(move);
            int from = to - 16;
            moves.push_back({ 1ULL << from, 1ULL << to, WHITE_PAWN, EMPTY });
        }

    }

    return moves;
}

// Method for generating knight moves
std::vector<Move> MoveGenerator::generateKnightMoves(Color color) {
    uint64_t knightBoard;
    uint64_t opponentBoard;
    uint64_t currPosition;
    uint64_t toPosition;
    ChessPiece piece = (color == BLACK) ? BLACK_KNIGHT : WHITE_KNIGHT;

    std::vector<Move> moves;
    const int knightOffsets[8] = {
        -10, 6, 15, 17, 10, -6, -15, -17
    };

    if (color == NONE) {
        exit(EXIT_FAILURE);
    }
    
    // Set the knight board according to color, and do the same for the opponent's board. 
    knightBoard = (color == BLACK) ? board.getBitboard(BLACK_KNIGHT) : board.getBitboard(WHITE_KNIGHT);
    opponentBoard = (color == WHITE) ? board.getBlackPieces() : board.getWhitePieces();

        
    while (knightBoard) {
        int from = std::_Countr_zero(knightBoard); // Get the least bit
        currPosition = 1ULL << from; // Create the board representing the curr knight position. 

        for (int i = 0; i < 8; i++) {
            if (currPosition & board.KNIGHT_MASKS[i]) { // it cannot perform the offset
                continue;
            }

            if (knightOffsets[i] < 0) {
                toPosition = currPosition >> -knightOffsets[i];
            } else { toPosition = currPosition << knightOffsets[i]; }
            
            if (toPosition & board.getWhitePieces()) { // There is a piece of the same color in the way.
                continue;
            }

            moves.push_back({ currPosition, toPosition, piece, board.getPieceAt(toPosition) }); // Add the move to the array
        }
        

        knightBoard &= (knightBoard - 1); // Decrement the pieces
    }

    return moves;
}

std::vector<Move> MoveGenerator::generateBishopMoves(Color color) {
    uint64_t bishopBoard;
    uint64_t opponentBoard;
    uint64_t currPosition;
    uint64_t toPosition;
    ChessPiece piece = (color == BLACK) ? BLACK_BISHOP : WHITE_BISHOP;

    std::vector<Move> moves;

    // Set the bishop board according to color, and do the same for the opponent's board. 
    bishopBoard = (color == BLACK) ? board.getBitboard(BLACK_BISHOP) : board.getBitboard(WHITE_BISHOP);
    opponentBoard = (color == WHITE) ? board.getBlackPieces() : board.getWhitePieces();

    while (bishopBoard) {

    }

    return moves;
}

//std::vector<Move> MoveGenerator::generateKingMoves(Color color) {
//
//}
//
//std::vector<Move> MoveGenerator::generateQueenMoves(Color color) {
//
//}
//
//std::vector<Move> MoveGenerator::generateRookMoves(Color color) {
//
//}


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
