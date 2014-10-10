// ////////////////////////////////////////////////////////////////
//
// Project: 15-Puzzle-Solver
// Author: Christopher Anzalone
// File: Coordinates.h 				
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

#ifndef COORDINATES_H
#define COORDINATES_H

class coordinates
{
public:
	coordinates();
	int getRow();
	int getCol();
	void setRow(int);
	void setCol(int);
	coordinates operator= (coordinates rhs);
private:
	int row, col;
};

#endif






