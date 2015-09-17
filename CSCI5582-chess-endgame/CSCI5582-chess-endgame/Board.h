#ifndef __CSCI5582_chess_endgame__State_02__
#define __CSCI5582_chess_endgame__State_02__

#include <vector>
#include <string>

typedef uint64_t Bitboard;

const int NUM_PLAYERS = 2;
enum NAMES { WHITE, BLACK };
const int NUM_TYPES = 7;
enum TYPE { EMPTY, KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN };

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

private:
    char type;
    Bitboard board;
};

class Board {
public:
    Board();
    Board(Board&);
    
    void setPiece(int, int, Piece);
    Piece getPiece(int, int, int);
    
    std::string getMove() { return move; }
    std::string getChessMove();
    
private:
    std::string move;
    std::vector<Piece> pieces [NUM_PLAYERS][NUM_TYPES];
};


#endif /* defined(__CSCI5582_chess_endgame__State_02__) */
