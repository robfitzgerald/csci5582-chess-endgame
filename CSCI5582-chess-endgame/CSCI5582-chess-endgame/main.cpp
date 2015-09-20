//
//  main.cpp
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

//#include "Board.h"
//#include "State.h"
#include "ChessStrategy.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    MovePawn::create();
    
//    std::cout << " it begins: \n";
//    Piece test(4,4);
//    
    Board fred;
    std::vector<Board> possibilities;
//
//    fred.setPiece(WHITE,PAWN,test);
//    Location result = fred.getPiece(WHITE,PAWN,0).locate();
//    std::cout << "board fred pawn location is " << result.x << ", " << result.y << "\n";
//    Board fredward = fred;
//    Location result2 = fredward.getPiece(WHITE,PAWN,0).locate();
//    std::cout << "fredward is a son of fred has a pawn at " << result2.x << ", " << result2.y << "\n";
//    std::cout << "team white allplayers: \n";
//    for (int i = 0; i < fredward.getPieceCount(WHITE, ALLMINE); ++i) {
//        Location result3 = fredward.getPiece(WHITE,ALLMINE,i).locate();
//        Location result4 = fredward.getPiece(BLACK,ALLTHEIRS,i).locate();
//        std::cout << "white says white has " << result3.x << ", " << result3.y << "\n";
//        std::cout << "black says white has " << result4.x << ", " << result4.y << "\n";
//    }
    
    //Tree(fred, moveStrategies);
    
    MovePawn::instance()->generateMoves(fred,possibilities);
    
    return 0;
}
