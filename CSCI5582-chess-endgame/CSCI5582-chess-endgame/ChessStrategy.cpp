#include "ChessStrategy.h"

// v1.0.0 - not worry about bitboard move operations (x,y is fine)


void Pawn::generateMoves(Board& game, std::vector<Board>*& possibilities) {
    size_t numPawns = game.getPieceCount(game.getPlayer(), PAWN);
    int direction;
    if (game.getPlayer() == 0) {
        direction = 1;
    } else {
        direction = -1;
    }
    for (int i = 0; i < numPawns; ++i) {
        Piece thisPiece = game.getPiece(game.getPlayer(), PAWN, i);
        Location check = thisPiece.locate();
        for (int j = -1; j < 2; ++j) {
            Location newPos = check;
            newPos.x += j;
            newPos.y += direction;
            Piece move = thisPiece;
            
            if (testRange(move.locate()) && noBuddies(move)) {
                Board* temp = new Board;
                
            }
        }
    }
}

void King::generateMoves(Board& game, std::vector<Board>& possibilities) {
    
}

void Queen::generateMoves(Board& game, std::vector<Board>& possibilities) {
    
}

bool testRange(Location here) {
    
    return true;
}
