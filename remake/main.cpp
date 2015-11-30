#include <iostream>
#include "Board.h"
#include "moves.h"
#include "search.h"
int main(int argc, char** argv)
{
	int depth = 0, m = 0, n = 0;
	if (argc < 2)
	{
		std::cout << "Usage: ./rreti <depth> <m> <n>\n";
		std::cout << "where <depth> is search depth\n";
		std::cout << "      <m> and <n> are indices of the output tree data (optional)\n";
		return 0;
	}
	else if (argc < 3)
	{
		depth = atoi(argv[1]);
	}
	else if (argc < 4)
	{
		std::cout << "error: adding <m> argument requires additional <n> argument.\n";
		std::cout << "Usage: ./rreti <depth> <m> <n>\n";
		std::cout << "where <depth> is search depth\n";
		std::cout << "      <m> and <n> are indices of the output tree data (optional)\n";
		return 0;		
	}
	else if (argc >= 4)
	{
		depth = atoi(argv[1]);
		m = atoi(argv[2]);
		n = atoi(argv[3]);
	}

	Board b;
	b.addPiece(Piece(0,PAWN,42));
	b.addPiece(Piece(0,KING,63));
	b.addPiece(Piece(1,KING,40));
	b.addPiece(Piece(1,PAWN,39));
	int result = search(b,depth,m,n);
	return 0;
}

