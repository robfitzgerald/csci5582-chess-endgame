#ifndef MoveStrategy_h
#define MoveStrategy_h

#include "Board.h"

class MoveStrategy {
    virtual void moveStrategy(Board&, std::vector<Board>&) = 0;
};

#endif