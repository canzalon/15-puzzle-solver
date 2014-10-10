// ////////////////////////////////////////////////////////////////
//
// Project: 15-Puzzle-Solver
// Author: Christopher Anzalone
// File: Board.cpp 				
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
#include <iostream>

using namespace std;

Board::Board()
{
	width = 4;
//	in_Fringe = false;
	//f_n = 0;
	//g_n = 0;
	//h_n = 0;
//	action = "INITIAL";
	//parent = NULL;

	/*Initialize board with goal state*/
	//for (int row = 0; row < 4; row++)
	//{
	//	for (int col = 0; col < 4; col++)
	//	{
	//		board[row][col] = (row*width + col);
	//	}
	//}

	/*FOR TESTING PURPOSES: initialize with easy board layout*/
	///*TEST PURPOSES*/
	//Board testBoard;
	board[0][0] = 1;
	board[0][1] = 2;
	board[0][2] = 3;
	board[0][3] = 4;
	board[1][0] = 5;
	board[1][1] = 6;
	board[1][2] = 7;
	board[1][3] = 8;
	board[2][0] = 9;
	board[2][1] = 0;
	board[2][2] = 11;
	board[2][3] = 12;
	board[3][0] = 13;
	board[3][1] = 10;
	board[3][2] = 14;
	board[3][3] = 15;
	///**/

	/*Initialize empty location var*/
//	empty_space_loc_x = 0;
//	empty_space_loc_y = 0;
}

Board::Board(const Board & other)
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			board[row][col] = other.board[row][col];
		}
	}
}

int Board::get_Board(int row, int col)
{

	return board[row][col];
}

void Board::set_Board(int row, int col, int value)
{
	board[row][col] = value;
}

//bool Board::Goal_Test() //will need to take in current state S as board object
//{
//	/*goal_Check true after loop if the goal is reached*/
//	bool goal_Check = true;
//
//	for (int row = 0; row < 4; row++)
//	{
//		for (int col = 0; col < 4; col++)
//		{
//			if (board[row][col] != (row*width + col))
//			{
//				goal_Check = false;
//			}
//		}
//	}
//	
//	return goal_Check;
//}

//void Board::print_Board()
//{
//	for (int row = 0; row < 4; row++)
//	{
//		for (int col = 0; col < 4; col++)
//		{
//			cout << board[row][col];
//		}
//		cout << endl;
//	}
//}

void Board::Print()
{
	int current_Val;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			current_Val = board[row][col];
			cout << current_Val <<" ";
		}
		cout << endl;
	}
}

Board & Board::operator= (Board rhs)
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			board[row][col] = rhs.board[row][col];
		}
	}

	return *this;
}

bool Board::operator== (const Board & rhs)
{
	bool equal = true;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (board[row][col] != rhs.board[row][col])
			{
				equal = false;
			}	
		}
	}

	return equal;
}