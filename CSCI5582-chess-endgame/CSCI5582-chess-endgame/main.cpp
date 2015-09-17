//
//  main.cpp
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#include <iostream>
#include "Board.h"

int main(int argc, const char * argv[]) {
    std::cout << " it begins: \n";
    Piece test(4,5);
    
    Board fredward;
    fredward.setPiece(0,0,test);
    Location result = fredward.getPiece(0,0,0).locate();
    std::cout << "location is " << result.x << ", " << result.y;
    return 0;
}
