//
//  State_02.cpp
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#include "State_02.h"


int state(Board currentState, int heuristic, bool min) {
    int level;  // depth of search, stop if level >= SOME_DEPTH_CONSTANT
    
    // make possible states
    
    // if none possible, you're at the bottom, which is where you generate
    // values that will be returned.  otherwise, you're supposed to just
    // blindly pass the min or max of what's been passed to you.
    
    // 
    
    
    std::vector<Board> possibleStates;
    for (int i = 0; i < possibleStates.size(); ++i) {
        // something like,
        possibleStates[0].heuristic = state(possibleStates[0], 0, true);
    }
    
    return 0;
};