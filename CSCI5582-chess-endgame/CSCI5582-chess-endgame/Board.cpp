#include "Board.h"
#include <iostream>

// -------------- class Board -------------------------------------------

Board::Board() {
    Piece clearPiece;
    clearPiece.clear();
    this->pieces[WHITE][ALLMINE].push_back(clearPiece);
    this->pieces[BLACK][ALLMINE].push_back(clearPiece);
    this->pieces[WHITE][ALLTHEIRS].push_back(clearPiece);
    this->pieces[BLACK][ALLTHEIRS].push_back(clearPiece);
    move = "";
}

Board::Board(const Board& source) {
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        for (int j = 0; j < NUM_TYPES; ++j) {
            this->pieces[i][j] = source.pieces[i][j];
        }
    }
    populateTeamBoards();
    this->move = source.getMove();
}

void Board::populateTeamBoards() {
    std::cout << "populate team boards called()" << std::endl;
    this->pieces[WHITE][ALLMINE][0].clear();
    this->pieces[WHITE][ALLTHEIRS][0].clear();
    this->pieces[BLACK][ALLMINE][0].clear();
    this->pieces[BLACK][ALLTHEIRS][0].clear();
    // type '0' is 'EMPTY' - we ignore that guy
    for (int i = 1; i < NUM_TYPES - NUM_PLAYERS; ++i) {
        size_t whitePc = pieces[WHITE][i].size();
        size_t blackPc = pieces[BLACK][i].size();
        for (int j = 0; j < whitePc; ++j) {
            Location l = pieces[WHITE][i][j].locate();
            std::cout << "this piece is at " << l.x << "," << l.y << "\n";
            pieces[WHITE][ALLMINE][0].board = pieces[WHITE][ALLMINE][0].board | pieces[WHITE][i][j].board;
            pieces[BLACK][ALLTHEIRS][0].board = pieces[BLACK][ALLTHEIRS][0].board | pieces[WHITE][i][j].board;
            std::cout << "adding " << i << "th type, " << j << "th piece to white allboard." << std::endl;
            std::cout << "looks like this now: " << pieces[WHITE][ALLMINE][0].board << std::endl;
            pieces[WHITE][ALLMINE][0].debugPrintBoard();
        }
        for (int j = 0; j < blackPc; ++j) {
            pieces[BLACK][ALLMINE][0].board = pieces[BLACK][ALLMINE][0].board | pieces[WHITE][i][j].board;
            pieces[WHITE][ALLTHEIRS][0].board = pieces[BLACK][ALLTHEIRS][0].board | pieces[BLACK][i][j].board;
        }
    }
}

// obsolete - i exposed bitboard
Piece& Board::exposeBoard(NAMES pl, TYPE t, int i) {
    return pieces[pl][t][i];
}

std::string Board::getChessMove() {
    std::string output;
    output.push_back(97 + move[0]);
    output.push_back(1 + move[1]);
    output.push_back(97 + move[2]);
    output.push_back(1 + move[3]);
    return output;
}

void Board::setPiece(NAMES pl, TYPE t, Piece pc) {
    //if (0 <= pl) // && pl < NUM_PLAYERS)
    pieces[pl][t].push_back(pc);
    populateTeamBoards();
}

Piece Board::getPiece(NAMES pl, TYPE t, int index) {
    Piece err(-1,-1);
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





