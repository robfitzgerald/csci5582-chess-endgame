#ifndef __CSCI5582_chess_endgame__State_02__
#define __CSCI5582_chess_endgame__State_02__

#include <vector>
#include <string>
#include "Piece.h"

class Empty: public Piece {
public:
    typedef Piece super;
    Empty();
    Empty(int x, int y) {
        super::place(x, y);
    }
    void generateMoves(const Bitboard& a, const Bitboard& b, const int c) { /* dummy */ };
};

class Board {
public:
    Board();
    Board(Board&);
    
    void setPiece(int, int, Piece);
    Piece getPiece(int, int, int);
    
    std::string getMove() { return move; }
    std::string getChessMove();
    
    void setHeuristic(int h) { heuristic = h; }
    int getHeuristic() { return heuristic; }
    
    void setPlayer(NAMES pl) { currentPlayer = pl; }
    NAMES getPlayer() { return currentPlayer; }
private:
    std::string move;
    std::vector<Piece> pieces [NUM_PLAYERS][NUM_TYPES];
    NAMES currentPlayer;
    int heuristic;
};


#endif /* defined(__CSCI5582_chess_endgame__State_02__) */
