#include "BattleShip.h"

BattleShip::BattleShip() {
	shipSize = 4;
	isafloat = true;
	shipLetter = 'B';
}

void BattleShip::PlaceShip(int x, int y, PlayerBoard* p) {

	p->SetPlayerBoard(x, y, shipLetter, Orientation, shipSize);
	//Set Ships to Player Board
}

void BattleShip::PlaceCPUShip(int x, int y, CPUBoard* c) {

	c->SetCPUBoard(x, y, shipLetter, Orientation, shipSize);
	//Set Ships to CPU Board
}