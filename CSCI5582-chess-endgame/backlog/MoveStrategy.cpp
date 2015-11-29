#include "MoveStrategy.h"
#include <iostream>

// Global initialization to facilitate singleton design pattern
MoveStrategy* MoveStrategy::mpoSssInstance = 0;

MoveStrategy* MoveStrategy::instance() {
    if(mpoSssInstance == 0) std::cout << "Class has not been created" << std::endl;
        return mpoSssInstance;
}

bool MoveStrategy::exists() {
    return (mpoSssInstance != NULL); // Return true/false
}
