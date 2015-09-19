//
//  main.cpp
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#include "Board.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << " it begins: \n";
    Piece test(4,5);
    
    Board fred;
    fred.setPiece(WHITE,PAWN,test);
    Location result = fred.getPiece(WHITE,PAWN,0).locate();
    std::cout << "board fred pawn location is " << result.x << ", " << result.y << "\n";
    Board fredward = fred;
    Location result2 = fredward.getPiece(WHITE,PAWN,0).locate();
    std::cout << "fredward is a son of fred has a pawn at " << result2.x << ", " << result2.y;
    
    return 0;
}
