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
#include "State.h"
#include "Board.h"
#include <iostream>

int main(int argc, const char * argv[]) {

//    Bitboard a = 4, b = 8;
//    
//    std::cout << "a, b: " << a << " " << b << std::endl;
//    Bitboard c = a ^ b;
//    Bitboard d = a & b;
//    std::cout << "c = a ^ b, d = a & b\n";
//    std::cout << c << "          " << d << std::endl;

//    Piece clearPiece;
//    clearPiece.clear();
//    Location clr = clearPiece.locate();
//    std::cout << clr.x << "," << clr.y << " is clearpiece\n";
//    
//    std::cout << EMPTY << " " << WHITE << " " << PAWN << " \n";
    
    
    std::cout << " it begins: \n";
    Piece test(4,4);
    
    Board fred;
    std::vector<Board> possibilities;

    fred.setPiece(WHITE,PAWN,test);
    
    Tree(fred);
    
    //MovePawn::instance().generateMoves(fred,possibilities);
    
    return 0;
}
