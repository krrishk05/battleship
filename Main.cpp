// BattleShip.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
    srand(time(0));

    Game BattleShip;
    PlayerBoard Player;
    CPUBoard Computer;

    cout << "Welcome to Battleship!" << endl;
    cout << "------------------------------------" << endl;
    BattleShip.CreateThePlayerBoard(&Player);
    cout << endl;
    cout << "------------------------------------" << endl;
    BattleShip.CreateCPUBoard(&Computer);
    cout << endl;
    cout << endl;

    cout << "------------------------------------" << endl;
    BattleShip.Battle(&Player, &Computer);

}


