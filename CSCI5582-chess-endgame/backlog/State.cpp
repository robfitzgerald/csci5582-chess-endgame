//
//  State.cpp
//  CSCI5582-chess-endgame
//
//  Created by Robert Fitzgerald on 9/14/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#include <string>
#include "State.h"

void State::saveMove(std::string s) {
    move.push_back(s[0]);
    move.push_back(encodeChessFile(s[1]));
    move.push_back(encodeChessRank(s[2]));
    move.push_back('-');
    move.push_back(encodeChessFile(s[3]));
    move.push_back(encodeChessFile(s[4]));
}

char encodeChessFile(int x) {
    return x + 97;
}
char encodeChessRank(int y) {
    return y + 1;
}