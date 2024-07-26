#pragma once
#include "Ships.h"
class Carrier : public Ships
{

protected:



public:

	Carrier();
	void PlaceShip(int x, int y, PlayerBoard* p) override;
	void PlaceCPUShip(int x, int y, CPUBoard* c) override;

};