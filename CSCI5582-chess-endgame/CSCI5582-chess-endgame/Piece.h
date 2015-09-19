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
    Piece();
    Piece(int x, int y) {
        place(x,y);
    }
    Piece(const Piece&);
    
    void clear();
    bool place(int, int);
    Location locate() const;
    
    // for lack of a safer way to expose the board for bit ops.. it's public
    Bitboard board;
};

#endif /* defined(__CSCI5582_chess_endgame__Piece__) */
