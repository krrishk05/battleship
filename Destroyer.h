#pragma once
#include "Ships.h"
class Destroyer : public Ships
{
protected:



public:

	Destroyer();
	void PlaceShip(int x, int y, PlayerBoard* p) override;
	void PlaceCPUShip(int x, int y, CPUBoard* c) override;

};