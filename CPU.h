#pragma once

#include "Constants.h"

#include <iostream>
using namespace std;

class CPUBoard{

protected:

	char CPUgrid[gridSize][gridSize];
	char CPUDisplayGrid[gridSize][gridSize];

public:

	CPUBoard();

	void DisplayCPUBoard();
	void DisplayTrueCPUBoard(); //Use for Troubleshooting

	void SetCPUBoard(int x, int y, char ship, char o, int size);
	char GetBoardSpot(int x, int y) { return CPUgrid[x][y]; };
	void CheckCPUSpace(int X, int Y, char o, int size, bool* check);

	void PlayerMove(int *CPUAliveSpaces);

	/*
	virtual int GetShipSize() = 0;
	virtual bool GetFloatStaus() = 0;
	virtual void SetShipPlace() = 0;
	virtual void CheckSpace(int X, int Y) = 0;
	virtual void SetShipSize(int start) = 0;
	virtual void SetFloatStaus(bool status) = 0;

	virtual void PlaceShip(int x, int y) = 0;
	virtual void ShipHit() = 0;
	*/

};