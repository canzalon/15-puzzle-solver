// ////////////////////////////////////////////////////////////////
//
// Project: 15-Puzzle-Solver
// Author: Christopher Anzalone
// File: Puzzle.cpp 				
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

#include "Puzzle.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std;

Puzzle::Puzzle()
{
	width = 4;
	boardCounter = 1;
	max_bound = 100;
	fringe_counter = 0;

	STEP_COST = 1;  //never changes

	/*Allocate memory for path, previously visited, and fringe arrays*/
	//path = new Board[max_bound];

	/*Push initial node onto stack as placeholder before board is randomized [0-15 orientation]*/
//	Node tempNode;
//	tempNode.data = initial_State;
	//agent.front.push_back(tempNode);
//	agent.push_back(tempNode);

	//Node * temporaryNode = new Node;
	//temporaryNode->data = initial_State;

	initialNode = new Node;
//	initialNode->data = initial_State;
	
	/*dyn array replace for agent*/
	//agent = new Node[boardCounter];
	//agent[boardCounter].data = initial_State;

	/*Push initial state with 0-15 orientation*/
	//path.push_back(initial_State);
}

bool Puzzle::Goal_Test(Board & S) //will need to take in current state S as board object
{
	/*goal_Check true after loop if the goal is reached*/
	bool goal_Check = true;
	int tempValue;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			//if (s.get_Board(row, col) != (row*width + col))
			//tempValue = path[boardCounter].get_Board(row, col);
			tempValue = S.get_Board(row, col);
			//if (tempValue != (row*width + col))
			//{
			//	goal_Check = false;
			//}
			if (tempValue != ((row*width + col) + 1))
			{
				if ((row == 3) && (col == 3) && (tempValue == 0))  //if bottom right tile is blank
				{
					break;
				}
				else
				{
					goal_Check = false;
				}
			}
		}
	}

	return goal_Check;
}

//void Puzzle::save_Initial() //only used at inception of puzzle object
//{
//	int current_Val;
//
//	for (int row = 0; row < 4; row++)
//	{
//		for (int col = 0; col < 4; col++)
//		{
//			//current_Val = path[/*boardCounter*/0].get_Board(row, col);
//			//current_Val = path.front().get_Board(row, col);
//			current_Val = agent.front().data.get_Board(row, col);
//			//current_Val = mem_Path.
//			initial_State.set_Board(row, col, current_Val);
//		}
//	}
//}

void Puzzle::Randomize(/*Board & S*/)  //use internally, with path[0]. can not be used after search has begun. only before or after
{
	int RandomVal;
	int tempValue;
//	tempRandomVal = ((rand() % 15) - 1);
	int tempBoard[16];
	int arithConversion;
	srand(time(NULL));

	/*Linearize the board for later randomization*/
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			arithConversion = (row*width + col);
			//tempBoard[arithConversion] = initial_State.get_Board(row, col);//////////
			/*tempBoard[arithConversion] = path.front().get_Board(row, col); */
	//		tempBoard[arithConversion] = agent.front().data.get_Board(row, col);
	//		tempBoard[arithConversion] = agent[0].data.get_Board(row, col);
			//tempBoard[arithConversion] = agent[0].data.get_Board(row, col);
			tempBoard[arithConversion] = initialNode->data.get_Board(row, col);
		}
	}

	///*Linearize the board for later randomization*/
	//for (int row = 0; row < 4; row++)
	//{
	//	for (int col = 0; col < 4; col++)
	//	{
	//		arithConversion = (row*width + col);
	//		tempBoard[arithConversion] = S.get_Board(row, col);
	//	}
	//}

	/*Randomize linear board/array*/
	for (int x = 15; x > 0; x--)
	{
		RandomVal = rand() % x;
		
		tempValue = tempBoard[RandomVal];
		tempBoard[RandomVal] = tempBoard[x];
		tempBoard[x] = tempValue;

	}

	int tempValueTwo;

	///*Convert linear array back to two dimensional array/board*/
	//for (int row = 0; row < 4; row++)
	//{
	//	for (int col = 0; col < 4; col++)
	//	{
	//		arithConversion = (row*width + col);
	//		tempValueTwo = tempBoard[arithConversion];
	//		S.set_Board(row, col, tempValueTwo);
	//	}
	//}

	/*Convert linear array back to two dimensional array/board*/
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			arithConversion = (row*width + col);
			tempValueTwo = tempBoard[arithConversion];
			//initial_State.set_Board(row, col, tempValueTwo);  /////////
	//		agent.front().data.set_Board(row, col, tempValueTwo);
	//		agent[0].data.set_Board(row, col, tempValueTwo);
			initialNode->data.set_Board(row, col, tempValueTwo);
		}
	}

	/*Save to initial state var*/
//	save_Initial();

	/*TESTING FUNCTION: PRINT*/
	int current_Val;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
		//	current_Val = initial_State.get_Board(row, col);
	//		current_Val = agent.front().data.get_Board(row, col);
		//	current_Val = agent[0].data.get_Board(row, col);
			current_Val = initialNode->data.get_Board(row, col);
			cout <<" "<< current_Val;
		}
		cout << endl;
	}
}

//void Puzzle::print_active_Board()  //think about changing to path.back(), depending on search algo
//{
//	int current_Val;
//	for (int row = 0; row < 4; row++)
//	{
//		for (int col = 0; col < 4; col++)
//		{
//			current_Val = current_Board.get_Board(row, col);
//			cout << current_Val;
//		}
//		cout << endl;
//	}
//}

void Puzzle::print_Board(Board & S)  //a more general print function
{
	S.Print();
}

//Board Puzzle::update_Current_Board(Node & N)
//{
//	int current_Val;
//
//	for (int row = 0; row < 4; row++)
//	{
//		for (int col = 0; col < 4; col++)
//		{
//		//	 current_Val = path[boardCounter].get_Board(row, col);
//			current_Val = N.data.get_Board(row, col);
//			current_Board.set_Board(row, col, current_Val);
//		}
//	}
//
//	return current_Board;
//}

int Puzzle::misplaced_Heuristic(Node & N)
{
	///*TEST PURPOSES*/
	//Board testBoard;
	//testBoard.set_Board(0, 0, 0);//0
	//testBoard.set_Board(0, 1, 1);//1
	//testBoard.set_Board(0, 2, 2);//2
	//testBoard.set_Board(0, 3, 3);//3
	//testBoard.set_Board(1, 0, 4);//4
	//testBoard.set_Board(1, 1, 7);//5
	//testBoard.set_Board(1, 2, 6);//6
	//testBoard.set_Board(1, 3, 5);//7
	//testBoard.set_Board(2, 0, 11);//8
	//testBoard.set_Board(2, 1, 10);//9
	//testBoard.set_Board(2, 2, 9);//10
	//testBoard.set_Board(2, 3, 8);//11
	//testBoard.set_Board(3, 0, 15);//12
	//testBoard.set_Board(3, 1, 14);//13
	//testBoard.set_Board(3, 2, 13);//14
	//testBoard.set_Board(3, 3, 12);//15
	///**/

	int actual_Val, expected_Val;
	int misplaced_Count = 0;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			/*actual_Val = path[boardCounter].get_Board(row, col);*/
			/*actual_Val = current_Board.get_Board(row, col);*/
			/*actual_Val = path.back().get_Board(row, col);*/
			actual_Val = N.data.get_Board(row, col);
			/*actual_Val = testBoard.get_Board(row, col);*/
			expected_Val = (row*width + col);

			if (actual_Val != 0)
			{
				if (expected_Val != actual_Val)
				{
					misplaced_Count++;
				}
			}
		}
	}

	return misplaced_Count;
}

//void Puzzle::initial_To_Path0()
//{
//	int current_Val;
//
//	for (int row = 0; row < 4; row++)
//	{
//		for (int col = 0; col < 4; col++)
//		{
//			current_Val = initial_State.get_Board(row, col);
//			path[0].set_Board(row, col, current_Val);
//		}
//	}
//}

int Puzzle::manhattan_Distance(Node & N)  //after getting to work with path vector, reCODE for fringe variables specifically, make seperate functino to pass fringe elements to heuristics
{
	int actual_Val;
	int expected_element;
	int total = 0;
	coordinates coord_i, coord_f;
	//int row_i, col_i;
	int tempManDist;
	signed int row_diff, col_diff;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
		//	actual_Val = current_Board.get_Board(row, col);
		//	actual_Val = path.back().get_Board(row, col);
			actual_Val = N.data.get_Board(row, col);
			expected_element = (row*width + col);
			if ((actual_Val != expected_element) && (actual_Val != 0))
			{
				/*set initial coordinate with loop counters*/
				coord_i.setRow(row);
				coord_i.setCol(col);

				/*obtain value's goal coordinate location*/
				coord_f = j_to_Coord_Convert(actual_Val);

				/*Compute manhattan distance = abs(row_f-row_i) + abs(col_f-col_i) */
				row_diff = abs((coord_f.getRow()) - abs(coord_i.getRow()));
				col_diff = abs((coord_f.getCol()) - abs(coord_i.getCol()));
				tempManDist = row_diff + col_diff;

				/*Add to manhattan distance total*/
				total = total + tempManDist;
			}
		}
	}

	return total;
}

void Puzzle::Search(int heuristic_choice)
{
	bool goal_Reached = false;  //Note: N is current_Node, s is current_Board 

	Node N; //copy of current Node object being examined  //NOTE: KEEPING THIS LOCAL N node to be an ACTUAL copy of the data pointed at by current node pointers in fringe_ptr 
	Node * N_ptr;  //for pointing successors to current parent node
	Board s; //copy of current board configuration being examined
	vector <Board> tempSuccessors;  //temporary storage for newly produced successors, to be passed by ref to successors function
	vector <char> correspondingActions;  //corresponding actions for successors
	int fringe_choice_element;
	vector <char> moves;  //to print actions of goal path in correct order

	int search_iteration = 0; //TESTING PURPOSES

	//1. INSERT(initial_node, fringe);
	//2. Repeat:
	//	a. if empty(FRINGE) then return failure
	//	b. N <- REMOVE(FRINGE)
	//	c. s <- STATE(N)
	//	d. if GOAL?(s) then return path or goal state
	//	e. for every state s' in SUCCESSORS(s)
	//		i. Create a node N' as a successor of N
	//		ii. INSERT(N', FRINGE)

	/*Insert initial node to fringe*/
	//insert_To_Fringe(agent.front());
//	insert_To_Fringe(agent[0]);
	//agent[0].h_n = heuristic_medium(agent[0], heuristic_choice);
	//agent[0].update_F();
	
	initialNode->h_n = heuristic_medium(*initialNode, heuristic_choice);
	initialNode->update_F();
	insert_To_Fringe(*initialNode);

	//////////////////
	//update f(n) whenever h_N or g_N is modified
	//////////////////


	/*Loop of search*/
	while (!goal_Reached)
	{
		search_iteration++;
		if ((search_iteration % 1000) == 0)
		{
			cout << "Search iteration:" << search_iteration << endl;
		}
	//	cout << "Search iteration " << search_iteration++ << endl;

		if (/*fringe.empty()*//*fringe_counter == 0*/ fringe_ptr.empty())  
		{
			cout << "search failed." << endl;
			exit(EXIT_FAILURE);  // MAKE THIS JUST HALT AND GO BACK TO MENU WITH FALSE BOOL TO RESET MENU
		}

		/*Get element of node in fringe vector with lowest f(N) value*/
		fringe_choice_element = fringe_choice();

		/*Remove fringe choice from FRINGE and set temporary node object N with it*/
	//	N = fringe[fringe_choice_element];  /////////////////NEED TO OVERLOAD OPERATOR FOR NODE CLASS
		N = *fringe_ptr[fringe_choice_element]; /////////////////NEED TO OVERLOAD OPERATOR FOR NODE CLASS
		N_ptr = fringe_ptr[fringe_choice_element];
	//	fringe.erase(fringe.begin() + fringe_choice_element);
		fringe_ptr.erase(fringe_ptr.begin() + fringe_choice_element);

		/*TESTING PURPOSES: Print expanded nodes*/
		//N.data.Print();
		//cout << endl;

		/*Add node N's state to set of explored states*/
		insert_to_explored_set(N.data);

		/*Get state of current node being examined*/
		s = N.data;

		/*Check if goal state*/
		goal_Reached = Goal_Test(s);  //returns true if goal state
		if (goal_Reached)
		{
			//return path. call function that re-traces steps from current node to root via parent pointers.
			//while (->parent != NULL) //while not root node
			//go back up, find similar code in stack code files
			Node * nodeIterator = N_ptr;
			cout << "\n\nGOOOOOOOOOOAAAAAAAAAAAAAAAAAAL" << endl;
			while (nodeIterator->parent != NULL)
			{
			/*	cout << "Actions (backward) [add to stack later and output]" << endl;
				cout <<"Action:"<< nodeIterator->action << endl;*/

				moves.push_back(nodeIterator->action);

				nodeIterator = nodeIterator->parent;
			}

			cout << "Actions:" << endl;
			for (int x = moves.size(); x > 0; x--)
			{
				cout << moves[x - 1] << endl;
			}

			//break;  //break while loop
			return;
		}

		/*Obtain all possible successors of s (s')*/
		Successors(s, tempSuccessors, correspondingActions);

		//Check explored set for any matches in s'
		check_explored_set(tempSuccessors, correspondingActions);

		//Create new node for each successor (with parent's g_n+1, update f_n's; also point parent* at parent)
		if (!tempSuccessors.empty())  //if s' not empty
		{
			for (int succ = 0; succ < tempSuccessors.size(); succ++)  //for each successor in tempSuccessors, create new node as successor to N' and add to fringe
			{
				/*Create new node with state s', g(n) of parent + step cost, and h(n) based on chosen heuristic*/
				Node * new_node = new Node;
				new_node->data = tempSuccessors[succ];
				new_node->g_n = N.g_n + STEP_COST;
				new_node->h_n = heuristic_medium(*new_node, heuristic_choice);
				//new_node->parent = fringe_ptr[fringe_choice_element];  //points to parent node, which is the currently expanded node
				new_node->parent = N_ptr;
				new_node->update_F();
				new_node->action = correspondingActions[succ];

				/*Add to fringe*/
				fringe_ptr.push_back(new_node);
			}
		}

		/*Clear successor and action containers for next iteration*/
		//LATER, MAY HAVE TO CLEAR OTHER VARS ( such as s and N and N_ptr )
		tempSuccessors.clear();
		correspondingActions.clear();

		//////////!!!!
		//Right after successors are returned from Successors() function, scan the explored_set for each succesor individually by sending to expored_set_check(s')
		//  it will send back a bool value (true if it's been explored-match, false if there is no match-and is new). if its been explored already, remove from
		//  vector of successors. whatever remains of successors, add to fringe.
		//call function for sending N's state to explored_set
		//////////!!!!


		/*Determine h(n) values of nodes in fringe (after inserting newly created nodes into fringe)*/
		/*..also add g(n) (from their parents) values to nodes when they are created*/




	}
}

void Puzzle::insert_to_explored_set(Board s)
{
	explored_set.push_back(s);
}

void Puzzle::check_explored_set(vector<Board>& tempSuccessors, vector<char>& correspondingActions)
{
	for (int succ = 0; succ < tempSuccessors.size(); succ++)  //for each successor in tempSuccessors
	{
		for (int expl = 0; expl < explored_set.size(); expl++)  //for each board in explored set
		{
			if (tempSuccessors[succ] == explored_set[expl])  //if current successor is equal to a board in the explored set, remove from successors
			{
				tempSuccessors.erase(tempSuccessors.begin() + succ);
				correspondingActions.erase(correspondingActions.begin() + succ);  //succ bound should be same for both vectors
				break;  //go to next succ iteration
			}
		}
	}
}

void sendtoExploredSet()
{

}

void Puzzle::Successors(Board & s, vector<Board>& tempSuccessors, vector<char>& correspondingActions)  //produce possible states (s') of s
{
	//if-else trees controlling blank space movement
	//push appropriate board configurations onto local successors vector
	//return successors vector, put into tempSuccessors vector in Search function
	//or just push appropriate board configurations onto tempSuccessors as it loops through, yay vectors!

	Board tempBoard;

	/*Get blank space position of parent node*/
	coordinates blank_space_coord;
	int blank_row, blank_col;
	int blank_space_linearloc;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (s.get_Board(row, col) == 0)
			{
				blank_space_coord.setRow(row);
				blank_space_coord.setCol(col);
				blank_row = row;
				blank_col = col;
				blank_space_linearloc = (row*width + col);
			}
		}
	}

	bool up=false, down=false, left=false, right=false;
	//check up, down, left, and right possibilies
	//          initial -> final
	//going up: (row, col) -> ((row-1), col)
	//going down: (row, col) -> ((row+1), col)
	//going left: (row, col) -> (row, (col-1))
	//going right: (row, col) -> (row, (col+1))
	//check if final is legal move, if so, create board with the blank swapping positions with whatever value is there
	//
	//
	//up = checkMove(blank_space_coord, 'u')
	//if (up) { tempBoard = produce_Board(); 
//		tempSuccessors.push(tempBoard)  }
	// .....
	int value_to_move;

	up = check_move(blank_space_coord, 'u');
	if (up)
	{
		tempBoard = s;
		value_to_move = tempBoard.get_Board(blank_row - 1, blank_col);  //get val to be moved from direction that blank space is going
		tempBoard.set_Board(blank_row, blank_col, value_to_move);  //set blank space as other val
		tempBoard.set_Board(blank_row - 1, blank_col, 0);  //set/move blank up one, where other val replaced blank area
		tempSuccessors.push_back(tempBoard);  //push onto successor vector

		correspondingActions.push_back('u');
		//coord of value to swap with blank0 value: (row-1, col)
		//tempBoard = produce_Board(); 
//		tempSuccessors.push(tempBoard)
	}

	down = check_move(blank_space_coord, 'd');
	if (down)
	{
		tempBoard = s;
		value_to_move = tempBoard.get_Board(blank_row + 1, blank_col);  //get val to be moved from direction that blank space is going
		tempBoard.set_Board(blank_row, blank_col, value_to_move);  //set blank space as other val
		tempBoard.set_Board(blank_row + 1, blank_col, 0);  //set/move blank down one, where other val replaced blank area
		tempSuccessors.push_back(tempBoard);  //push onto successor vector

		correspondingActions.push_back('d');
		//coord of value to swap with blank0 value: (row+1, col)
		//tempBoard = produce_Board(); 
		//		tempSuccessors.push(tempBoard)
	}

	left = check_move(blank_space_coord, 'l');
	if (left)
	{
		tempBoard = s;
		value_to_move = tempBoard.get_Board(blank_row, blank_col - 1);  //get val to be moved from direction that blank space is going
		tempBoard.set_Board(blank_row, blank_col, value_to_move);  //set blank space as other val
		tempBoard.set_Board(blank_row, blank_col - 1, 0);  //set/move blank left one, where other val replaced blank area
		tempSuccessors.push_back(tempBoard);  //push onto successor vector

		correspondingActions.push_back('l');
		//coord of value to swap with blank0 value: (row, col-1)
		//tempBoard = produce_Board(); 
		//		tempSuccessors.push(tempBoard)
	}

	right = check_move(blank_space_coord, 'r');
	if (right)
	{
		tempBoard = s;
		value_to_move = tempBoard.get_Board(blank_row, blank_col + 1);  //get val to be moved from direction that blank space is going
		tempBoard.set_Board(blank_row, blank_col, value_to_move);  //set blank space as other val
		tempBoard.set_Board(blank_row, blank_col + 1, 0);  //set/move blank right one, where other val replaced blank area
		tempSuccessors.push_back(tempBoard);  //push onto successor vector

		correspondingActions.push_back('r');
		//coord of value to swap with blank0 value: (row, col+1)
		//tempBoard = produce_Board(); 
		//		tempSuccessors.push(tempBoard)
	}

	/*TESTING PURPOSES - PRINT SUCCESSORS WITH PARENT*/
	//cout << "Parent: " << endl;
	//s.Print();

	//for (int succ = 0; succ < tempSuccessors.size(); succ++)  //for each successor in tempSuccessors
	//{
	//	cout << "Succ " << succ << ": " << endl;
	//	tempSuccessors[succ].Print();
	//	cout << endl;
	//}


}

bool Puzzle::check_move(coordinates blank_pos, char direction_of_movement)  //consider using INTs to represent blank row and col, if logic error arises
{
	int tempRow, tempCol;

	if (direction_of_movement == 'u')
	{
		tempRow = blank_pos.getRow();
		if ((tempRow - 1) < 0) //beyond the bound of 0th row, move not possible
		{
			return false;
		}
		else  //not passed the 0th row
		{
			return true;  
		}
	}
	else if (direction_of_movement == 'd')
	{
		tempRow = blank_pos.getRow();
		if ((tempRow + 1) > 3)  //beyond the 3rd row, move not possible
		{
			return false;
		}
		else  //not passed the 3rd row, possible
		{
			return true;
		}
	}
	else if (direction_of_movement == 'l')
	{
		tempCol = blank_pos.getCol();
		if ((tempCol - 1) < 0)  //beyond the bound of 0th column, not possible
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (direction_of_movement == 'r')
	{
		tempCol = blank_pos.getCol();
		if ((tempCol + 1) > 3)  //beyond the bound of 3rd column, not possible
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		cout << "ERROR: Improper direction_of_movement value." << endl;
		exit(EXIT_FAILURE);
	}
}

int Puzzle::heuristic_medium(/*vector<Node>&*/Node & N, int heuristic_choice)  //individually passes each node in the fringe to the heuristic function and determines h(n)
{
	int heuristic_value;

	if (heuristic_choice == 1)  //manhattan distance
	{
		heuristic_value = manhattan_Distance(N);
	}
	else if (heuristic_choice == 0) //misplaced tiles
	{
		heuristic_value = misplaced_Heuristic(N);
	}
	else
	{
		cout << "ERROR: invalid heuristic choice." << endl;
		exit(EXIT_FAILURE);
	}

	return heuristic_value;
}

/*Node &*/int Puzzle::fringe_choice() //scans fringe for node with lowest f(n) value and returns it [put into local N var of Search() and send to remove(fringe) function]
{
//	int size_of_fringe = fringe.size();
//	int * f_values = new int[size_of_fringe];
	int tempVal = 100000;//INT_MAX;  //possibility of logic error later when comparing below?
	int lesser_element;

	///*Iterate through each node in the fringe and obtain f(N) values*/
	//for (int x = 0; x < size_of_fringe; x++)
	//{
	//	f_values[x] = fringe[x].f_n;
	//}

	/*Compare each node in fringe and determine which f(N) is smallest*/
	//for (int x = 0; x < fringe.size(); x++)
	//{
	//	if (fringe[x].f_n < tempVal)
	//	{
	//		tempVal = fringe[x].f_n;
	//		lesser_element = x;
	//	}
	//}

	for (int x = 0; x < fringe_ptr.size(); x++)
	{
		if (fringe_ptr[x]->f_n < tempVal)
		{
			tempVal = fringe_ptr[x]->f_n;
			lesser_element = x;
		}
	}

	return lesser_element;

//	delete[] f_values;
}

coordinates Puzzle::j_to_Coord_Convert(int j)
{
	int expected_Val;
	coordinates jCoord;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			expected_Val = (row*width + col);
			if (j == expected_Val)
			{
				jCoord.setRow(row);
				jCoord.setCol(col);
			}
		}
	}

	return jCoord;
}

bool Puzzle::puzzle_Solvable()  //only called after randomize function, program using Node * initialNode var
{
	///*TEST PURPOSES*/
	//Board testBoard;
	//testBoard.set_Board(0, 0, 0);//0
	//testBoard.set_Board(0, 1, 1);//1
	//testBoard.set_Board(0, 2, 2);//2
	//testBoard.set_Board(0, 3, 5);//3
	//testBoard.set_Board(1, 0, 4);//4
	//testBoard.set_Board(1, 1, 7);//5
	//testBoard.set_Board(1, 2, 6);//6
	//testBoard.set_Board(1, 3, 3);//7
	//testBoard.set_Board(2, 0, 11);//8
	//testBoard.set_Board(2, 1, 10);//9
	//testBoard.set_Board(2, 2, 9);//10
	//testBoard.set_Board(2, 3, 8);//11
	//testBoard.set_Board(3, 0, 15);//12
	//testBoard.set_Board(3, 1, 14);//13
	//testBoard.set_Board(3, 2, 13);//14
	//testBoard.set_Board(3, 3, 12);//15
	///**/

	///*TESTING FUNCTION: PRINT*/
	//int current_Val;
	//for (int row = 0; row < 4; row++)
	//{
	//	for (int col = 0; col < 4; col++)
	//	{
	//		current_Val = testBoard.get_Board(row, col);
	//		cout << " " << current_Val;
	//	}
	//	cout << endl;
	//}

	int current_i;  //i
	int current_j;  //j
	int n[15];  //inversions. [n-1 .. (n-1)-1]
	int num_of_rows = 4; 
	int inversion_count = 0;
	int perm_inversion_total_N = 0; 
	int sum_N_rows;  //sum of N and number of rows
	n[0] = 0;  //i = 1 permutation
	bool firstIteration = true;
	int col_fixed;

	/*Traverses the board and checks for permutation inversions of each element*/
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			/*Get i value of square (row, col)*/
			current_i = initialNode->data.get_Board(row, col);
		//	current_i = current_Board.get_Board(row, col);
		/*	current_i = testBoard.get_Board(row, col);*/

			if ((current_i != 1) && (current_i != 0))  //no number less than 1; skip blank space
			{
				/*Scans entire board against the current_i value at (row, col)*/
				for (int x = row; x < 4; x++)
				{
					/*Ensures iteration through all columns of remaining rows after the first row*/
					if (firstIteration) { col_fixed = col; }
					else { col_fixed = 0; }

					for (int y = col_fixed; y < 4; y++)
					{
						/*Get j value in front of i*/
						current_j = initialNode->data.get_Board(x, y);
				/*		current_j = testBoard.get_Board(x, y);*/

						/*If j is less than i, increment inversion counter*/
						if ((current_j != 0) && (current_j != current_i))
						{
							if (current_i > current_j)
							{
								inversion_count++;
							}
						}
						
						/*Iteration control for columns*/
						if (y == 3) { firstIteration = false; }
					}
				}

				/*save permutation inversions for i*/
				n[current_i - 1] = inversion_count;

				/*cout << "n [ " << current_i << " ] = " << inversion_count << endl; */

				/*Reset inversion counter*/
				inversion_count = 0;
				
				/*Reset iteration control for column iteration*/
				firstIteration = true;
			}
		}
	}

	/*Calculate sum of all permutation inversions (Sigma^(15)_(i=1) = N)*/
	for (int x = 0; x < 15; x++)
	{
		perm_inversion_total_N = perm_inversion_total_N + n[x];
	}

	/*cout << "N = " << perm_inversion_total_N << endl;*/

	/*Get row of blank space*/
	int blank_row = 0;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (initialNode->data.get_Board(row, col) == 0)
			{
				blank_row = row;
			}
		}
	}

	/*Compensate for 0..n element notation*/
	blank_row++;

	/*Check whether the sum of N and blank_row is even or not and return solution*/
	sum_N_rows = perm_inversion_total_N + blank_row;
	/*cout << "N + e = " << sum_N_rows << endl; */

	if (((sum_N_rows) % 2) == 0)  //if even
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Puzzle::insert_To_Fringe(Node & N)
{
//	fringe.push_back(N);
	fringe_ptr.push_back(&N); 


	//if (fringe_counter == 0)  //if fringe is empty
	//{
	//	Node tempNode;
	//	tempNode = N;

	//	fringe = new Node[1];
	//	fringe[0] = N;
	//}
	//else
	//{

	//}
}

bool Puzzle::fringe_empty_check()
{
	if (fringe_ptr.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//void currentBoard_To_PathList

