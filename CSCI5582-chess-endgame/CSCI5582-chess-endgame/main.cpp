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
    
    Tree(rReti);
    
    return 0;
}
