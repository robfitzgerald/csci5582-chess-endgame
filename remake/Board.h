#ifndef p1_remake_Board_h
#define p1_remake_Board_h

#include "Piece.h"
#include <cstdlib>
#include <vector>
#include <string>

typedef uint64_t Bitboard;

class Board
{
public:
	Board(){};
	Board(const Board&);
	void addPiece(Piece p) { pieces.push_back(p); }
	Piece& getPiece(int, TYPE);
	Piece copyPiece(int) const;
	Piece* refByPosition(int);
	std::vector<Piece *> getPieces(int);
	int numPieces() const;
	Bitboard boardByPiece(int);
	bool move(Piece*,int);
	std::string moveName;
	void debugListPieces();
private:
	bool deleteEnemyAtPosition(Piece);
	bool checkNoFriendlies(Piece, int);
	Piece& _find(int,TYPE);
	std::vector<Piece> pieces;
};

#endif

/*
	getters and setters
		add a piece by type, player and location
		get a piece by location
		get a piece by player
		get all pieces by player
	boards
		construct a Bitboard with a single piece on it
		construct a Bitboard with all pieces
		construct a Bitboard with all pieces by one player on it
		construct a board with a possible move (logic not here)
*/