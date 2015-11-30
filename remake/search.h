#ifndef p1_remake_search_h
#define p1_remake_search_h
#include <iostream>
#include <vector>
#include <string>
#include "Board.h"
#include "moves.h"

const int UNSET = 999;

class searchNode
{
public:
	searchNode(Board b): state(b)
	{
		heuristic = UNSET;
		moveName = b.getMoveName();
		alphaBetaCutoff = false;
	}
	void addChild (searchNode* add) { children.push_back(add); }
	int numChildren () { return children.size(); }
	searchNode* getChild(int i)
	{
		if (i >= 0 && i < children.size())
			return children[i];
		return 0;
	}
	Board getBoard() { return state; }
	std::string getMoveName() { return moveName; }
	void setHeuristic(int h) { heuristic = h; }
	int getHeuristic() { return heuristic; }
	std::string prettyPrintBoard() { return state.displayBoardPieces(); }
	void setCutoff(bool c) { alphaBetaCutoff = c; }
	bool hasCutoff() { return alphaBetaCutoff; }
	bool anyKingsMissing()
	{
		if ((state.findPiece(0,KING) == 0) || (state.findPiece(1,KING) == 0))
			return true;
		return false;
	}
private:
	std::vector<searchNode* > children;
	Board state;
	std::string moveName;
	bool alphaBetaCutoff;
	int heuristic;
};

int search(Board,int,int,int);
int _search(searchNode*,const int,int,int);
void printTree(searchNode*,int,int);
void _printTree(searchNode*,int,std::vector<std::string>&);
void printBest(searchNode*);
void _printBest(searchNode*,int);
searchNode* traverseOptimal(searchNode*,int,int);
searchNode* _traverseOptimal(searchNode*,int,int);
void printNodesMThroughN(searchNode*,int);
int simpleHeuristic(Board);
void calculatePieceValue(int&,int);
void updateBestHeuristic(int,int&,int);
void determineBestChild(searchNode*&,searchNode*,int);


#endif

/*	our goal
		for each node of the search
			generate the array of possible moves
			choose the correct move by propogating the
			 heuristic from the leaf to the node, and 
			 apply minimax for alpha-beta cutoffs
		at the end, we should be able to pick the best
		 next move for the first player. in other words,
		 our search should return at least the move we
		 should make, but, ideally a tree of moves and their
		 heuristics. so, a linked node structure. this node
		 structure that is the search.

*/