#include "Piece.h"

Piece::Piece() {
    legal = true;
    board = 0;
}

Piece::Piece(const Piece& source) {
    Location pos = source.locate();
    this->place(pos.x, pos.y);
}

void Piece::clear() { board = 0; }

// returns success in storing piece location
void Piece::place(int x, int y) {
    if ( !((x + 8*y) > 63)) {               // only checking range
        this->legal = true;
        int index = x + (8*y);              // bitboard 'index'
        this->board = 1;                          // storing a bit is 2^index; start at 2^0 = 1
        if (index != 0) {                   // if index was 0, we want board = 1 and be done
            for (int i = 0; i < index; ++i) {
                board *= 2;
            }
        }
    } else {
        this->legal = false;
    }
}

Location Piece::locate() const {
    int index = -1, i = 0;
    Bitboard bit = 1;
    
    while (i < 64) {
        if ((bit & this->board) == this->board) {
            index = i;
            i = 64; // end
        }
        bit *= 2;
        ++i;
    }
    
    if (index == -1) { return Location(-1,-1); }
    
    return Location(index % 8, index / 8);
}
