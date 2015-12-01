#include "search.h"
#include <iomanip>
#include <sstream>

int search(Board b, int maxDepth, int m, int n)
{
	searchNode* head = new searchNode(b);
	std::cout << "\n** R.Reti Endgame Board **\n";
	head->printBoardImage();
	int topHeurisic = _search(head,maxDepth,0,UNSET);
	printOptimal(head,m,n);
	printBest(head);
	return topHeurisic;
}

int _search(searchNode* thisNode, const int maxDepth, int depth, int parentHeuristic)
{
	if (thisNode->anyKingsMissing())
	{
		return simpleHeuristic(thisNode->getBoard());
	}
	int currentPlayer = (depth % 2);
	if (depth == maxDepth)
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
		//std::cout << "depth " << depth << " trying possibles[" << p << "] whose move is " << possibles[p].getMoveName() << "\n";
		searchNode* newNode = new searchNode(possibles[p]);
		thisNode->addChild(newNode);
		//std::cout << "newNode should match possibles[p] move name: " << newNode->getMoveName() << "\n";
		int childHeuristic = _search(newNode,maxDepth,depth+1,bestHeuristic);
		newNode->setHeuristic(childHeuristic);
		updateBestHeuristic(currentPlayer, bestHeuristic, childHeuristic);
		if (parentHeuristic != UNSET) 
		{
			if (
				(currentPlayer == 1 && bestHeuristic < parentHeuristic) ||
				(currentPlayer == 0 && bestHeuristic > parentHeuristic)
				)
			{
				//std::cout << "player: " << currentPlayer << " best: " << bestHeuristic << " parent: " << parentHeuristic << " -> cutoff applied.\n";
				thisNode->setCutoff(true);
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

void printTree(searchNode* head, int m, int n)
{
	std::cout << "\nplayer depth  heuristic    move                board\n";
	std::cout <<   "----------------------------------------------------\n";
	_printTree(head,0,n);
/*	if (
		(m == 0 && n == 0) ||
		(m > n) ||
		(m < 0)
		)
	{
		m = 0;
		// n = some max depth value
	}*/
}

void _printTree(searchNode* node, int depth, int maxDepth)
{
	if (depth <= maxDepth)
	{
		std::ostringstream output;
		output << std::left;
		if (depth == 0)
			output << "start  ";
		else if ((depth % 2) == 0)
			output << "black  ";
		else
			output << "white  ";
		output << std::setw(7) << depth;
		std::string heuristicOutput;
		heuristicOutput += std::to_string(node->getHeuristic());
		if (node->hasCutoff())
			heuristicOutput += " -cutoff-";
		output << std::setw(12) << heuristicOutput << "|";
		std::string moveText;
		for (int indent = 0; indent < depth; ++indent)
		{
			moveText += " ";
		}
		moveText += node->getMoveName();
		output << std::setw(20) << moveText;
		output << node->prettyPrintBoard() << "\n";
		std::cout << output.str();
		for (int i = 0; i < node->numChildren(); ++i)
		{
			_printTree(node->getChild(i), depth+1, maxDepth);
		}
	}
}

void printBest(searchNode* head)
{
	// std::cout << "best moves based on search results\n";
	_printBest(head,0);
}

void _printBest(searchNode* node, int depth)
{
	searchNode* best = new searchNode(Board());
	for (int i = 0; i < node->numChildren(); ++i)
	{
		determineBestChild(best,node->getChild(i),depth);
	}
	if (best->getHeuristic() == UNSET)
	{
		std::cout << "\n** Result **\n";
		node->printBoardImage();
	}
	else 
	{
		if ((depth % 2) == 0)
		{
			std::cout << ((depth / 2) + 1) << ". " << best->getMoveName() << ", ";
		}
		else 
		{
			std::cout << best->getMoveName() << "\n";
		}
		_printBest(best,depth+1);
	}	
}

void printOptimal(searchNode* head, int m, int n)
{
	searchNode* cursor = head;
	std::cout << "best moves based on search results\n";
	std::cout << "\nplayer depth  heuristic    move                board\n";
	std::cout <<   "----------------------------------------------------\n";

	if (m > 0)
		cursor = _traverseBest(cursor,0,m);
	_printTree(cursor,m,n);

}

searchNode* _traverseBest(searchNode* node, int depth, int n)
{
	if (depth == n)
	{
		return node;
	}
	searchNode* best = new searchNode(Board());
	for (int i = 0; i < node->numChildren(); ++i)
	{
		determineBestChild(best,node->getChild(i),depth);
	}
	if (!(best->getHeuristic() == UNSET))
	{
		return _traverseBest(best,depth+1,n);
	}
	return node;
}

void determineBestChild(searchNode*& bestNode, searchNode* thisChild, int depth)
{
	int player = depth % 2;
	if (bestNode->getHeuristic() == UNSET)
	{
		bestNode = thisChild;
	}
	else if (player == 0 && bestNode->getHeuristic() < thisChild->getHeuristic())
	{
		bestNode = thisChild;
	}
	else if (player == 1 && bestNode->getHeuristic() > thisChild->getHeuristic())
	{
		bestNode = thisChild;
	}
}



