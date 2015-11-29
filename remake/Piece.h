#ifndef p1_remake_piece_h
#define p1_remake_piece_h

#include <cassert>
enum TYPE { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

class Piece 
{
public:
	Piece(int pl, TYPE t, int po): player(pl), type(t), pos(po) 
	{
		assert(pos >= 0 && pos < 64);
	}
	void setType(TYPE t) { type = t; }
	TYPE getType() { return type; }
	int getPlayer() { return player; }
	void setPlayer(int p) { player = p; }
	void setPos(int x, int y)
	{
		pos = (y * 8) + x;
		assert(pos >= 0 && pos < 64);
	}
	void setPos(int p) { pos = p; }
	int getPos() { return pos; }
private:
	int player;
	int pos;
	TYPE type;
};

#endif