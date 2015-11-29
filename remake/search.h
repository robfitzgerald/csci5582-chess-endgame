#ifndef p1_remake_search_h
#define p1_remake_search_h
#include <iostream>
#include <vector>
#include "Board.h"
#include "moves.h"

const int UNSET = 999;

class searchNode
{
public:
	searchNode(Board b, std::string m): state(b), moveName(m) 
	{
		heuristic = UNSET;
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
private:
	std::vector<searchNode* > children;
	Board state;
	std::string moveName;
	int heuristic;
};

int search(Board,int);
int _search(searchNode*,const int,int,int);
void print(searchNode*);
void _print(searchNode*,int);
int simpleHeuristic(Board);
void calculatePieceValue(int&,int);
void updateBestHeuristic(int,int&,int);

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