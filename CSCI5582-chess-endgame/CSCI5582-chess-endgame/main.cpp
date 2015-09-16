//
//  main.cpp
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#include "State_02.h"

int main(int argc, const char * argv[]) {
    Board A;
    
    // prepare initial board state with R.Reti endgame
    A.white.push_back(Piece('K',0,0));
    A.white.push_back(Piece('P',2,5));
    A.black.push_back(Piece('K',0,5));
    A.black.push_back(Piece('P',7,4));
    
    
    
    return 0;
}
