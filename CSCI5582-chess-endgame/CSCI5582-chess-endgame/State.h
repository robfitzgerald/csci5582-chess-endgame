#ifndef __CSCI5582_chess_endgame__State__
#define __CSCI5582_chess_endgame__State__

#include <vector>
#include "Board.h"

// build the tree of possible moves
void Tree (Board&);
int State (Board&, int, int);
void moves(Board&, std::vector<Board>&);

// minimax functions
bool applyCutoff(int, int, int);
int heuristic(Board&);

// move generators
void generatePawnMoves(Board&, std::vector<Board>&);
void generateKingMoves(Board&, std::vector<Board>&);


// helper functions
bool isOnBoard(Location);
bool noBuddies(Board&, TYPE, Piece);
char getPieceChar(TYPE);
std::string getChessNotation(TYPE, int, int, int, int);

#endif /* defined(__CSCI5582_chess_endgame__State__) */
