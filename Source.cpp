// ////////////////////////////////////////////////////////////////
//
// Project: 15-Puzzle-Solver
// Author: Christopher Anzalone
// File: Source.cpp				
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

#include <iostream>
#include <string>
#include "Puzzle.h"

using namespace std;

int main()
{
//	bool goalTestTEST = false;
//	bool puzzleSolveableTEST;
//	Puzzle thePuzzle;
//	thePuzzle.print_active_Board();  //prints current_Board
////	thePuzzle.save_Initial();  //saves path[0] to initial state 
//	int heuristic_choice; //0 for misplaced tiles, 1 for manhattan distance
//
//	cout << endl;
////	goalTestTEST = thePuzzle.Goal_Test();
//	if (goalTestTEST) { cout << "GOAL STATE REACHED"<<endl; }
//	else { cout << "NOTGOALSTATE"<<endl; }
//
//	cout << endl << "Testing randomize function" << endl;
//
//	thePuzzle.Randomize();  //randomizes initial_state -> NOW RANDOMIZES FRONT OF PATH
//
//	cout << endl << endl << "Testing misplaced H(n):" << endl;
//
////	thePuzzle.initial_To_Path0();
////	thePuzzle.update_Current_Board(); //update current_board with path[board_counter] (boardcount still 0)
//
////	int mispl_heur_test = thePuzzle.misplaced_Heuristic();
////	cout << "mispl_heur_test: " << mispl_heur_test << endl;
//	cout << endl;
//
////	int mandist_heur_test = thePuzzle.manhattan_Distance();
////	cout << "mandist_heur_test: " << mandist_heur_test << endl;
//	cout << endl;
//
//	puzzleSolveableTEST = thePuzzle.puzzle_Solvable();
//	if (puzzleSolveableTEST)
//	{
//		cout << "solvable. " << endl;
//	}
//	else
//	{
//		cout << "not solvable. " << endl;
//	}

	Puzzle aPuzzle;  //puzzle object declared. initial node is created with 0-15 layout
	bool solvableTest;
	int heuristic_choice=0;  //0-misplaced tiles, 1--manhattan distance

	/*Randomize function to scramble numbers on board*/
//	aPuzzle.Randomize();

	/*Check if randomized board is solvable*/
	solvableTest = aPuzzle.puzzle_Solvable();
	if (solvableTest) { cout << "Solvable!" << endl; }
	else { cout << "NOT solvable!" << endl; }

	//WRITE PSUEDO-RANDOM FUNCTION THAT PRODUCES REASONABLY SOLVED CONFIGURATIONS, FUCK.. WHY AM I SHOUTING?
	//ADD CODE TO CALL EACH INDIVIDUAL HEURISTIC WITH INITIAL STATE BOARD AND COMPARE RUNTIMES/NO. OF STEPS FOR BOTH 

	if (solvableTest)
	{
		cout << " Press enter to begin search." << endl;
		cin.ignore();
		//cin.get();


		/*TIME TO SEE HOW BROKEN THIS IS! Search! D: */
		if (heuristic_choice == 1)  //manhattan distance
		{
			aPuzzle.Search(1);
		}
		else if (heuristic_choice == 0) //misplaced
		{
			aPuzzle.Search(0);
		}
		else
		{
			cout << "ERROR: Incorrect value for heuristic_choice." << endl;
		}
	}

	cout << "end of program." << endl;

	return 0;
}