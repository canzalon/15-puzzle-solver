// ////////////////////////////////////////////////////////////////
//
// Project: 15-Puzzle-Solver
// Author: Christopher Anzalone
// File: Node.cpp			
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

#include "Node.h"
#include <iostream>

Node::Node()
{
	g_n = 0;
	h_n = 0;
	f_n = g_n + h_n;

	parent = NULL;  //be sure to initialize during search function
	action = 'x';
}

Node::Node(const Node & other)
{
	data = other.data;
	parent = other.parent;
	f_n = other.f_n;
	g_n = other.g_n;
	h_n = other.h_n;
}

void Node::update_F()
{
	f_n = g_n + h_n;
}

Node & Node::operator=(Node rhs)
{
	data = rhs.data;
	parent = rhs.parent;
	f_n = rhs.f_n;
	g_n = rhs.g_n;
	h_n = rhs.h_n;

	action = rhs.action;

	return *this;
}