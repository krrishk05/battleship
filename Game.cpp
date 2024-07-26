#include "Game.h"

void Game::CreateThePlayerBoard(PlayerBoard *P) {

    cout << "Are you Ready to Play BattleShip?" << endl;
    cout << "Place ships!" << endl;

    //Player Board Arrangement Starts

    Ships* ShipsofPlayer[5];
    Carrier* Pcarrier = new Carrier();
    BattleShip* Pbattleship = new BattleShip();
    Submarine* Psubmarine = new Submarine();
    Destroyer* Pdestroyer = new Destroyer();
    Cruiser* Pcruiser = new Cruiser();

    ShipsofPlayer[0] = Pcarrier;
    ShipsofPlayer[1] = Pbattleship;
    ShipsofPlayer[2] = Pdestroyer;
    ShipsofPlayer[3] = Pcruiser;
    ShipsofPlayer[4] = Psubmarine;

    for (int i = 0; i < 5; i++) {

        cout << endl;
        cout << "Placing: " << vesselNames[i] << "; Size: " << Sizes[i] << endl;
        ShipsofPlayer[i]->SetShipPlace(P);

    }
    //Player Board Arrangement Ends
}

void Game::CreateCPUBoard(CPUBoard* C) {

    ClearScreen();
    //CPU Board Arrangement Starts
    //srand(time(0));
    Ships* CPUBoardArray[5]; 
    Carrier* CPUcarrier = new Carrier(); 
    BattleShip* CPUbattleship = new BattleShip(); 
    Submarine* CPUsubmarine = new Submarine(); 
    Destroyer* CPUdestroyer = new Destroyer(); 
    Cruiser* CPUcruiser = new Cruiser(); 

    CPUBoardArray[0] = CPUcarrier; 
    CPUBoardArray[1] = CPUbattleship; 
    CPUBoardArray[2] = CPUdestroyer; 
    CPUBoardArray[3] = CPUcruiser; 
    CPUBoardArray[4] = CPUsubmarine; 

    for (int i = 0; i < 5; i++) {


        cout << endl;
        CPUBoardArray[i]->SetCPUShips(C);

    }
    //CPU Board Arrangement Ends
    
}

void Game::Battle(PlayerBoard *P, CPUBoard *C) {

    ClearScreen();
    int PlayerAliveSpaces = totalVesselSpaces;
    int CPUAliveSpaces = totalVesselSpaces;

    cout << endl;
    cout << "Player Ships: Set!" << endl;
    cout << "CPU Ships: Set" << endl;
    cout << "Get ready to play Battleship!" << endl;
    cout << endl;
    ClearScreen();
    //srand(time(0));

    while(PlayerAliveSpaces > 0 and CPUAliveSpaces > 0){

        cout << "------------------------------------" << endl;
        cout << "Player's Turn!"<< endl;
        cout << "PlayerAliveSpaces: " << PlayerAliveSpaces << endl;
        cout << "CPUAliveSpaces: " << CPUAliveSpaces << endl;
        P->DisplayPlayerBoard();
        cout << endl;
        C->PlayerMove(&CPUAliveSpaces);
        if (CPUAliveSpaces == 0) {

            break;
        }
        cout << "------------------------------------" << endl;
        cout << "CPU's Turn!" << endl;
        cout << "PlayerAliveSpaces: " << PlayerAliveSpaces << endl;
        cout << "CPUAliveSpaces: " << CPUAliveSpaces << endl;
        P->CPUMove(&PlayerAliveSpaces);
        if (PlayerAliveSpaces == 0) {

            break;
        }
        ClearScreen();
        cout << endl;
        cout << "------------------------------------" << endl;
        cout << "Enemy has missed!" << endl;

    }

    if (PlayerAliveSpaces == 0) {

        cout << "The CPU has Won" << endl;

    }

    else {

        cout << "Congradulations Player. You win!" << endl;

    }
}