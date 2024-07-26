#include "Cruiser.h"

Cruiser::Cruiser() {
	shipSize = 3;
	isafloat = true;
	shipLetter = 'C';
}

void Cruiser::PlaceShip(int x, int y, PlayerBoard* p) {

	p->SetPlayerBoard(x, y, shipLetter, Orientation, shipSize);
	//Set Ships to Player Board
}

void Cruiser::PlaceCPUShip(int x, int y, CPUBoard* c) {

	c->SetCPUBoard(x, y, shipLetter, Orientation, shipSize);
	//Set Ships to CPU Board
}
