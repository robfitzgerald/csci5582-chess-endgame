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
// this version will use 2 arrays of pieces and their positions with no 'board'

const int BOARD_SIZE = 8;
enum Piece { EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING };

class Board {
public:
    Board();
    Board(Board&);
    
    void place (Piece p, int x, int y) { board[x][y] = p; };
    void remove (int x, int y) { board[x][y] = EMPTY; };
    
    std::string getMove() { return move; }
    void setMove(std::string m) { move = m; }
    
    int getHeuristic() { return heuristic; }
    void setHeuristic(int h) { heuristic = h; }
    
    char getCurrentPlayer() { return currentPlayer; }
    void setCurrentPlayer(char m) { currentPlayer = m; }
    
    void applyMove(std::string);
    void generateMoves();
    
private:
    int board[BOARD_SIZE][BOARD_SIZE];
    std::string move;  //
    char currentPlayer;  // B, W
    int heuristic;
    std::vector<std::string> possibleMoves;
    
};

// recursive function object
int state(std::string move, int, bool);
int heuristic(Board);

// helpers
int decodeFile(char file) { return file - 97; }
char encodeFile(int x) { return x + 97; }
int decodeRank(char rank) { return rank - 1; }
char encodeRank(int x) { return x + 1; }

#endif /* defined(__CSCI5582_chess_endgame__State_02__) */
