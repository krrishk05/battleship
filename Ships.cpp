#include "Ships.h"

Ships::Ships() {


}

void Ships::SetShipPlace(PlayerBoard* p) {

	int X;
	int Y;
	char choice;
	validplace = false;

	p->DisplayPlayerBoard();

	while (validplace == false) {

		bool validDirection = false;

		while (validDirection == false) {

			cout << "Select Ship Orientation. Vertical(v) or Horizontal(h)-(Must be lower case);" << endl;
			cin >> choice;

			if (choice == 'v' or choice == 'h') {

				Orientation = choice;
				validDirection = true;
			}

			else {
			
				cout << "Invalid Direction" << endl;
			
			}

		}

		cout << "Enter X Placement (1-10): ";
		cin >> X;
		cout << "Enter Y Placement (1-10): ";
		cin >> Y;
		cout << "Coordinates chosen for ship are (" << X << ", " << Y << ")" << endl;
		cout << "The Orientation is: " << Orientation << endl;
		X = X - 1;
		Y = Y - 1;
		p->CheckSpace(X, Y, Orientation, shipSize, &validplace);

		if (validplace == false){
			
			cout << "Invalid Spot. Please redo" << endl; 
		
		}

	}

	if (validplace == true) {
		cout << "Valid Spot" << endl;
		PlaceShip(X, Y, p);

	}

}

void Ships::SetCPUShips(CPUBoard* c) {

	int x, y, v;

	int min = 1;
	int max = 10;
	int minD = 1;
	int maxD = 3;
	char choice;
	validplace = false;

	while (validplace == false) {

		bool validDirection = false;

		while (validDirection == false) {

			v = min + rand() % (maxD - minD);

			if (v == 1) {

				choice = 'h';
			}

			else if (v == 2) { 

				choice = 'v';
			}

			else if (choice == 'v' or choice == 'h') {

				Orientation = choice;
				validDirection = true;
			}

		}

		x = min + rand() % (max - min);

		y = min + rand() % (max - min);


		x = x - 1;
		y = y - 1;

		c->CheckCPUSpace(x, y, Orientation, shipSize, &validplace);

		if (validplace == false) {

			

		}

	}

	if (validplace == true) {
		
		PlaceCPUShip(x, y, c);

	}

} 