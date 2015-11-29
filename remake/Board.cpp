#include <iostream>
#include <vector>
#include "Board.h"

// returns success in storing piece location

Board::Board(const Board& source)
{
    for (int i = 0; i < source.numPieces(); ++i)
    {
        this->pieces.push_back(source.copyPiece(i));
    }
    this->moveName = source.moveName;
}

Bitboard Board::boardByPiece(int pieceIndex) {
    assert(pieceIndex < pieces.size());
    Piece p = pieces[pieceIndex];
    int bitboardValue = p.getPos();
    Bitboard board = 1;  // we will apply board^2 starting from 1 (2^0)
    assert(bitboardValue < 64 && bitboardValue >= 0);
    if (bitboardValue != 0) {
        // if index was 0, we want board = 1 and be done
        for (int i = 0; i < bitboardValue; ++i) {
            board *= 2;
        }
    }
    return board;
}

Piece& Board::getPiece(int player, TYPE type)
{
    return _find(player,type);
}

Piece Board::copyPiece(int i) const
{
    return pieces[i];
}

Piece* Board::refByPosition(int pos)
{
    for (int i = 0; i < pieces.size(); ++i)
    {
        if (pieces[i].getPos() == pos)
        {
            return &pieces[i];
        }
    }
    return 0;
}

std::vector<Piece *> Board::getPieces(int player)
{
    std::vector<Piece *> output;
    for (int i = 0; i < pieces.size(); ++i)
    {
        if (pieces[i].getPlayer() == player)
        {
            //Piece * temp = &pieces[i];
            output.push_back(&pieces[i]);
        }
    }
    return output;
}

int Board::numPieces() const
{
    return pieces.size();
}

bool Board::move(Piece* moving, int newPos) 
{
    if (moving->getPos() == newPos) {
        // moving to same location is not valid.
        std::cout << "invalid move to same pos\n";
        return false;
    }
    
    bool noFriendlies = checkNoFriendlies(*moving, newPos);
    if (!noFriendlies)
    {
        std::cout << "in move(), failed noFriendlies check.\n";
        return false;        
    }

    // move the piece.
    moving->setPos(newPos);

    deleteEnemyAtPosition(*moving);

    return true;
}

/*
    tries to delete any pieces at this location loc that
    belong to any other players than pl
*/
bool Board::deleteEnemyAtPosition(Piece attacker)
{
    for (int i = 0; i < pieces.size(); ++i)
    {
        if (pieces[i].getPlayer() != attacker.getPlayer())
        {
            if (pieces[i].getPos() == attacker.getPos())
            {
                pieces.erase(pieces.begin() + i);
                return true;
            }
        }
    }
    return false;
}

bool Board::checkNoFriendlies(Piece thisPiece, int newPos)
{
    // std::cout << "checkNoFriendlies(): \n";   
    for (int i = 0; i < pieces.size(); ++i)
    {
        // std::cout << "i: " << i << ", pieces.size(): " << pieces.size() << "\n";

        if (pieces[i].getPlayer() == thisPiece.getPlayer())
        {
            // std::cout << "found piece of same team\n";
            // std::cout << "pieces[i].getPos(): " << pieces[i].getPos() << ", newPos: " << newPos << "\n";

            if (pieces[i].getPos() == newPos)
            {
                return false;
            }
        }
    }
    return true;
}

Piece& Board::_find(int player, TYPE type)
{
    for (int i = 0; i < pieces.size(); ++i)
    {
        if (
            pieces[i].getPlayer() == player &&
            pieces[i].getType() == type
            )
            return pieces[i];
    }
    Piece * temp = new Piece(-1,EMPTY,0); 
    return *temp;
}

void Board::debugListPieces() {
    std::cout << "*****locations occupied on board*****\n";
    for (int i = 0; i < pieces.size(); ++i)
    {
        std::cout << "P" << pieces[i].getPlayer() << "-" << (int) pieces[i].getType() << "@" << pieces[i].getPos() << "  ";
    }
    std::cout << "\n\n";
}

/* from old incarat

void Board::debugPrintBoard() {
    Bitboard inc = 1;
    for(int i = 0; i < 64; ++i) {
        if ((i > 1) && ((i % 8) == 0)) {
            std::cout << std::endl;
        }
        if(board & inc)
            std::cout << " 1";
        else
            std::cout << " 0";
        inc *= 2;

    }
    std::cout << std::endl;
}*/