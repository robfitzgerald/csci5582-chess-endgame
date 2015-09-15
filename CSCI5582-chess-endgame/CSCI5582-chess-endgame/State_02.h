//
//  State_02.h
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#ifndef __CSCI5582_chess_endgame__State_02__
#define __CSCI5582_chess_endgame__State_02__

#include <vector>
#include <string>

// State_01 (State.h) used a 2D array of chars to represent the board.
// this version will use 2 arrays of pieces and their positions.

struct Piece {
    char type, file, rank;
    Piece(char t, char f, char r): type(t), file(f), rank(r) {}
};

struct Board {
    std::vector<Piece> black;
    std::vector<Piece> white;
    std::string move;  //
    char currentMove;  // B, W
    int heuristic;
};

// recursive function object
int state(Board, int, bool);
void generateMoves();  // for each piece in current player's vector, generate states that are possible, and place in the
int heuristic(Board);

#endif /* defined(__CSCI5582_chess_endgame__State_02__) */
