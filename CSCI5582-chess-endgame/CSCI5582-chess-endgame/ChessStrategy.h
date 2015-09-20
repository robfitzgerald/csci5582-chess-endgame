#ifndef __CSCI5582_chess_endgame__ChessPiece__
#define __CSCI5582_chess_endgame__ChessPiece__

#include <vector>
#include "Board.h"

class MovePawn {
public:
    static MovePawn& instance() {
        static MovePawn source;
        m_pInstance = &source;
        return *m_pInstance;
    };
    void generateMoves(Board&, std::vector<Board>&);
private:
    MovePawn(){};
    MovePawn(MovePawn const&){};
    MovePawn& operator=(const MovePawn& source){
        if (this != &source) {
            m_pInstance = source.m_pInstance;
        }
        return *this;
    };
    static MovePawn* m_pInstance;
};

class MoveKing {
public:
    static void instance();
    void generateMoves(Board&, std::vector<Board>&);
protected:
    MoveKing(){};
    MoveKing(MoveKing const&){};
//    MoveKing& operator=(MoveKing const&){};
    static MoveKing* m_pInstance;
};



class MoveQueen {
public:
    static void instance();
    void generateMoves(Board&, std::vector<Board>&);
private:
    MoveQueen(){};
    MoveQueen(MoveQueen const&){};
//    MoveQueen& operator=(MoveQueen const&){};
    static MoveQueen* m_pInstance;
};


bool isOnBoard(Location here);
bool noBuddies(Board&, TYPE, Piece);

#endif /* defined(__CSCI5582_chess_endgame__ChessPiece__) */
