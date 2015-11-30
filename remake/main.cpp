#include <iostream>
#include "Board.h"
#include "moves.h"
#include "search.h"
int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: \n";
		return 0;
	}
	Piece p (0,PAWN,42);
	Piece q (0,KING,63);
	Piece r (1,KING,40);
	Piece s (1,PAWN,39);
	// Piece w1 (1,PAWN,15);
	// Piece w2 (1,PAWN,16);
	// Piece w3 (1,PAWN,17);
	// Piece w4 (1,PAWN,18);
	// Piece b1 (0,PAWN,9);
	// Piece b2 (0,PAWN,10);
	// Piece b3 (0,PAWN,11);
	// Piece b4 (0,PAWN,12);

	Board b;
	b.addPiece(Piece(0,PAWN,42));
	b.addPiece(Piece(0,KING,63));
	b.addPiece(Piece(1,KING,40));
	b.addPiece(Piece(1,PAWN,39));
	// b.addPiece(p);
	// b.addPiece(q);
	// b.addPiece(r);
	// b.addPiece(s);
	// b.addPiece(w1);
	// b.addPiece(w2);
	// b.addPiece(w3);
	// b.addPiece(w4);
	// b.addPiece(b1);
	// b.addPiece(b2);
	// b.addPiece(b3);
	// b.addPiece(b4);
	//b.debugListPieces();
	int result = search(b,8);
	std::cout << "best heuristic: " << result << "\n";	
	return 0;
}

