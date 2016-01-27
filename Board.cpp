#include <iostream>
#include <vector>
#include <cctype>
#include "Board.h"
#include "moves.h"

// returns success in storing piece location

Board::Board(const Board& source)
{
    for (int i = 0; i < source.numPieces(); ++i)
    {
        this->pieces.push_back(source.copyPiece(i));
    }
    this->moveName = source.getMoveName();
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
        return false;
    }
    
    bool noFriendlies = checkNoFriendlies(*moving, newPos);
    if (!noFriendlies)
    {
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

// poorly implemented. next version should find more
// ways to be certain you are getting the correct piece.
// but, this will work for the only thing i need it for, which
// is finding the king.
Piece* Board::findPiece(int player, TYPE type)
{
    for (int i = 0; i < pieces.size(); ++i)
    {
        if (
            pieces[i].getPlayer() == player &&
            pieces[i].getType() == type
            )
            return &pieces[i];
    }
    return 0;
}

void Board::debugListPieces() {
    std::cout << "*****locations occupied on board*****\n";
    for (int i = 0; i < pieces.size(); ++i)
    {
        std::cout << "P" << pieces[i].getPlayer() << "-" << (int) pieces[i].getType() << "@" << pieces[i].getPos() << "  ";
    }
    std::cout << "\n\n";
}

std::string Board::displayBoardPieces() {
    std::string output;
    for (int i = 0; i < pieces.size(); ++i)
    {
        if (pieces[i].getPlayer() == 0)
            output += "W:";
        else
            output += "B:";
        output += getChessPosition(
            pieces[i].getType(),
            pieces[i].getPos() % 8,
            pieces[i].getPos() / 8
            );
        output += " ";
    }
    return output;
}

std::string Board::getChessPosition(TYPE t, int x, int y) {
    std::string output;
    output.push_back(getPieceChar(t));
    output.push_back(97 + x);
    output.push_back(49 + y);
    return output;
}



void Board::printBoard()
{
    std::cout << "\n";
    for (int y = 7; y >= 0; --y)
    {
        for (int x = 0; x < 8; ++x)
        {
            int thisPos = (y*8)+x;
            Piece* thisPiece = refByPosition(thisPos);
            if (thisPiece != 0)
            {
                char c = getPieceChar(thisPiece->getType());
                if (thisPiece->getPlayer() == 0)
                    std::cout << (char) tolower(c);
                else
                    std::cout << c;
            }
            else if (((x % 2) != (y % 2)) == 0)
                std::cout << "_";
            else
                std::cout << "x";
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}



