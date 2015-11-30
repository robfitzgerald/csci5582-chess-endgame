#include "search.h"
#include <iomanip>
#include <sstream>

int search(Board b, int maxDepth, int m, int n)
{
	searchNode* head = new searchNode(b);
	int topHeurisic = _search(head,maxDepth,0,UNSET);
	//printTree(head,m,n);
	searchNode* nodeM = traverseOptimal(head,0,m);
	// printNodesMThroughN(nodeM,n-m);
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
	std::vector<std::string> displayNodes;
	std::cout << "index   player depth  heuristic    move                board\n";
	_printTree(head, 0, displayNodes);
	if (
		(m == 0 && n == 0) ||
		(m > n) ||
		(m < 0) ||
		(n > displayNodes.size())
		)
	{
		m = 0;
		n = displayNodes.size();
	}
	for ( ; m < n; ++m)
	{
		std::cout << std::left << std::setw(8) << m <<displayNodes[m];
	}
}

void _printTree(searchNode* node, int depth, std::vector<std::string>& out)
{
	std::ostringstream output;
	output << std::left;
	if ((depth % 2) == 0)
		output << "white  ";
	else
		output << "black  ";
	output << std::setw(7) << depth;
	std::string heuristicOutput;
	heuristicOutput += std::to_string(node->getHeuristic());
	if (node->hasCutoff())
		heuristicOutput += " -cutoff-";
	output << std::setw(12) << heuristicOutput << "|";
	std::string moveText;
	for (int indent = 0; indent < depth; ++indent)
	{
		moveText += "  ";
	}
	moveText += node->getMoveName();
	output << std::setw(20) << moveText;
	output << node->prettyPrintBoard() << "\n";
	out.push_back(output.str());
	for (int i = 0; i < node->numChildren(); ++i)
	{
		_printTree(node->getChild(i), depth+1, out);
	}
}

void printBest(searchNode* head)
{
	std::cout << "best moves based on search results\n";
	_printBest(head,0);
}

void _printBest(searchNode* node, int depth)
{
	std::string output;
	searchNode* best = new searchNode(Board());
	for (int i = 0; i < node->numChildren(); ++i)
	{
		//std::cout << "node->numChildren(): " << node->numChildren() << "\n";
		determineBestChild(best,node->getChild(i),depth);
	}
	//std::cout << "best heuristic: " << best->getHeuristic() << "\n";
	if (best->getHeuristic() == UNSET)
		std::cout << "\n";
	else 
	{
		for (int indent = 0; indent < depth; ++indent)
		{
			output += "  ";
		}
		output += best->getMoveName();
		std::cout << output << "\n";
		_printBest(best,depth+1);
	}	
}

searchNode* traverseOptimal(searchNode* node, int m, int n)
{
	searchNode* out = new searchNode(Board());
	return out;
}

searchNode* _traverseOptimal(searchNode* node, int depth, int endDepth)
{
	if (!(depth == endDepth))
	{
		searchNode* best = new searchNode(Board());
		for (int i = 0; i < node->numChildren(); ++i)
		{
			determineBestChild(best,node->getChild(i),depth);
		}
		if (!(best->getHeuristic() == UNSET))
		{
			return best;
		}
	}
	return 0;
}

void printNodesMThroughN(searchNode* node,int steps)
{
	for (int i = 0; i < steps; ++i)
	{
		
	}
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



