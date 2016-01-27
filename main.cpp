#include <iostream>
#include "Board.h"
#include "moves.h"
#include "search.h"

void usage();

int main(int argc, char** argv)
{
	int depth = 0, m = 0, n = 0;
	if (argc < 2)
	{
		usage();
		return 0;
	}
	else if (argc < 3)
	{
		depth = atoi(argv[1]) * 2;
		m = 0 * 2;
		n = depth;
	}
	else if (argc < 4)
	{
		std::cout << "error: adding <m> argument requires additional <n> argument.\n";
		usage();
		return 0;		
	}
	else if (argc >= 4)
	{
		depth = atoi(argv[1]) * 2;
		m = atoi(argv[2]) * 2;
		n = atoi(argv[3]) * 2;
	}
	if (depth < 0)
	{
		std::cout << "error: <turns> must be a number greater than zero.\n";
		usage();
		return 0;		
	}
	if (n > depth)
	{
		std::cout << "error: <n> must be equal to or less than <turns>.\n";
		usage();
		return 0;
	}

	Board b;
	b.addPiece(Piece(0,PAWN,42));
	b.addPiece(Piece(0,KING,63));
	b.addPiece(Piece(1,KING,40));
	b.addPiece(Piece(1,PAWN,39));
	int result = search(b,depth,m,n);
	return 0;
}

void usage()
{
	std::cout << "Usage: ./rreti <turns> <m> <n>\n";
	std::cout << "where <turns> is how many turns to generate, \n";
	std::cout << "      (1 turn contains moves for both opponents)\n";
	std::cout << "      <m> and <n> specify the range of turns to print the search tree (optional)\n";
}
