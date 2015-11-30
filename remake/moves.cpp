#include "moves.h"
#include <iostream>
#include <cmath>
#include <algorithm>

const int UNSET = 999;
const int BOARD_UPPER_BOUND = 64;
const int BOARD_LOWER_BOUND = -1;

std::vector<Board> generateMoves(std::vector<Piece * > pieces, Board current)
{
	
	std::vector<Board> output;
	for (int i = 0; i < pieces.size(); ++i)
	{
		switch (pieces[i]->getType())
		{
			case EMPTY:
				break;
			case PAWN:
				pawnMoves(output,current,pieces[i]);
				break;
			case KNIGHT:
				break;
			case BISHOP:
				break;
			case ROOK:
				break;
			case QUEEN:
				queenMoves(output,current,pieces[i]);
				break;
			case KING:
				kingMoves(output,current,pieces[i]);
				break;	
		}
	}

	// sort by 'priority function' - # players on board
	// if less players on board, it's always better since we are 
	// whomever we are generating moves for would hope to reduce
	// the playing field. ;-)
	std::sort(output.begin(), output.end(), [ ] (const Board& lhs, const Board& rhs) {
		return lhs.numPieces() < rhs.numPieces();
	});
	return output;
}

void pawnMoves(std::vector<Board>& possibles, Board b, Piece* p)
{
	std::vector<int> goodMoves;
	int thisPos = p->getPos();
	int thisX = thisPos % 8;
	int nextVerticalStep;
	if (p->getPlayer() == 0)
		nextVerticalStep = thisPos + 8;
	else
		nextVerticalStep = thisPos - 8;
	if (0 <= nextVerticalStep && nextVerticalStep < 64)
		goodMoves.push_back(nextVerticalStep);
	if ((thisX - 1) >= 0)
		goodMoves.push_back(nextVerticalStep - 1);
	if ((thisX + 1) < 8)
		goodMoves.push_back(nextVerticalStep + 1);
	for (int i = 0; i < goodMoves.size(); ++i)
	{
		Board temp = b;
		Piece* toMove = temp.refByPosition(p->getPos());
		bool moveSuccess = temp.move(toMove,goodMoves[i]);
		temp.setMoveName(
			getChessNotation(
				p->getType(),
				p->getPos() % 8,
				p->getPos() / 8,
				goodMoves[i] % 8,
				goodMoves[i] / 8
				)
			);
		
		if (moveSuccess && goodMoves[i] == nextVerticalStep)
		{
			if (temp.numPieces() == b.numPieces())
			{
				if (goodMoves[i] >= 56 || goodMoves[i] < 8) 
				{
					Piece* toQueen = temp.refByPosition(goodMoves[i]);
					toQueen->setType(QUEEN);
				}	
				// valid vertical move
				possibles.push_back(temp);
			}
		}
		else if (moveSuccess)
		{
			if (temp.numPieces() < b.numPieces())
			{
				if (goodMoves[i] >= 56 || goodMoves[i] < 8) 
				{
					Piece* toQueen = temp.refByPosition(goodMoves[i]);
					toQueen->setType(QUEEN);
				}
				//valid diagonal move
				possibles.push_back(temp);
			}
		}
	}
}

void queenMoves(std::vector<Board>& possibles, Board b, Piece* p)
{
	std::vector<int> goodMoves;
	int thisPos = p->getPos();
	int thisX = thisPos % 8;
	int thisY = thisPos / 8;

	for (int yIncrement = -1; yIncrement <= 1; ++yIncrement)
	{
		for (int xIncrement = -1; xIncrement <= 1; ++xIncrement)
		{
			if (!((yIncrement == 0) && (xIncrement == 0)))
			{
				queenSearch(goodMoves,thisX+xIncrement,thisY+yIncrement,xIncrement,yIncrement,b);
			}
		}
	}
	for (int i = 0; i < goodMoves.size(); ++i)
	{
		Board temp = b;
		Piece* toMove = temp.refByPosition(p->getPos());
		if (temp.move(toMove,goodMoves[i]))
		{
			temp.setMoveName(
				getChessNotation(
					p->getType(),
					p->getPos() % 8,
					p->getPos() / 8,
					goodMoves[i] % 8,
					goodMoves[i] / 8
					)
				);
			possibles.push_back(temp);
		}
	}
}

void queenSearch(std::vector<int>& goodMoves, int x, int y, int xInc, int yInc, Board b)
{
	int thisPos = (y * 8) + x;
	if (0 <= x && x < 8 && 0 <= y && y < 8)
	{
		if (b.refByPosition(thisPos) != 0)
		{
			goodMoves.push_back(thisPos);
		}
		else
		{
			goodMoves.push_back(thisPos);
			queenSearch(goodMoves,x+xInc,y+yInc,xInc,yInc,b);
		}
	}
}

void kingMoves(std::vector<Board>& possibles, Board b, Piece* p)
{
	int thisPos = p->getPos();
	int thisX = thisPos % 8;
	int thisY = thisPos / 8;

	for (int y = thisY - 1; y <= thisY + 1; ++y)
	{
		for (int x = thisX - 1; x <= thisX + 1; ++x)
		{
			if (0 <= x && x < 8 && 0 <= y && y < 8)
			{
				int validStep = (y * 8) + x;
				Board temp = b;
				Piece* toMove = temp.refByPosition(p->getPos());
				if (temp.move(toMove,validStep))
				{
					temp.setMoveName(
						getChessNotation(
							p->getType(),
							p->getPos() % 8,
							p->getPos() / 8,
							validStep % 8,
							validStep / 8
							)
						);
					possibles.push_back(temp);
				}
			}
		}
	}
}

char getPieceChar(TYPE t) {
    switch(t) {
        case EMPTY:
            return ' ';
            break;
        case KING:
            return 'K';
            break;
        case QUEEN:
            return 'Q';
            break;
        case BISHOP:
            return 'B';
            break;
        case KNIGHT:
            return 'K';
            break;
        case ROOK:
            return 'R';
            break;
        case PAWN:
            return 'P';
            break;
        default:
            return '?';
    }   
}

std::string getChessNotation(TYPE t, int x1, int y1, int x2, int y2) {
    std::string output;
    output.push_back(getPieceChar(t));
    output.push_back(97 + x1);
    output.push_back(49 + y1);
    output.push_back('-');
    output.push_back(97 + x2);
    output.push_back(49 + y2);
    return output;
}

