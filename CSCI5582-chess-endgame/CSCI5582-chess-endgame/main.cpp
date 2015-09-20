#include "State.h"
#include "Board.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    std::cout << " it begins: \n";
    
    Board rReti;
    std::vector<Board> possibilities;
    
    rReti.setPiece(WHITE,PAWN,Piece(2,5));
    rReti.setPiece(WHITE,KING,Piece(7,7));
    rReti.setPiece(BLACK,PAWN,Piece(7,4));
    rReti.setPiece(BLACK,KING,Piece(0,5));
    rReti.setPlayer(WHITE);
    Location t2 = rReti.getPiece(WHITE, PAWN, 0).locate();
    std::cout << " that was: " << t2.x << "," << t2.y << ", and now, into Tree()" << std::endl;
    
    Tree(rReti);
    
    return 0;
}
