#include "Board.h"
#include <iostream>

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
            return Empty(-1,-1);
    else
        return Empty(-1,-1);
}
