#include "State.h"
#include <iostream>


// tried to do something to iterate through generateMoves() for each
// ChessStrategy i have, by making an array of singletons...
// not the best design pattern it turns out (fail)
// v2 : solve programmatic strategy iteration
void moves(Board& current, std::vector<Board>& possibilities) {
    MovePawn::instance().generateMoves(current, possibilities);
    //MoveKing::instance()->generateMoves(current, possibilities);
    //MoveQueen::instance()->generateMoves(current, possibilities);
}

int State (Board& currentBoard) {
    std::vector<Board> possiblities;
    int bestHeuristic = currentBoard.getHeuristic();
    
    // generate moves
    moves(currentBoard, possiblities);
    
    // no moves, BASE CASE.  return heuristic
    if (possiblities.size() == 0)
        return bestHeuristic;
    
    // for loop
    // call minimax() on Board.heuristic;
    // call State(possiblities[i]);
    
    for (int i = 0; i < possiblities.size(); ++i) {
        // this should be where we compare heuristics
        Location test = possiblities[i].getPiece(WHITE, PAWN, 0).locate();
        std::cout << "possibility " << i << " exists.\n";
        std::cout   << "(x,y) " << test.x << ", " << test.y << "\n";
    }
    
    return 1;
}

void Tree (Board& startState) {

    State(startState);
}