#ifndef __CSCI5582_chess_endgame__ChessPiece__
#define __CSCI5582_chess_endgame__ChessPiece__

#include <vector>
#include "Board.h"
#include "MoveStrategy.h"

class Pawn: public MoveStrategy {
    void generateMoves(Board&, std::vector<Board>*&);
};

class King: public MoveStrategy {
    void generateMoves(Board&, std::vector<Board>&);
};

class Queen: public MoveStrategy {
    void generateMoves(Board&, std::vector<Board>&);
};

bool testRange(Location);

#endif /* defined(__CSCI5582_chess_endgame__ChessPiece__) */
