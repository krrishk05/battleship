#include "CPU.h"

CPUBoard::CPUBoard() {

    for (int c = 0; c < gridSize; c++) {
        for (int r = 0; r < gridSize; r++) {
            CPUgrid[c][r] = Water;
        }
    }

	for (int c = 0; c < gridSize; c++) {
		for (int r = 0; r < gridSize; r++) {
			CPUDisplayGrid[c][r] = gridUnknown;
		}
	}
	srand(time(0));

}

void CPUBoard::DisplayCPUBoard() {

	cout << "CPU Board: " << endl;
	for (int r = 0; r < gridSize; r++) {

		cout << BoardNum[r] << " ";
	}

	cout << endl;
	for (int c = 0; c < gridSize; c++) {

		for (int r = 0; r < gridSize; r++) {

			cout << CPUDisplayGrid[r][c] << " ";
		}

		cout << BoardNum[c];
		cout << endl;
	}
}

void CPUBoard::DisplayTrueCPUBoard() {

	cout << "True CPU Board: " << endl;

	for (int c = 0; c < gridSize; c++) {

		for (int r = 0; r < gridSize; r++) {

			cout << CPUgrid[r][c] << " ";
		}
		cout << endl;
	}
}


void CPUBoard::SetCPUBoard(int x, int y, char ship, char o, int size) {

	if (o == 'h') {

		for (int c = x; c < size + x; c++) {

			if (CPUgrid[c][y] = Water) {

				CPUgrid[c][y] = ship;

			}

		}

	}

	if (o == 'v') {

		for (int c = y; c < size + y; c++) {

			if (CPUgrid[x][c] = Water) {

				CPUgrid[x][c] = ship;

			}

		}

	}

	cout << endl;
	//DisplayCPUBoard();
	cout << endl;
}

void CPUBoard::CheckCPUSpace(int X, int Y, char o, int size, bool* check) {

	int rulesobyed = 0;
	//DisplayCPUBoard();

	if ((X >= 0 and X <= 9) and (Y >= 0 and Y <= 9)) {

		rulesobyed++;
		

	}

	if (o == 'v') {

		

		if ((Y + size - 1) >= 0 and (Y + size - 1) <= 9) {

			rulesobyed = rulesobyed + 1;
			

		}

	}

	if (o == 'h') {



		if ((X + size - 1) >= 0 and (X + size - 1) <= 9) {

			rulesobyed = rulesobyed + 1;


		}

	}

	int Overlapcounter = 0;

	if (o == 'h') {

		for (int c = X; c < size + X; c++) {

			if (GetBoardSpot(c, Y) == Water) {

				Overlapcounter = Overlapcounter + 1;


			}

			else {

				Overlapcounter = 0;

			}

		}

		if (Overlapcounter == size) {

			rulesobyed = rulesobyed + 1;

		}

		else {

		}

	}

	if (o == 'v') {

		for (int c = Y; c < size + Y; c++) {

			if (GetBoardSpot(X, c) == Water) {

				Overlapcounter = Overlapcounter + 1;
				
			}

			else {

				Overlapcounter = 0;

			}

		}

		if (Overlapcounter == size) {

			rulesobyed = rulesobyed + 1;

		}

		else {

		}

	}

	if (rulesobyed == 3) {

		*check = true;
	}

	//DisplayCPUBoard();
}

void CPUBoard::PlayerMove(int *CPUAliveSpaces) {

	DisplayCPUBoard();
	//DisplayTrueCPUBoard();
	//Used for Trouble shooting

	int x, y;
	bool invalid = true;

	invalid = true;

	cout << endl;
	cout << "~Player's Turn: " << endl;

	while (invalid) {

		cout << "Enter X attack: " << endl;
		cin >> x;
		cout << "Enter Y attack:" << endl;
		cin >> y;

		if ((x >= 1 and x <= 10) and (y >= 1 and y <= 10)) {

			invalid = false;

		}

		else {
		
			cout << "Invalid input; redo needed" << endl;
		}

	}

	x = x - 1;
	y = y - 1;

	if (CPUgrid[x][y] == Water) {
		CPUgrid[x][y] = Miss;
		CPUDisplayGrid[x][y] = Miss;
		DisplayCPUBoard();
		cout << "Missed!" << endl;
	}
	else if (CPUgrid[x][y] == Miss || CPUgrid[x][y] == Hit) { //CHANGE TO Hit

		cout << "ERROR! You already attacked this spot!" << endl;
		PlayerMove(CPUAliveSpaces);
	}
	else {
		CPUgrid[x][y] = Hit; //CHANGE TO Hit
		CPUDisplayGrid[x][y] = Hit;
		DisplayCPUBoard();
		cout << "Hit!" << endl;
		*CPUAliveSpaces = *CPUAliveSpaces - 1;

		if (*CPUAliveSpaces != 0) {

			cout << endl;
			cout << "Attack Again!" << endl;
			PlayerMove(CPUAliveSpaces);
		}

		else {
			DisplayCPUBoard();
		}
	}

}