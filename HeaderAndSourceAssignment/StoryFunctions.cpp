//declaring libraries needed
#include  <iostream>
#include <string>
#include <stdlib.h>

//declaring namespace
using namespace std;

//returns a string for the intro
void introduction()
{
	cout << "\t\t***Welcome to Dungeon Escape!***\n\n A interactive fiction game where you have to find a way out of a dungeon using a list of commands.\n The commands are 'Look at', 'Grab', and 'Use'.\n To check what commands you have type 'Commands' for a refresher.\n Type 'Start' to begin or 'Quit' to leave the game.\n\n";
}

//returns true if the player inputed start and false if not
bool startGame(string& answer)
{
	if (answer == "START") {
		return true;
	}
	else
	{
		return false;
	}
}

//plays the stage based on the number inputed
int playStage(int& stageNum) 
{
	//keeps track of what the player is looking at
	string focusedOn;
	//user input
	string answer;

	//keeps track if user completed the level or not
	bool complete = false;
	//keeps track if user has the key
	bool hasKey = false;
	//keeps track if the door is unlocked
	bool doorUnlocked = false;
	//if it's stage one
	if (stageNum == 1)
	{
		//intro
		cout << "You wake up in a dark, cold room after being knocked by a giant monster from earlier.\n";
		cout << "You see a door and something shiny on the ground in the corner.\n\n What will you do?\n\n";

		//keep getting answers until player has escaped found
		while (!complete)
		{
			//grabs input
			getline(cin, answer);

			//if player inputs "look at shiny"
			if (answer == "look at shiny" || answer == "Look at shiny")
			{
				//changes the focus to the key
				focusedOn = "key";
				cout << "It appears to be a key!\n\n";
			}
			//if player inputs "look at door"
			else if (answer == "look at door" || answer == "Look at door")
			{
				//changes the focus to the door
				focusedOn = "door";
				cout << "it's just a door with a keyhole\n\n";
			}
			//if player inputs "grab key"
			else if (answer == "grab key" || answer == "Grab key")
			{
				//if focused on the key
				if (focusedOn == "key")
				{
					//player now has the key
					hasKey = true;
					cout << "You grabbed the key\n\n";
				}
				//if the player isnt focused on the key
				else
				{
					cout << "What key?\n\n";
				}
			}
			//if player inputs "grab door"
			else if (answer == "grab door" || answer == "Grab door")
			{
				//if door is unlocked
				if (doorUnlocked == true)
				{
					cout << "You grabbed the door and open it.\n\n";
					//completes the stage
					complete = true;
				}
				//if door isnt unlocked
				else
				{
					cout << "It's locked...\n\n";
				}
			}
			//if player inputs "use key"
			else if (answer == "use key" || answer == "Use key")
			{
				//if the focus is on the door and the player has the key
				if (focusedOn == "door" && hasKey == true) {
					doorUnlocked = true;
					cout << "You used the key on the door.\n\n";
				}
				//if the player doesnt have the key
				else if (hasKey == false)
				{
					cout << "what key?\n\n";
				}
				//if the player isnt looking at the door or doesnt have the key
				else
				{
					cout << "What are you looking at?\n\n";
				}
			}
			//if player inputs "Commands" 
			else if (answer == "Commands" || answer == "commands") {
				cout << "Look at 'object to look at', Use 'object to use', Grab 'object to grab', Quit (to quit the game), Commands (to see this again).\n\n";
			}
			//if player inputs anything else
			else
			{
				cout << "You can't do that. Please check your spelling or type 'Commands' to see what you can do.\n\n";
			}
		}
	}
	//when its stage 2
	else {
		cout << "You've unlocked the door and you see the outside world. You sigh in relief and head back home. \nThe End\n\n.";

		//ends the function
		return 0;
	}

	//ends the function
	return 0;
}

//Changes the stage number
int nextStage(int& stageNum)
{
	//adds one to the current stage num
	return stageNum + 1;
}

//recieves commands and converts them to caps
string InputCommand()
{
	string answer;
	getline(cin, answer);

	//make the answer caps to make it easier to read
	for (int i = 0; i < answer.length(); i++)
	{
		answer[i] = toupper(answer[i]);
	}

	//returned capped answer
	return answer;
}