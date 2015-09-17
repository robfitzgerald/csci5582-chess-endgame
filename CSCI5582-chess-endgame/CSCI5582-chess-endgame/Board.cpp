#include "Board.h"
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

Board::Board() {
    move = "";
}

Board::Board(Board& source) {
    
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        for (int j = 0; j < NUM_TYPES; ++j) {
            this->pieces[i][j] = source.pieces[i][j];
        }
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

void Board::setPiece(int pl, int t, Piece pc) {
    if (0 <= pl && pl < NUM_PLAYERS)
        pieces[pl][t].push_back(pc);
}

Piece Board::getPiece(int pl, int t, int i) {
    if (0 <= pl && pl < NUM_PLAYERS)
        if (0 <= i && i < pieces[pl][t].size())
            return pieces[pl][t][i];
        else
            return Piece(-1,-1);
    else
        return Piece(-1,-1);
}
