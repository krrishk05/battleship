#include "Carrier.h"

Carrier::Carrier() {
	shipSize = 5;
	isafloat = true;
	shipLetter = 'A'; 
}

void Carrier::PlaceShip(int x, int y, PlayerBoard* p) {

	p->SetPlayerBoard(x, y, shipLetter, Orientation, shipSize);
	//Set Ships to Player Board
}

void Carrier::PlaceCPUShip(int x, int y, CPUBoard* c) {

	c->SetCPUBoard(x, y, shipLetter, Orientation, shipSize);
	//Set Ships to CPU Board
}