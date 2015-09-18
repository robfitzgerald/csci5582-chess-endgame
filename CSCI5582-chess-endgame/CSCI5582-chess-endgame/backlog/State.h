//
//  State.h
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#ifndef __CSCI5582_chess_endgame__State__
#define __CSCI5582_chess_endgame__State__

#include <string>

class State {
public:
    State() {
        for (int i = 0;i < 8; ++i) {
            for (int j = 0;j < 8; ++j) {
                board[i][j] = 32;
            }
        }
    }  // default: set each to ASCII 32
    void placePawn(int x,int y) { board[x][y] = 'P'; }
    void placeKing(int x,int y) { board[x][y] = 'K'; }
    void placeQueen(int x,int y) { board[x][y] = 'Q'; }
    void saveMove(std::string);  // transforms to chess a-h, 1-8 formatting
    std::string getMove() { return move; }
private:
    char board [8][8];
    std::string move;  // move that generated this string
    
};

char encodeChessFile(int);
char encodeChessRank(int);

#endif /* defined(__CSCI5582_chess_endgame__State__) */
