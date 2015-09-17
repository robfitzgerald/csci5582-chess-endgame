//
//  State_02.cpp
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#include "State_03.h"
#include <iostream>

// -------------- class Piece -------------------------------------------

void Piece::clear() { board = 0; }

// returns success in storing piece location
bool Piece::place(int x, int y) {
    if ( !((x + 8*y) > 63)) {
        int index = x + (8*y);          // bitboard 'index'
        board = 1;          // storing a bit is 2^index; start at 2^0 = 1
        if (index != 0) {   // if index was 0, we want board = 1 and be done
            for (int i = 0; i < index; ++i) {
                board *= 2;
            }
        }
    } else {
        return false;
    }
    return true;

}

Location Piece::locate() {
    int index = -1, i = 0;
    Bitboard bit = 1;
    
    while (i < 64) {
        if ((bit & board) == board) {
            index = i;
            i = 64; // end
        }
        bit *= 2;
        ++i;
    }
    
    if (index == -1) { return Location(-1,-1); }

    return Location(index % 8, index / 8);
}

// -------------- class Board -------------------------------------------

Board::Board(Board& source) {
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        this->pieces[i] = source.pieces[i];
    }
    this->move = source.getMove();
}

std::string Board::getChessMove() {
    std::string output;
    output.push_back(97 + move[0]);
    output.push_back(1 + move[1]);
    output.push_back(97 + move[2]);
    output.push_back(1 + move[3]);
    return output;
}

void Board::addPiece(int pl, Piece pc) {
    if (0 <= pl && pl < NUM_PLAYERS)
        pieces[pl].push_back(pc);
}

Piece Board::getPiece(int pl, int i) {
    if (0 <= pl && pl < NUM_PLAYERS)
        if (0 <= i && i < pieces[pl].size())
            return pieces[pl][i];
        else
            return Piece(-1,-1);
    else
        return Piece(-1,-1);
}
