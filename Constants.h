// Constants.h
#pragma once
#include <string>
#include <cstdlib>
using namespace std;

// Game play constants (standard game of battleship)
const int numVessels = 5;
const int gridSize = 10; 
const int totalVesselSpaces = 17;
const int BoardNum[gridSize] = {1, 2, 3, 4, 5 ,6, 7, 8, 9, 10};
const int Sizes[numVessels] = {5, 4, 3, 3, 2};
const string vesselNames[numVessels] = { "Carrier(A)","Battleship(B)","Destroyer(D)","Cruiser(C)", "Submarine(S)" };

// Grid value constants
const char Hit = '*';
const char Miss = 'O';
const char Water = 'w';
const char gridUnknown = '?';