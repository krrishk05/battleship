#pragma once
#include "Ships.h"
class Submarine : public Ships
{
protected:



public:

	Submarine();
	void PlaceShip(int x, int y, PlayerBoard* p) override;
	void PlaceCPUShip(int x, int y, CPUBoard* c) override;

};