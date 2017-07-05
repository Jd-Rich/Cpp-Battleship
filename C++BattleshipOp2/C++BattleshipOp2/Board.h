#pragma once
#include "BattleShips.h"
const int ROWS = 10;
const int COLS = 10;

class Board : public BattleShips {
protected:
	char board[ROWS][COLS];
	int carrierHealth = 5;
	int battleshipHealth = 4;
	int cruiserHealth = 3;
	int submarineHealth = 3;
	int destroyerHealth = 2;
public:
	//constructor
	Board();

	//functions
	virtual void setShips();

	void clearBoard();
	void showBoard();

	void placeCarrier();
	void placeBattleship();
	void placeCruiser();
	void placeSubmarine();
	void placeDestroyer();

	int randomDirection(int min, int max);
};