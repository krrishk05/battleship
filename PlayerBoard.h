//Player.h
#pragma once

#include <iostream>
using namespace std;

#include "Constants.h"

class PlayerBoard{

protected:

	char grid[gridSize][gridSize];
	bool targetingmode;
	bool hasmovedinTM;
	int targetcoords[2];
	int direc;

public:

	PlayerBoard();
	char GetBoardSpot(int x, int y) { return grid[x][y]; };
	void SetPlayerBoard(int x, int y, char ship, char o, int size);
	void CheckSpace(int X, int Y, char o, int size, bool *check);
	void CPUMove(int *PlayerAliveSpaces);
	void RandomMove(int* PlayerAliveSpaces);
	void ProcessMove(int x, int y, int* PlayerAliveSpaces);
	void TargetedMove(int* PlayerAliveSpaces);

	void DisplayPlayerBoard();
    
};

