#ifndef __CSCI5582_chess_endgame__State_02__
#define __CSCI5582_chess_endgame__State_02__

#include <vector>
#include <string>

// State_01 (State.h) used a 2D array of chars to represent the board.
// this version will use 2 arrays of pieces and their positions with no 'board'
// State_02 is too big. gonna switch to bitboards while i can.

typedef uint64_t Bitboard;
const int NUM_PLAYERS = 2;

struct Location {
    int x;
    int y;
    Location(int xpos, int ypos): x(xpos), y(ypos) {}
};

class Piece {
public:
    Piece();
    Piece(int x, int y) {
        place(x,y);
    }
    void clear();
    bool place(int, int);
    Location locate();
    
    void setType(char t) { type = t; }
    char getType() { return type; }
private:
    char type;
    Bitboard board;
};

class Board {
    /*
     defining a board
        a state will have 1 to m boards, m-1 being the # of possible moves
        we will init a state with 
            a board that is a copy of another state
            a move from [a-h][1-8] to [a-h][1-8] represented as a string
             in index notation ([0-7][0-7][0-7][0-7])
            the current player (again, stored in state)
            vectors of type Piece, one for each player (Board)
            
     functions need to be called to review possible moves live in State.
     so, we will expose our Pieces with some getters and setters.
     */
    // pieces[0] == white, pieces[1] == black
public:
    Board();
    Board(Board&);
    
    void setPiece(int, Piece);
    Piece getPiece(int, int);
    size_t getNumPieces(int pl) { return pieces[pl].size(); }
    
    std::string getMove() { return move; }
    std::string getChessMove();
    
private:
    std::string move;
    std::vector<Piece> pieces [NUM_PLAYERS];
};


#endif /* defined(__CSCI5582_chess_endgame__State_02__) */
