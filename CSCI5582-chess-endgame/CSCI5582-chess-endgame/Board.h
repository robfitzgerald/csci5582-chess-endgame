#ifndef __CSCI5582_chess_endgame__State_02__
#define __CSCI5582_chess_endgame__State_02__

#include <vector>
#include <string>
#include "Piece.h"

const int NUM_PLAYERS = 2;
enum NAMES { WHITE, BLACK };
const int NUM_TYPES = 9;
// the last $NUM_PLAYERS of TYPE enum should be named for all player groups
enum TYPE { EMPTY, KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, ALLMINE, ALLTHEIRS };

//class Empty: public Piece {
//public:
//    typedef Piece super;
//    Empty() {
//        super::place(-1,-1);
//    }
//};

class Board {
public:
    Board();
    Board(const Board&);
    
    void setPiece(NAMES, TYPE, Piece);
    Piece getPiece(NAMES, TYPE, int);
    size_t getPieceCount(NAMES player, TYPE type) {
        return pieces[player][type].size();
    }
    
    std::string getMove() { return move; }
    std::string getChessMove();
    std::string getMove() const { return move; }

    
    void setHeuristic(int h) { heuristic = h; }
    int getHeuristic() { return heuristic; }
    int getHeuristic() const { return heuristic; }
    
    void setPlayer(NAMES pl) { currentPlayer = pl; }
    NAMES getPlayer() { return currentPlayer; }
    NAMES getPlayer() const { return currentPlayer; }
private:
    void populateTeamBoards();
    Piece& exposeBoard(NAMES, TYPE, int);
    
    std::string move;
    std::vector<Piece> pieces [NUM_PLAYERS][NUM_TYPES];
    NAMES currentPlayer;
    int heuristic;
};


#endif /* defined(__CSCI5582_chess_endgame__State_02__) */
