#include "Board.h"
#include <iostream>

// -------------- class Board -------------------------------------------


// the start state uses this constructor
Board::Board() {
    Piece clearPiece;
    clearPiece.clear();
    this->pieces[WHITE][ALLMINE].push_back(clearPiece);
    this->pieces[BLACK][ALLMINE].push_back(clearPiece);
    this->pieces[WHITE][ALLTHEIRS].push_back(clearPiece);
    this->pieces[BLACK][ALLTHEIRS].push_back(clearPiece);
    move = "";
    heuristic = 0;
    heuristicSet = false;
}

// a new 'possibility' uses this constructor.  we need to:
//   copy the pieces
//   in code, this should be immediately followed by a call to replacePiece()
//    which in turn will call populateTeamBoards().
//   that should be called by a function to write a new move string
//   we don't want to use the source's heuristic
Board::Board(const Board& source) {
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        for (int j = 0; j < NUM_TYPES; ++j) {
            this->pieces[i][j] = source.pieces[i][j];
        }
    }
    populateTeamBoards();
    move = source.move;
    heuristic = 0;
    heuristicSet = false;
}

void Board::populateTeamBoards() {
//    std::cout << "populate team boards called()" << std::endl;
    this->pieces[WHITE][ALLMINE][0].clear();
    this->pieces[WHITE][ALLTHEIRS][0].clear();
    this->pieces[BLACK][ALLMINE][0].clear();
    this->pieces[BLACK][ALLTHEIRS][0].clear();
    // type '0' is 'EMPTY' - we ignore that guy
    for (int i = 1; i < NUM_TYPES - NUM_PLAYERS; ++i) {
        size_t whitePc = pieces[WHITE][i].size();
        size_t blackPc = pieces[BLACK][i].size();
        for (int j = 0; j < whitePc; ++j) {
//            Location l = pieces[WHITE][i][j].locate();
//            std::cout << "this piece is at " << l.x << "," << l.y << "\n";
            pieces[WHITE][ALLMINE][0].board = pieces[WHITE][ALLMINE][0].board | pieces[WHITE][i][j].board;
            pieces[BLACK][ALLTHEIRS][0].board = pieces[BLACK][ALLTHEIRS][0].board | pieces[WHITE][i][j].board;
//            std::cout << "adding " << i << "th type, " << j << "th piece to white allboard." << std::endl;
//            std::cout << "looks like this now: " << pieces[WHITE][ALLMINE][0].board << std::endl;
        }
        for (int j = 0; j < blackPc; ++j) {
            pieces[BLACK][ALLMINE][0].board = pieces[BLACK][ALLMINE][0].board | pieces[BLACK][i][j].board;
            pieces[WHITE][ALLTHEIRS][0].board = pieces[WHITE][ALLTHEIRS][0].board | pieces[BLACK][i][j].board;
        }
    }
}

// obsolete - i exposed bitboard
Piece& Board::exposeBoard(NAMES pl, TYPE t, int i) {
    return pieces[pl][t][i];
}

void Board::setPiece(NAMES pl, TYPE t, Piece pc) {
    //if (0 <= pl) // && pl < NUM_PLAYERS)
    pieces[pl][t].push_back(pc);
    populateTeamBoards();
}

Piece Board::getPiece(NAMES pl, TYPE t, int index) {
    Piece err(0,0);
    err.legal = false;
    if (0 <= pl) // && pl < NUM_PLAYERS)
        if (0 <= index && index < pieces[pl][t].size()) {
            
            return pieces[pl][t][index];
        }
        else
            return err;
    else
        return err;
}

void Board::replacePiece(NAMES n, TYPE t, int i, Piece mod) {
    pieces[n][t][i] = mod;
    populateTeamBoards();
}

void Board::deletePiece(NAMES n, TYPE t, int i) {
    pieces[n][t].erase(pieces[n][t].begin() + (i - 1));
}



