README

Resubmission of AI Project 1

-----------------------------
--Installation Instructions--
-----------------------------

This project is written in C++11.  A standard makefile has been provided, as well as a binary compiled in Mac OS X Terminal, which may run on most Linux distributions.
To Compile, enter a command line at the project directory, and run:

$ make

which should result in the compilation:

g++ -c -g -std=c++11  Board.cpp
g++ -c -g -std=c++11  moves.cpp
g++ -c -g -std=c++11  search.cpp
g++ -c -g -std=c++11  main.cpp
g++ -o rreti Board.o moves.o search.o main.o   -lm

then, you can run the program by typing:

$ ./rreti

this will output the program usage instructions:

Usage: ./rreti <turns> <m> <n>
where <turns> is how many turns to generate, 
      (1 turn contains moves for both opponents)
      <m> and <n> specify the range of turns to print the search tree (optional)

examples are provided in the output examples file.

-------------------------------------
--Addressing the Problem Statement:--
-------------------------------------

This section takes the form:

<project requirement> 
	<location in code>

Do not continue branches after a King is lost. 
	search.cpp _search() lines 22-25

Utilize evaluation function which is a sum of values of White pieces minus sum of values of Black pieces. 
	search.cpp simpleHeuristic() lines 63-77

Assign values of this function to the terminal states and apply minimax search algorithm with alpha-beta cut-offs. 
	search.cpp _search() lines 46-57

Introduce a priority function to evaluate priority of moves for inclusion in the search tree. Better priority function should lead to more cut-offs.
	moves.cpp generateMoves() lines 38-44

For the output use the following notation: 1. Kh8-g8, Ph5-h4 2. Kg8-g7, Ph4-h3 and so on. 
	moves.cpp getChessNotation() lines 223-232

All the moves included on the search tree should be counted.
	search.cpp _search() line 21

Your program should print a complete search subtree beginning from move number M to move number N, where numbers M and N are input parameters.
	search.cpp printTree() lines 173-183
	
Print sample subtrees for different pairs M, N. The depth of each move in your trees should be reflected by the left margin. The deeper move is in your tree the greater its margin is. Print the total number of moves included in the search tree.
Print optimal subtree resulted from your search. It should be a solution to the problem. Verify if searches with different depth limit yield a solution to the problem. If your trees are represented by graphs and your moves included on the tree could be demonstrated by the dynamic pictures of movement of pieces over the chess board you will get extra credit.
	for comments on finding a solution and examples, see output examples.txt

---------------------------------------