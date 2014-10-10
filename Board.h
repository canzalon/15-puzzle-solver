// ////////////////////////////////////////////////////////////////
//
// Project: 15-Puzzle-Solver
// Author: Christopher Anzalone
// File: Board.h 				
//
// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//
// DESCRIPTION:
//
//	Produces a randomized board of 15-puzzle, and determines 
//	if it is solvable. If so, it finds the solution and produces 
//	the moves required to complete it.
//		
// ////////////////////////////////////////////////////////////////

#ifndef BOARD_H
#define BOARD_H

class Board
{
	public:
		Board();
		Board(const Board&);
		int get_Board(int, int);
		void set_Board(int, int, int);
		void Print();
		//void print_Board();
		/*~Board();*/
		/*bool Goal_Test();*/
		Board & operator= (Board rhs);
		bool operator== (const Board & rhs);
	private:
		int board[4][4];  //STATE [problem.RESULT(parent.STATE, action)]
//		int empty_space_loc_x;
//		int empty_space_loc_y;
		int width;
	//	bool in_Fringe;  //true if in fringe

		//int f_n;  //f(n) value of state
		//int g_n;  //PATH COST g(n) [PARENT g(n) + STEP-COST(parent.STATE, action)]
		//int h_n;  //HEURISTIC VALUE (from N to Goal)
		//string action;  //action applied to the parent node to get this state

	//	Board * parent; //pointer to parent for retrieving goal path (even though a stack will do this)
};

#endif 