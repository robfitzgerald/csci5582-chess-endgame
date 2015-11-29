#include "ChessStrategy.h"

// v1.0.0 - not worry about bitwise board move operations


MovePawn* MovePawn::m_pInstance = NULL;

void MovePawn::generateMoves(Board& game, std::vector<Board>& possibilities) {
    size_t numPawns = game.getPieceCount(game.getPlayer(), PAWN);
    int direction;
    if (game.getPlayer() == WHITE) {
        direction = 1;
    } else {
        direction = -1;
    }
    for (int i = 0; i < numPawns; ++i) {
        Piece thisPiece = game.getPiece(game.getPlayer(), PAWN, i);
        Location current = thisPiece.locate();
        
        // pawn can move diag left, up, diag right
        for (int j = -1; j < 2; ++j) {
            Location newPos = current;
            newPos.x += j;
            newPos.y += direction;
            Piece move(newPos.x, newPos.y);
            
            // since we are using x,y, a bad move is a simple check
            // also check that we aren't writing over a 'buddy'
            if (isOnBoard(newPos) && noBuddies(game, PAWN, move)) {
                Board temp = game;
                temp.replacePiece(game.getPlayer(), PAWN, i, move);
                possibilities.push_back(temp);
            }
        }
    }
}


MoveKing* MoveKing::m_pInstance = NULL;

void MoveKing::generateMoves(Board& game, std::vector<Board>& possibilities) {
    
}


MoveQueen* MoveQueen::m_pInstance = NULL;

void MoveQueen::generateMoves(Board& game, std::vector<Board>& possibilities) {
    
}

bool isOnBoard(Location here) {
    if (here.x < 0 || here.x >= 8 || here.y < 0 || here.y >= 8)
        return false;
    return true;
}

bool noBuddies(Board& board, TYPE t, Piece m) {
    Piece all = board.getPiece(board.getPlayer(), ALLMINE, 0);
    // taking the OR of the future move and the current should be > just the current
    // UNLESS the move ends up illegally stepping on a member of this team, which we
    // want to say would disrupt their list of 'buddies'
    if ((m.board | all.board) == all.board) {
        return false;
    }
    return true;
}