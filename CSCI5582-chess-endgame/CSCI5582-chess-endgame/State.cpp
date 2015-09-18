#include "State.h"

void moves(Board& current) {
    for (int i = 0; i < NUM_TYPES; ++i) {
        
    }
}


int State (Board& currentBoard) {
    std::vector<Board> possiblities;
    int bestHeuristic = currentBoard.getHeuristic();
    
    // generate moves
    moves(currentBoard);
    
    // no moves, BASE CASE.  return heuristic
    if (possiblities.size() == 0)
        return bestHeuristic;
    
    // for loop
    // call minimax() on Board.heuristic;
    // call State(possiblities[i]);
    
    
    return 1;
}