#include "Board.h"

// -------------- class Board -------------------------------------------

Board::Board() {
    Piece clearPiece;
    clearPiece.clear();
    this->pieces[0][ALLMINE].push_back(clearPiece);
    this->pieces[1][ALLMINE].push_back(clearPiece);
    this->pieces[0][ALLTHEIRS].push_back(clearPiece);
    this->pieces[1][ALLTHEIRS].push_back(clearPiece);
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
    this->pieces[0][ALLMINE][0].clear();
    this->pieces[1][ALLMINE][0].clear();
    this->pieces[0][ALLTHEIRS][0].clear();
    this->pieces[1][ALLTHEIRS][0].clear();
    // type '1' is 'Empty' - we ignore that guy
    for (int i = 1; i < NUM_TYPES - NUM_PLAYERS; ++i) {
        size_t whitePc = pieces[0][i].size();
        size_t blackPc = pieces[1][i].size();
        for (int j = 0; j < whitePc; ++j) {
            pieces[0][ALLMINE][0].board = pieces[0][ALLMINE][0].board | pieces[0][i][j].board;
            pieces[1][ALLTHEIRS][0].board = pieces[1][ALLTHEIRS][0].board | pieces[0][i][j].board;
        }
        for (int j = 0; j < blackPc; ++j) {
            pieces[0][ALLTHEIRS][0].board = pieces[0][ALLTHEIRS][0].board | pieces[0][i][j].board;
            pieces[1][ALLMINE][0].board = pieces[1][ALLMINE][0].board | pieces[0][i][j].board;
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
    if (0 <= pl) // && pl < NUM_PLAYERS)
        pieces[pl][t].push_back(pc);
}

Piece Board::getPiece(NAMES pl, TYPE t, int index) {
    Piece err(-1,-1);
    if (0 <= pl) // && pl < NUM_PLAYERS)
        if (0 <= index && index < pieces[pl][t].size())
            return pieces[pl][t][index];
        else
            return err;
    else
        return err;
}

void Board::replacePiece(NAMES n, TYPE t, int i, Piece mod) {
    pieces[n][t][i] = mod;
}
