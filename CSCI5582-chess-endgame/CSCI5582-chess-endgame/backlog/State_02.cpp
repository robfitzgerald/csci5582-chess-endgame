//
//  State_02.cpp
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#include "State_02.h"

Board::Board() {
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            board[i][j] = EMPTY;
        }
    }
}

Board::Board(Board& source) {
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            board[i][j] = source.board[i][j];
        }
    }
    this->setCurrentPlayer(source.getCurrentPlayer());
    //this->setMove(source.getMove());      <---- NO! unique for each board.
    this->setHeuristic(source.getHeuristic());
}

void Board::applyMove(std::string givenMove)
{
    
    // givenMove is the generated move-string we want to apply to this state
    // this happens once, after a copy constructor has completed a copy.
    // we didn't copy over the source's move string. that is associated with the
    // source's state. so, we will store this move string in this Board. then
    // we will apply the meaning of it to the board (look for the piece that should
    // be moved, and move it accordingly).
    
    // chess notation: [PQK][a-h][1-8]-[a-h][1-8]
    //                 0    1    2    34    5
    
    move = givenMove;
    
    char movePiece = move[0];
    int oldRank = (int) move[1];
    int oldFile = (int)  move[2];
    int newRank = (int)  move[4];
    int newFile = (int)  move[5];
    
    // cheesy search and update
    if (board[oldRank][oldFile] == movePiece) {
        // remove old, add new
        board[oldRank][oldFile] = EMPTY;
        board[newRank][newFile] = movePiece;
    } else
    {
        // error: expected what got somebizniss
    }
}

void Board::generateMoves()
{
    
    // look at currentPlayer. i mean, look at the guy.
    // always good to look your competition in the eye.
    // k, next up...
    // we are going to iterate through one player's pieces, and generate
    // a list of possible moves from this current board state.
    
    // cheesy search and update
    if (currentPlayer == 'B') {
        for (int p = 0; p < black.size(); ++p)
        {
            if (black[p].type == 'P')
            {
                // do pawn things
                
                // 
                
                
            } else if (black[p].type == 'K')
            {
                // do king things
            } else
            {
                // we're doing queen things
            }
        }
    } else
    {
        for (int p = 0; p < white.size(); ++p)
        {
            
        }
    }
    
    
}

int state(std::string currentState, int heuristic, bool min)
{
    int level;  // depth of search, stop if level >= SOME_DEPTH_CONSTANT
    level = 4; // level may need to be a parameter..
    
    // make possible states
    
    // if none possible, you're at the bottom, which is where you generate
    // values that will be returned.  otherwise, you're supposed to just
    // blindly pass the min or max of what's been passed to you.
    
    // 
    
    
    std::vector<Board> possibleStates;
    for (int i = 0; i < possibleStates.size(); ++i)
    {
        // something like,
        possibleStates[0].setHeuristic(state(possibleStates[0].getMove(), 0, true));
    }
    
    return 0;
};