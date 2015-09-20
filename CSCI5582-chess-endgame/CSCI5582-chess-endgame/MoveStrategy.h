#ifndef MoveStrategy_h
#define MoveStrategy_h

#include "Board.h"

// with help from http://www.yolinux.com/TUTORIALS/C++Singleton.html

class MoveStrategy {
public:
    static MoveStrategy* instance();
    static bool exists();
    virtual void generateMoves(Board&, std::vector<Board>&) = 0;
protected:
    MoveStrategy(){};
    virtual ~MoveStrategy(){};
    static MoveStrategy* mpoSssInstance;
    
};

#endif