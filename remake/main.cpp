#include <iostream>
#include "Board.h"
#include "moves.h"
int main()
{
	Piece p (0,PAWN,3);
	Piece q (0,KING,16);
	Piece r (1,KING,13);
	Piece s (1,QUEEN,9);
	Board b;
	b.addPiece(p);
	b.addPiece(q);
	b.addPiece(r);
	b.addPiece(s);
	b.debugListPieces();
	std::vector<Board> result = generateMoves(b.getPieces(1),b);
	std::cout << "results\n";
	for (int i = 0; i < result.size(); ++i)
	{
		result[i].debugListPieces();
	}
	return 0;
}

