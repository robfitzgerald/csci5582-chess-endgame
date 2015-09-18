//
//  Piece.h
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/17/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#ifndef __CSCI5582_chess_endgame__Piece__
#define __CSCI5582_chess_endgame__Piece__

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
    void clear();
    bool place(int, int);
    Location locate();
    virtual void moveStrategy(Bitboard) =0;
    
private:
    char type;
    Bitboard board;
};

#endif /* defined(__CSCI5582_chess_endgame__Piece__) */
