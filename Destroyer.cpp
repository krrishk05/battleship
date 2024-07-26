#include "Destroyer.h"

Destroyer::Destroyer() {
	shipSize = 3;
	isafloat = true;
	shipLetter = 'D';

}

void Destroyer::PlaceShip(int x, int y, PlayerBoard *p) {

	p->SetPlayerBoard(x, y, shipLetter, Orientation, shipSize); 
	//Set Ships to Player Board
}

void Destroyer::PlaceCPUShip(int x, int y, CPUBoard* c) {

	c->SetCPUBoard(x, y, shipLetter, Orientation, shipSize);
	//Set Ships to CPU Board

}