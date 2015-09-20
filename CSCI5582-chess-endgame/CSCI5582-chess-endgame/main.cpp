#include "State.h"
#include "Board.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    std::cout << " it begins: \n";
    Piece test(4,4);
    Piece block(4,5);
    
    
    
    Board fred;
    std::vector<Board> possibilities;
    
    fred.setPiece(WHITE,PAWN,test);
    fred.setPiece(WHITE,KING,block);
    fred.setPlayer(WHITE);
    Location t2 = fred.getPiece(WHITE, PAWN, 0).locate();
    std::cout << " that was: " << t2.x << "," << t2.y << ", and now, into Tree()" << std::endl;
    
    Tree(fred);
    
    //MovePawn::instance().generateMoves(fred,possibilities);
    
    return 0;
}
