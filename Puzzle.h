// ////////////////////////////////////////////////////////////////
//
// Project: 15-Puzzle-Solver
// Author: Christopher Anzalone
// File: Puzzle.h 				
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
//#include "BoardStack.h"
#include "Coordinates.h"
#include "Node.h"
#include <vector>

using namespace std;

#ifndef PUZZLE_H
#define PUZZLE_H  //CLEAN UP MEMORY AFTER FINISHED (USING NODE * INITIALNODE)

class Puzzle //: Board  //Uses tree-search with admissible heuristics 
{
	public:
		Puzzle();  //working
		void Search(int);
		void Successors(Board &, vector<Board> &, vector<char>&);
		bool Goal_Test(Board &);  //working
		void Randomize(/*Board&*/);  //working
		void save_Initial();  //working
		void print_active_Board();  //working
		Board update_Current_Board(Node &); //working
		int misplaced_Heuristic(Node &);  //working
		int manhattan_Distance(Node &); //working
		void initial_To_Path0();  //working
		coordinates j_to_Coord_Convert(int);  //working
		bool puzzle_Solvable();  //working
		void print_Board(Board &);
		void insert_To_Fringe(Node &);  //insert node to fringe
		bool fringe_empty_check();
		int heuristic_medium(/*vector<Node>&*/Node &, int);
		/*Node &*/int fringe_choice();
		bool check_move(coordinates, char);
		void check_explored_set(vector<Board> &, vector<char>&);
		void insert_to_explored_set(Board);
	private:
	//	boardStack mem_Path;  //stack of nodes (nodes contain Board object)
//		vector < Node > fringe;  //set of NODES in the fringe
//		vector < Node > agent;  
	
		vector < Node* > fringe_ptr;
		Node * initialNode;
		vector < Board > explored_set;  //set of STATES that have been visited, not nodes
//		vector < Node * > master_ptr;  //pointers for every node for the purpose of mem dealloc
//		vector < Board > successors; //successors of s during search, should be cleared after each use


//		Node * agent;
//		Node * fringe;

//		vector< Node * > fringe_ptr;
//		vector< Node * > agent_ptr;

	//	Board * path;  //declare in driver? - will be array that grows and shrinks, to store path
	//	Board * previously_visited;
	//	vector<Board> previously_visited;
		//Node * path;  //for outputting path of states 
		//Node * previously_visited;  //will store all states that have been examined, so as to avoid revisiting
	//	Board * fringe; // array of states in the fringe/recently expanded nodes, or children
	//	vector <Board> fringe;  //no particular order

	//	boardStack fringe;
//		Board initial_State;  //creates Board object that is initialized (constr) with 0-15 orientation, only to be used in Puzzle constructor
//		Board current_Board;

		//Node current_Node;
		int width;
		int boardCounter;
		int max_bound;
		int fringe_counter;
		int STEP_COST;  //always 1 for N-puzzle
};


#endif 