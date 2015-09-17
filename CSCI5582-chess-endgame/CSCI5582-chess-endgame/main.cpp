//
//  main.cpp
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#include <iostream>
#include "State_03.h"

int main(int argc, const char * argv[]) {
    std::cout << " it begins: \n";
    Piece test;
    Location bob(0,0);
    bool good = test.place(7,7);
    if (good) {
        std::cout << " twas good \n";
        bob = test.locate();
    }
    
    std::cout << "x " << bob.x << ", y " << bob.y << "\n";
    
    Board fredward;
    fredward.pieces[0].push_back(test);
    return 0;
}
