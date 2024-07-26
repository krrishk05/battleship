#pragma once
#include "Carrier.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "BattleShip.h"
#include "Cruiser.h"
class Game : public Carrier, public Submarine, public Destroyer, public Cruiser, public BattleShip
{
protected:


public:

	void CreateThePlayerBoard(PlayerBoard *P);
	void CreateCPUBoard(CPUBoard *C);
	void Battle(PlayerBoard *P, CPUBoard *C);
	void ClearScreen() { system("cls"); }
};

