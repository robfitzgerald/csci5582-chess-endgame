#ifndef __CSCI5582_chess_endgame__ChessPiece__
#define __CSCI5582_chess_endgame__ChessPiece__

#include <vector>
#include "Board.h"
#include "MoveStrategy.h"

class MovePawn: public MoveStrategy {
public:
    static void create();
    void generateMoves(Board&, std::vector<Board>&);
protected:
    MovePawn();
    virtual ~MovePawn(){};
};

class MoveKing: public MoveStrategy {
public:
    static void create();
    void generateMoves(Board&, std::vector<Board>&);
protected:
    MoveKing();
    virtual ~MoveKing(){};
};

class MoveQueen: public MoveStrategy {
public:
    static void create();
    void generateMoves(Board&, std::vector<Board>&);
protected:
    MoveQueen();
    virtual ~MoveQueen(){};
};

bool isOnBoard(Location here);
bool noBuddies(Board&, TYPE, Piece);

#endif /* defined(__CSCI5582_chess_endgame__ChessPiece__) */
