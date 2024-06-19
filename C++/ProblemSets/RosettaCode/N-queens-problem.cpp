// In this page we attack the 8-q and N-q problems
#include <iostream>
#include <vector>

/*
 * The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so 
 * that no two queens threaten each other; thus, a solution requires that no two queens share the 
 * same row, column, or diagonal. There are 92 solutions. The problem was first posed in the 
 * mid-19th century. In the modern era, it is often used as an example problem for various computer 
 * programming techniques.
 *
 * The eight queens puzzle is a special case of the more general n queens problem of placing n 
 * non-attacking queens on an n×n chessboard. Solutions exist for all natural numbers n with the 
 * exception of n = 2 and n = 3. Although the exact number of solutions is only known for n ≤ 27, 
 * the asymptotic growth rate of the number of solutions is approximately (0.143 n)n. 
 *
 * The eight queens puzzle has 92 distinct solutions. If solutions that differ only by the symmetry 
 * operations of rotation and reflection of the board are counted as one, the puzzle has 12 
 * solutions. These are called fundamental solutions; representatives of each are shown below. 
 *
 * stair-stepped patterns - wtf is a stair stepped pattern
 *
 * Finding all solutions to the eight queens puzzle is a good example of a simple but nontrivial 
 * problem. For this reason, it is often used as an example problem for various programming techniques, 
 * including nontraditional approaches such as constraint programming, logic programming or genetic 
 * algorithms. Most often, it is used as an example of a problem that can be solved with a recursive 
 * algorithm, by phrasing the n queens problem inductively in terms of adding a single queen to any 
 * solution to the problem of placing n−1 queens on an n×n chessboard. The induction bottoms out with 
 * the solution to the 'problem' of placing 0 queens on the chessboard, which is the empty chessboard.
 * 
 * Methods for solving the problem:
 * 	- Constraint programming, logic programming, genetic algorithms,
 * 	- Brute force,
 * 	- A better brute-force algorithm: Places a single queen on each row, leading
 * 	to only pow(8,8) blind placements,
 * 	- It's, however, possible to do far better than this. One algorithm solves the
 * 	eight rooks puzzle, and uses the elements of each permutation as indices to place
 * 	a queen on each row,
 * 	- The backtracking depth-first search program, a slight improvement on the per-
 * 	mutation method, constructs the search tree by considering one row of the board
 * 	at a time, eliminating most nonsolution board positions at a very early stage in
 * 	their construction.
 * 	---> Eliminates most nonsolution board positions at a very early stage in their
 * 	     construction
 *	
 * 	An alternative to exhaustive search is an 'iterative repair' algorithm, which
 * 	typically starts with all queens on the board, for example with one queen
 * 	per column. It then counts the number of conflicts, and uses a heuristic to
 * 	determine how to improve the placement of the queens.
 *
 * 	As an alternative to backtracking, solutions can be counted by recursively 
 * 	enumerating valid partial solutions, one row at a time. Rather than
 * 	constructing entire board positions, blocked diagonals and columns are tracked
 * 	with bitwise operations. This doesn't allow the recovery of individual solutions.
 *
 */

/* In this section, we must consider how to:
 * - Represent a chess board on a computer,
 * - How to check for collisions of queens,
 * - How to iterate through potential positions
 * - How to reduce the initial number of candidate postions
 */

int main() {
	return 0;
}
