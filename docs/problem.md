Two Kings and two Pawns. Black Pawn moves down, White Pawn moves up. When pawns reach c8 and h1, respectively, they are promoted to Queens. White begins. Algorithm.  Employ minimax search algorithm with limited depth. Run several experiments with depth 10, 11 and 12. Do not continue branches after a King is lost. Utilize evaluation function which is a 
sum of values of White pieces minus sum of values of Black pieces. Assign values of this functionto the terminal states and apply minimax search algorithm with alpha-beta cut-offs. 
Introduce a priority function to evaluate priority of moves for inclusion in the search tree. Better priority function should lead to more cut-offs.
Output.

For the output use the following notation: 

1. Kh8-g8, Ph5-h4 
2. Kg8-g7, Ph4-h3 

and so on. 

All the moves included on the search tree should be counted. Yourprogram should print a complete search subtree beginning from move number 
M to move number N, where numbers M and N are input parameters. Print sample subtrees for different pairs M, N. The depth of 
each move in your trees should bereflected by the left margin. The deeper move is in your tree the greater its margin is.
 Print the total number of moves included in the search tree. Print optimal subtree resulted from your search. It should be a solution to the problem. Verify if 
searches with different depth limit yield a solutionto the problem. 

If your trees are represented by graphs and your moves included on the tree could be demonstrated by the dynamic pictures of 
movement of pieces over the chess board you will get extra credit.  
