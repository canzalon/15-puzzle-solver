// ////////////////////////////////////////////////////////////////
//
// Project: 15-Puzzle-Solver
// Author: Christopher Anzalone
// File: Coordinates.cpp 				
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

#include "Coordinates.h"

int coordinates::getCol()
{
	return col;
}

int coordinates::getRow()
{
	return row;
}

void coordinates::setCol(int value)
{
	col = value;
}

void coordinates::setRow(int value)
{
	row = value;
}
coordinates::coordinates()
{
	row = col = -1;
}

coordinates coordinates::operator=(coordinates rhs)
{
	setRow(rhs.getRow());
	setCol(rhs.getCol());

	return *this;
}