#include "search.h"

int search(Board b, int maxDepth)
{
	std::string headMove = "";
	searchNode* head = new searchNode(b,headMove);
	return _search(head,maxDepth,0);
}

int _search(searchNode* thisNode, const int maxDepth, int depth)
{
	int currentPlayer = (depth % 2);
	if (depth == maxDepth-1)
	{
		return simpleHeuristic(thisNode->getBoard());
	}
	Board currentBoard = thisNode->getBoard();
	std::vector<Board> possibles = generateMoves(currentBoard.getPieces(currentPlayer), currentBoard);
	if (possibles.size() == 0)
	{
		return simpleHeuristic(thisNode->getBoard());
	}
	for (int p = 0; p < possibles.size(); ++p)
	{
		std::string newMoveName = "";
		searchNode* newNode = new searchNode(possibles[p],newMoveName);
		thisNode->addChild(newNode);
		int childHeuristic = _search(newNode,maxDepth,depth+1);
		std::cout << "childHeuristic = " << childHeuristic << "\n";
	}
	return 0;
}

int simpleHeuristic(Board b)
{
	int whiteHeuristic = 0, blackHeuristic = 0;
	std::vector<Piece *> white = b.getPieces(0);
	std::vector<Piece *> black = b.getPieces(1);
	for (int p = 0; p < white.size(); ++p)
	{
		calculatePieceValue(whiteHeuristic,(int) white[p]->getType());
	}
	for (int p = 0; p < black.size(); ++p)
	{
		calculatePieceValue(blackHeuristic,(int) black[p]->getType());
	}
	return whiteHeuristic - blackHeuristic;
}

void calculatePieceValue(int& sum, int type)
{
	int pieceValue = 1;
		for (int n = 0; n < type; ++n)
			pieceValue *= 2;
		sum += pieceValue;
}


