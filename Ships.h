#pragma once
#include "PlayerBoard.h"
#include "CPU.h"

class Ships : public PlayerBoard, public CPUBoard
{

protected: 

	int shipSize;
	char shipLetter;
	bool isafloat = true;
	bool validplace;
	bool overlap = true;
	char Orientation;

public:

	Ships();

	int GetShipSize(){return shipSize;};
	bool GetFloatStaus() { return isafloat; };
	void SetShipPlace(PlayerBoard* p);
	void SetCPUShips(CPUBoard* c); 
	void SetShipSize(int start) { shipSize = start; };
	void SetFloatStaus(bool status) {isafloat = status; };

	virtual void PlaceShip(int x, int y, PlayerBoard *p) = 0; 
	virtual void PlaceCPUShip(int x, int y, CPUBoard* C) = 0;

};

