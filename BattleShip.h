#pragma once
#include "Ships.h"
class BattleShip :public Ships
{
protected:



public:

	BattleShip();
	void PlaceShip(int x, int y, PlayerBoard* p) override;
	void PlaceCPUShip(int x, int y, CPUBoard* c) override;

};