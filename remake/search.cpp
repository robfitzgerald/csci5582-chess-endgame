#include "search.h"

int search(Board b, int maxDepth)
{
	std::string headMove = "";
	searchNode* head = new searchNode(b,headMove);
	int topHeurisic = _search(head,maxDepth,0,UNSET);
	print(head);
	return topHeurisic;
}

int _search(searchNode* thisNode, const int maxDepth, int depth, int parentHeuristic)
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
	int bestHeuristic = UNSET;
	for (int p = 0; p < possibles.size(); ++p)
	{
		std::string newMoveName = "";
		searchNode* newNode = new searchNode(possibles[p],newMoveName);
		thisNode->addChild(newNode);
		int childHeuristic = _search(newNode,maxDepth,depth+1,bestHeuristic);
		newNode->setHeuristic(childHeuristic);
		//std::cout << "childHeuristic = " << newNode->getHeuristic() << "\n";
		updateBestHeuristic(currentPlayer, bestHeuristic, childHeuristic);
		//std::cout << "depth " << depth << " bestHeuristic is now " << bestHeuristic << " and parentHeuristic is " << parentHeuristic << "\n";
		if (parentHeuristic != UNSET) 
		{
			if (
				(currentPlayer == 1 && bestHeuristic < parentHeuristic) ||
				(currentPlayer == 0 && bestHeuristic > parentHeuristic)
				)
			{
				std::cout << "player: " << currentPlayer << " best: " << bestHeuristic << " parent: " << parentHeuristic << " -> cutoff applied.\n";
				break;
			}
		}
	}
	thisNode->setHeuristic(bestHeuristic);
	return bestHeuristic;
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

void updateBestHeuristic(int pl, int& bestH, int newH)
{
	if (bestH == UNSET)
	{
		bestH = newH;
	}
	else if (pl == 0)
	{
		if (newH > bestH)
			bestH = newH;
	}
	else if (pl == 1)
	{
		if (newH < bestH)
			bestH = newH;
	}
}

void print(searchNode* head)
{
	_print(head, 0);
}

void _print(searchNode* node, int depth)
{
	for (int i = 0; i < node->numChildren(); ++i)
	{
		std::cout << "move " << depth << ", "; 
		if ((depth % 2) == 0)
			std::cout << "white ";
		else
			std::cout << "black ";
		for (int indent = 0; indent < depth; ++indent)
		{
			std::cout << "  ";
		}
		std::cout << node->getMoveName() << " : " << node->getHeuristic() << "\n";
		_print(node->getChild(i), depth+1);
	}
}












