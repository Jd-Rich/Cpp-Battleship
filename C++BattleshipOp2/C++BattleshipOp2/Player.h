#pragma once
#include <iostream>
#include "Player.h"
#include "Board.h"
using namespace std;

class Player : public Board {
private:
	int turns = 0; 
	int actualTurns = 0;
public:
	char playerBoard[ROWS][COLS];

	void initializePlayerBoard();
	void playerTurn(); 

	void checkShipsHealth();
	void setCarrierHealth(int pHealth);
	void setBattleShipHealth(int pHealth);
	void setCruiserHealth(int pHealth);
	void setSubmarineHealth(int pHealth);
	void setDestroyerHealth(int pHealth);

	int getCarrierHealth();
	int getBattleShipHealth();
	int getCruiserHealth();
	int getSubmarineHealth();
	int getDestroyerHealth();

	bool checkIfGameOver();
	void showPlayerBoard();

	int getTurns();
	int getActualTurns();
	void setTurns(int pTurns);
	void setActualTurns(int pActualTurns);

	void saveGame();
	void saveTurns(Player &player); 
	void saveShipsHealth(Player &player);
	void loadGame();
	void loadTurns(Player &player); 
	void loadShipsHealth(Player &player);
};