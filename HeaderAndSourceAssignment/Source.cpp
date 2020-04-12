//declaring libraries needed
#include <iostream>
#include <string>
//declaring header file needed
#include "StoryFunctions.h"

//declaring namespace needed
using namespace std;

int main()
{
	//stage number
	int stage = 1;
	int& r_stage = stage;

	//plays the introduction
	introduction();

	//grabs user input
	string answer = InputCommand();
	string& r_answer = answer;

	//if the player types start, run the game until it reaches stage 2
	while (startGame(r_answer))
	{
		//runs game
		playStage(r_stage);
		//if stage = 2, then end the game if not, move on to stage 2
		if (r_stage == 2) 
		{
			//ends game
			return 0;
		}
		else
		{
			//changes to stage 2
			r_stage = nextStage(r_stage);
		}
	}

	//ends the program if the player didn't type start
	return 0;
}