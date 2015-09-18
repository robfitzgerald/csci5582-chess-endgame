#ifndef __CSCI5582_chess_endgame__ChessPiece__
#define __CSCI5582_chess_endgame__ChessPiece__

#include "Piece.h"
#include "Board.h"

class Pawn: public Piece {
    void generateMoves(Board&);
};

class King: public Piece {
    void generateMoves(const Bitboard&, const Bitboard&, const int);
};

class Queen: public Piece {
    void generateMoves(const Bitboard&, const Bitboard&, const int);
};

#endif /* defined(__CSCI5582_chess_endgame__ChessPiece__) */
