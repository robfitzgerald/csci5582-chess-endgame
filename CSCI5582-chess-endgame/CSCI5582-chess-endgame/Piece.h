#ifndef __CSCI5582_chess_endgame__Piece__
#define __CSCI5582_chess_endgame__Piece__

#include <cstdlib>

typedef uint64_t Bitboard;

struct Location {
    int x;
    int y;
    Location(int xpos, int ypos): x(xpos), y(ypos) {}
};

class Piece {
public:
    // for now, public everything
    Piece();
    Piece(int x, int y) {
        place(x,y);
    }
    Piece(const Piece&);

    void clear();
    void place(int, int);
    Location locate() const;
    bool isLegal() { return legal; }
    void debugPrintBoard();
    
    // (v2 - friend function for Bitboard access)
    Bitboard board;
    bool legal;
};

#endif /* defined(__CSCI5582_chess_endgame__Piece__) */
