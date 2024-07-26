#include "Submarine.h"

Submarine::Submarine() {
	shipSize = 2;
	isafloat = true;
	shipLetter = 'S';
}

void Submarine::PlaceShip(int x, int y, PlayerBoard* p) {

	p->SetPlayerBoard(x, y, shipLetter, Orientation, shipSize); 
	//Set Ships to Player Board
}

void Submarine::PlaceCPUShip(int x, int y, CPUBoard* c) {

	c->SetCPUBoard(x, y, shipLetter, Orientation, shipSize);
	//Set Ships to CPU Board
}