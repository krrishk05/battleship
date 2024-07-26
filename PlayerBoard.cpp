#include "PlayerBoard.h"
#include <iostream>

PlayerBoard::PlayerBoard() {

    for (int c = 0; c < gridSize; c++) {

        for (int r = 0; r < gridSize; r++) {

            grid[r][c] = Water;
        }
    }

	targetingmode = 0;
	hasmovedinTM = 0;
	targetcoords[0] = -1;
	targetcoords[1] = -1;
	direc = -1;
	srand(time(0));

}

void PlayerBoard::CheckSpace(int X, int Y, char o, int size, bool *check) {

	int rulesobyed = 0;
	//DisplayPlayerBoard();

	if ((X >= 0 and X <= 9) and (Y >= 0 and Y <= 9)) {

		rulesobyed++;
		cout << "Co-ordinates Between 1 and 10" << endl;
		
	}

	if (o == 'v') {

		//cout << "Board end spot:" << Y + size - 1 << endl;

		if ((Y + size - 1) >= 0 and (Y + size - 1) <= 9) {

			rulesobyed = rulesobyed + 1;
			//cout << "Does not go OverBoard" << endl;

		}

	}

	if (o == 'h') {

		cout << "Board end spot:" << X + size<< endl;

		if ((X + size - 1) >= 0 and (X + size - 1) <= 9) {

			rulesobyed = rulesobyed + 1;
			//cout << "Does not go OverBoard" << endl;

		}

	}

	int Overlapcounter = 0;

	if (o == 'h') {

		cout << "You chose Horizontal." << endl;
		for (int c = X; c < size + X; c++) {

			if (GetBoardSpot(c, Y) == Water) {

				Overlapcounter = Overlapcounter + 1;
				//cout << GetBoardSpot(c, Y);
				//grid[c][Y] = '*';

			}

			else {

				Overlapcounter = 0;

			}

		}

		if (Overlapcounter == size) {

			rulesobyed = rulesobyed + 1;

		}

		else {

			cout << "Unable to PlaceShip due to Overlap" << endl;
		}

	}

	if (o == 'v') {

		cout << "You chose vertical." << endl;

		for (int c = Y; c < size + Y; c++) {

			if (GetBoardSpot(X, c) == Water) {

				Overlapcounter = Overlapcounter + 1;
				//cout << GetBoardSpot(X, c);
				//grid[X][c] = '*';
			}

			else {

				Overlapcounter = 0;

			}

		}

		if (Overlapcounter == size) {

			rulesobyed = rulesobyed + 1;

		}

		else {

			cout << "Unable to PlaceShip due to Overlap" << endl;
		}

	}

	if (rulesobyed == 3) {

		*check = true;
	}

	//DisplayPlayerBoard();
}

void PlayerBoard::SetPlayerBoard(int x, int y, char ship, char o, int size) {


	if (o == 'h') {

		for (int c = x; c < size + x; c++) {

			if (grid[c][y] = Water) {

				grid[c][y] = ship;

			}

		}

	}

	if (o == 'v') {

		for (int c = y; c < size + y; c++) {

			if (grid[x][c] = Water) {

				grid[x][c] = ship;

			}

		}

	}

	DisplayPlayerBoard();

}

void PlayerBoard::DisplayPlayerBoard() {

    cout << endl;
	cout << "Player Board" << endl;

	for (int r = 0; r < gridSize; r++) {

		cout << BoardNum[r] << " ";
	}

	cout << endl;
	for (int c = 0; c < gridSize; c++) {

		for (int r = 0; r < gridSize; r++) {

			cout << grid[r][c] << " ";
		}

		cout << BoardNum[c];
		cout << endl;
	}

}

void PlayerBoard::CPUMove(int* PlayerAliveSpaces) {

	if (!targetingmode) {
		RandomMove(PlayerAliveSpaces);
	}
	else {
		TargetedMove(PlayerAliveSpaces);
	}

}
void PlayerBoard::RandomMove(int* PlayerAliveSpaces) {

	cout << endl;
	int x = rand() % 10;
	int y = rand() % 10;

	ProcessMove(x, y, PlayerAliveSpaces);

}
void PlayerBoard::ProcessMove(int x, int y, int* PlayerAliveSpaces) {

	if (grid[y][x] == Water) {
		grid[y][x] = Miss;

	}
	else if (grid[x][y] == Miss || grid[x][y] == Hit) {
		RandomMove(PlayerAliveSpaces);
	}
	else {
		grid[x][y] = Hit; 
		DisplayPlayerBoard();
		cout << "Enemy has hit one of your ships! They get another turn. Press enter to continue:" << endl;
		cin.ignore();
		cin.get();

		targetingmode = 1;
		targetcoords[0] = x;
		targetcoords[1] = y;
		*PlayerAliveSpaces = *PlayerAliveSpaces - 1;
		TargetedMove(PlayerAliveSpaces);

	}

}
void PlayerBoard::TargetedMove(int* PlayerAliveSpaces) {

	int dx = 0;
	int dy = 0;
	int newx = targetcoords[0];
	int newy = targetcoords[1];

	// Initialize direc only when targeting mode is first started
	if (!hasmovedinTM) {
		direc = 0;
		hasmovedinTM = 1;
	}

	// Loop until all neighboring cells have been checked
	while (direc < 4) {

		switch (direc) {
		case 0: // Up
			dy = -1;
			dx = 0;
			break;
		case 1: // Down
			dy = 1;
			dx = 0;
			break;
		case 2: // Left
			dx = -1;
			dy = 0;
			break;
		case 3: // Right
			dx = 1;
			dy = 0;
			break;
		}

		newx += dx;
		newy += dy;

		// Check if new coordinates are within bounds and not already hit or missed
		if (newx >= 0 && newx < 10 && newy >= 0 && newy < 10 && grid[newx][newy] != Hit && grid[newx][newy] != Miss) {
			if (grid[newx][newy] == Water) {
				grid[newx][newy] = Miss;
				DisplayPlayerBoard();
				direc++; // Move to the next direction
				return;
			}
			else {
				grid[newx][newy] = Hit;
				DisplayPlayerBoard();
				*PlayerAliveSpaces = *PlayerAliveSpaces - 1;
				cout << "Enemy has hit one of your ships again! They get another turn. Press enter to continue." << endl;
				cin.ignore();
				cin.get();
			}
		}
		else {
			// If the move is invalid, move to the next direction
			newx = targetcoords[0];
			newy = targetcoords[1];
			direc++;
		}

	}

	// If all neighboring cells have been checked without a hit or miss, reset targeting mode
	targetingmode = 0;
	hasmovedinTM = 0;
	RandomMove(PlayerAliveSpaces);

}
