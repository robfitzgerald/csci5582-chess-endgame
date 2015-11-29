#ifndef p1_remake_moves_h
#define p1_remake_moves_h

#include <vector>
#include <string>
#include "Board.h"

std::vector<Board> generateMoves(std::vector<Piece * >,Board);
void pawnMoves(std::vector<Board>&,Board,Piece*);
void queenMoves(std::vector<Board>&,Board,Piece*);
void queenSearch(std::vector<int>&, int, int, int, int, Board);
void kingMoves(std::vector<Board>&,Board,Piece*);
char getPieceChar(TYPE);
std::string getChessNotation(TYPE,int,int,int,int);

#endif
