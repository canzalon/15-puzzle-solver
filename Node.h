// ////////////////////////////////////////////////////////////////
//
// Project: 15-Puzzle-Solver
// Author: Christopher Anzalone
// File: Node.h 				
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

#include "Board.h"
//#include <string>

#ifndef NODE_H
#define NODE_H

//typedef Board stackElement;

class Node 
{
public:
	Node();
	Node(const Node &); //copy constr
	Board data;
	Node *parent;

	int f_n;  //f(n) value of state
	int g_n;  //PATH COST g(n) [PARENT g(n) + STEP-COST(parent.STATE, action)]
	int h_n;  //HEURISTIC VALUE (from N to Goal)

	char action;  //action applied to the parent node to get this state
	Node & operator= (Node rhs);
	void update_F();
};

#endif

