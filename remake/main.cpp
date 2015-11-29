#include <iostream>
#include "Board.h"
#include "moves.h"
#include "search.h"
int main()
{
	Piece p (0,PAWN,3);
	Piece q (0,KING,16);
	Piece r (1,KING,13);
	Piece s (1,PAWN,20);
	Board b;
	b.addPiece(p);
	b.addPiece(q);
	b.addPiece(r);
	b.addPiece(s);
	b.debugListPieces();
	search(b,12);	
	return 0;
}

