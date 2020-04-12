#pragma once
//declaring libraries needed
#include <iostream>
#include <string>
#include <stdlib.h>

//declaring namespace needed
using namespace std;

//prototyping functions
void introduction();
bool startGame(string& answer);
int playStage(int& stageNum);
int nextStage(int& stageNum);
string InputCommand();