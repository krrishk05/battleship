#pragma once
#include "Ships.h"
class Cruiser : public Ships
{
protected:



public:

	Cruiser();
	void PlaceShip(int x, int y, PlayerBoard* p) override;
	void PlaceCPUShip(int x, int y, CPUBoard* c) override;

};

