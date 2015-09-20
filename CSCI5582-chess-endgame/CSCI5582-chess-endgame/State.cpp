#include "State.h"
#include <iostream>


// tried to do something to iterate through generateMoves() for each
// ChessStrategy i have, by making an array of singletons...
// not the best design pattern it turns out (fail)
// v2 : solve programmatic strategy iteration
void moves(Board& current, std::vector<Board>& possibilities) {
    generatePawnMoves(current, possibilities);
    //MoveKing::instance()->generateMoves(current, possibilities);
    //MoveQueen::instance()->generateMoves(current, possibilities);
}

int State (Board& currentBoard) {
    std::vector<Board> possiblities;
    int bestHeuristic = currentBoard.getHeuristic();
    
    std::cout << "entering state \n";
    Piece test2 = currentBoard.getPiece(currentBoard.getPlayer(), ALLMINE, 0);
    test2.debugPrintBoard();
    std::cout << "is it the print sequence? \n";
    Piece test3 = currentBoard.getPiece(currentBoard.getPlayer(), ALLMINE, 0);
    test3.debugPrintBoard();
    
    // generate moves
    moves(currentBoard, possiblities);
    
    // no moves, BASE CASE.  return heuristic
    if (possiblities.size() == 0)
        return bestHeuristic;
    
    // for loop
    // call minimax() on Board.heuristic;
    // call State(possiblities[i]);
    
    for (int i = 0; i < possiblities.size(); ++i) {
        // this should be where we compare heuristics
        Location test = possiblities[i].getPiece(WHITE, PAWN, 0).locate();
        std::cout << "possibility " << i << " exists.\n";
        std::cout   << "(x,y) " << test.x << ", " << test.y << "\n";
    }
    
    return 1;
}

void Tree (Board& startState) {

    State(startState);
}

void generatePawnMoves(Board& game, std::vector<Board>& possibilities) {
    std::cout << "generatePawnMoves() \n";
    
    std::cout << "current player: " << game.getPlayer() << "\n";
    Piece all = game.getPiece(game.getPlayer(), ALLMINE, 0);
    std::cout << "all moves: \n";
    all.debugPrintBoard();
    
    size_t numPawns = game.getPieceCount(game.getPlayer(), PAWN);
    int direction;
    if (game.getPlayer() == WHITE) {
        direction = 1;
    } else {
        direction = -1;
    }
    
    std::cout << "before outer for loop in generatePawnMoves() \n";
    Piece test3 = game.getPiece(game.getPlayer(), ALLMINE, 0);
    test3.debugPrintBoard();
    
    for (int i = 0; i < numPawns; ++i) {
        NAMES thisGuy = game.getPlayer();
        Piece thisPiece = game.getPiece(thisGuy, PAWN, i);
        Location current = thisPiece.locate();
        
        std::cout << "before inner for loop in generatePawnMoves() \n";
        Piece test2 = game.getPiece(game.getPlayer(), ALLMINE, 0);
        test2.debugPrintBoard();
        
        // pawn can move diag left, up, diag right
        for (int j = -1; j < 2; ++j) {
            Location newPos = current;
            newPos.x += j;
            newPos.y += direction;
            Piece move(newPos.x, newPos.y);
            //std::cout << "trying out a new move... \n";
            //move.debugPrintBoard();
            
            // since we are using x,y, a bad move is a simple check
            // also check that we aren't writing over a 'buddy'
            
            
            std::cout << "before noBuddies call \n";
            Piece all = game.getPiece(game.getPlayer(), ALLMINE, 0);
            all.debugPrintBoard();
            
            if (isOnBoard(newPos) && noBuddies(game, PAWN, move)) {
                std::cout << "if (isOnBoard(newPos) && noBuddies(game, PAWN, move)) => true \n";
                Board temp = game;
                temp.replacePiece(game.getPlayer(), PAWN, i, move);
                
                Piece seeAll = temp.getPiece(WHITE, ALLMINE, 0);
                //seeAll.debugPrintBoard();
                
                possibilities.push_back(temp);
            }
        }
    }
}

bool isOnBoard(Location here) {
    if (here.x < 0 || here.x >= 8 || here.y < 0 || here.y >= 8)
        return false;
    return true;
}

bool noBuddies(Board& board, TYPE t, Piece m) {
    std::cout << "in noBuddies call \n";
    Piece all = board.getPiece(board.getPlayer(), ALLMINE, 0);
    all.debugPrintBoard();
//    std::cout << "current player: " << board.getPlayer() << "\n";
//    std::cout << "all moves: \n";
//    all.debugPrintBoard();
//    std::cout << "new move: \n";
//    m.debugPrintBoard();
    // taking the OR of the future move and the current should be > just the current
    // UNLESS the move ends up illegally stepping on a member of this team, which we
    // want to say would disrupt their list of 'buddies'
    
    if ((m.board | all.board) == all.board) {
        return false;
    }
    return true;
}
