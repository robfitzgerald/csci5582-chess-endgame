#include "State.h"
#include <iostream>
#include <vector>
#include <string>

const int DEPTH = 3;
const int UNSET = 999;


void Tree (Board& startState) {
    
    int topH = State(startState, 1, UNSET);
    
    std::cout << "final heuristic at the top? " << topH;
}


int State (Board& currentBoard, int level, int parentHeuristic) {
    std::cout << "start of new state() at level " << level << "\n";
    Piece all = currentBoard.getPiece(WHITE, ALLMINE, 0);
    all.board = all.board | currentBoard.getPiece(BLACK, ALLMINE, 0).board;
    all.debugPrintBoard();
    std::cout << std::endl;
    
    int bestHeuristic = UNSET;
    
    // base case 1: node at cutoff depth
    if (level == DEPTH) {
        return heuristic(currentBoard);
    }
    
    std::vector<Board> possiblities;
    
    // generate moves
    moves(currentBoard, possiblities);
    
    // base case : no possible moves, must be a leaf
    if (possiblities.size() == 0)
        return bestHeuristic;
    
    // for loop
    // call minimax() on Board.heuristic;
    // call State(possiblities[i]);
    
    for (int i = 0; i < possiblities.size(); ++i) {
        if (bestHeuristic != UNSET) {
            // minimax() comparing parentHeuristic + bestHeuristic
        }
        std::cout << "possibility " << i << " exists.\n";
        bestHeuristic = State(possiblities[i], level + 1, bestHeuristic);
        std::cout << "  move is: " << possiblities[i].getMove() << " with heuristic " << possiblities[i].getHeuristic() << std::endl;
    }
    
    return 1;
}


// tried to do something to iterate through generateMoves() for each
// ChessStrategy i have, by making an array of singletons...
// not the best design pattern it turns out (fail)
// v2 : solve programmatic strategy iteration
void moves(Board& current, std::vector<Board>& possibilities) {
    generatePawnMoves(current, possibilities);
    generateKingMoves(current, possibilities);
    //MoveQueen::instance()->generateMoves(current, possibilities);
}


int heuristic(Board& currentBoard) {
    std::vector<int> players (2,0);
    for (int i = 0; i < NUM_PLAYERS; ++i) {                     // players
        for (int j = 1; j < NUM_TYPES - NUM_PLAYERS; ++j) {     // types
            int weightedValue = (int) currentBoard.getPieceCount((NAMES) i, (TYPE) j);
            for (int k = 0; k < (int) j; ++k) {
                weightedValue *= 2;
            }
            players[i] += weightedValue;
        }
    }
    return players[0] - players[1];
}


void generatePawnMoves(Board& game, std::vector<Board>& possibilities) {
    
    size_t numPawns = game.getPieceCount(game.getPlayer(), PAWN);
    int moveDirection;
    if (game.getPlayer() == WHITE) {
        moveDirection = 1;
    } else {
        moveDirection = -1;
    }
    
    for (int i = 0; i < numPawns; ++i) {
        NAMES thisGuy = game.getPlayer();
        Piece thisPiece = game.getPiece(thisGuy, PAWN, i);
        Location current = thisPiece.locate();
        
        // pawn can move diag left, up, diag right
        for (int j = -1; j < 2; ++j) {
            
            // - setup for testing move validity -
            
            Location newPos = current;
            newPos.x += j;
            newPos.y += moveDirection;
            Piece move(newPos.x, newPos.y);
            bool invalidAttack = false;
            
            if (j != 0) {
                // attack - test for opponent
                Piece opponent = game.getPiece(WHITE,ALLTHEIRS,0);
                if ((move.board | opponent.board) != opponent.board) {
                    // attack didn't attack opponent
                    invalidAttack = true;
                }
            }
            
            // since we are using x,y, a bad move is a simple check
            // also check that we aren't writing over a 'buddy'
            if (isOnBoard(newPos) && noBuddies(game, PAWN, move) && !(invalidAttack)) {
                Board temp = game;
                temp.replacePiece(game.getPlayer(), PAWN, i, move);
                
                Location oldPos = game.getPiece(thisGuy, PAWN, i).locate();
                Location newPos = temp.getPiece(thisGuy, PAWN, i).locate();
                temp.setMove(getChessNotation(KING, oldPos.x, oldPos.y, newPos.x, newPos.y));
                
                // <--- not setting heuristic but we need the MOVE string

                possibilities.push_back(temp);
                std::cout << "added one to possibilities, now has size(): " << possibilities.size() << std::endl;
            }
        }
    }
}

void generateKingMoves(Board& game, std::vector<Board>& possibilities) {
    
    size_t numKings = game.getPieceCount(game.getPlayer(), KING);
    
    for (int i = 0; i < numKings; ++i) {
        NAMES thisGuy = game.getPlayer();
        Piece thisPiece = game.getPiece(thisGuy, KING, i);
        Location current = thisPiece.locate();
        
        // king can move 1 in any direction
        for (int x = -1; x < 2; ++x) {
            for (int y = -1; y < 2; ++y) {
                // - setup for testing move validity -
                
                Location newPos = current;
                newPos.x += x;
                newPos.y += y;
                Piece move(newPos.x, newPos.y);
//                bool invalidAttack = false;
//                
//                Piece opponent = game.getPiece(WHITE,ALLTHEIRS,0);
//                if ((move.board | opponent.board) != opponent.board) {
//                    // attack didn't attack opponent
//                    invalidAttack = true;
//                }
                
                // since we are using x,y, a bad move is a simple check
                // also check that we aren't writing over a 'buddy'
                if (isOnBoard(newPos) && noBuddies(game, KING, move) && ((x + y) != 0)) {
                    Board temp = game;
                    temp.replacePiece(game.getPlayer(), KING, i, move);
                    
                    Location oldPos = game.getPiece(thisGuy, KING, i).locate();
                    Location newPos = temp.getPiece(thisGuy, KING, i).locate();
                    temp.setMove(getChessNotation(KING, oldPos.x, oldPos.y, newPos.x, newPos.y));
                    
                    // <--- not setting heuristic but we need the MOVE string
                    
                    possibilities.push_back(temp);
                    std::cout << "added one to possibilities, now has size(): " << possibilities.size() << std::endl;
                }
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
    //std::cout << "in noBuddies call \n";
    Piece all = board.getPiece(board.getPlayer(), ALLMINE, 0);

    // taking the OR of the future move and the current should be > just the current
    // UNLESS the move ends up illegally stepping on a member of this team, which we
    // want to say would disrupt their list of 'buddies'
    
    if ((m.board | all.board) == all.board) {
        return false;
    }
    return true;
}

char getPieceChar(TYPE t) {
    switch(t) {
        case EMPTY:
            return ' ';
            break;
        case KING:
            return 'K';
            break;
        case QUEEN:
            return 'Q';
            break;
        case BISHOP:
            return 'B';
            break;
        case KNIGHT:
            return 'K';
            break;
        case ROOK:
            return 'R';
            break;
        case PAWN:
            return 'P';
            break;
        case ALLMINE:
            return '>';
            break;
        case ALLTHEIRS:
            return '<';
            break;
        default:
            return '?';
    }
    
}

std::string getChessNotation(TYPE t, int x1, int y1, int x2, int y2) {
    std::string output;
    output.push_back(getPieceChar(t));
    output.push_back(97 + x1);
    output.push_back(49 + y1);
    output.push_back('-');
    output.push_back(97 + x2);
    output.push_back(49 + y2);
    return output;
}
