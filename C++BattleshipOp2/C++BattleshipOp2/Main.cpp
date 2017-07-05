#include "Board.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
using namespace std;

void play(int input);

int main() {
	srand(time(NULL));
	int waitForIt = 0;
	int input = 0;

	cout << "Welcome to Battleship!\n";
	cout << "See how many turns it takes you to sink all the ships!\n";
	cout << "The game will save automatically after each turn\n";
	cout << "Enter 1 to play\n";
	cout << "Enter 2 to load\n";
	cin >> input;
	play(input);

	cout << "Press any key to quit...\n";
	cin >> waitForIt;
}
void play(int inp) {
	Player pOne;
	pOne.setShips();
	pOne.initializePlayerBoard();
	//play game
	if (inp == 1) {
		do {
			cout << "    THE BOARD\n";
			pOne.showBoard();
			cout << "    PLAYER BOARD\n";
			pOne.showPlayerBoard();
			pOne.playerTurn();
			pOne.saveTurns(pOne);
			pOne.saveShipsHealth(pOne);
			cout << "Aftersave actual turns is " << pOne.getActualTurns() << endl;
			if (pOne.checkIfGameOver() == 0) {
				pOne.setTurns(1000);
			}
		} while (pOne.getTurns() < 1000);
		cout << "You finished! It took you " << pOne.getActualTurns() << " turns!\n";
	}
	//play from loaded game
	if (inp == 2) {
		Player pTwo;
		pTwo.loadGame();
		pTwo.loadTurns(pTwo); 
		pTwo.loadShipsHealth(pTwo);
		do {
			cout << "    THE BOARD\n";
			pTwo.showBoard();
			cout << "    PLAYER BOARD\n";
			pTwo.showPlayerBoard();
			pTwo.playerTurn();
			cout << pTwo.getActualTurns();
	
			if (pTwo.checkIfGameOver() == 0) {
				pTwo.setTurns(1000);
			}
		} while (pTwo.getTurns() < 1000);
		cout << "You finished! It took you " << pTwo.getActualTurns() << " turns!\n";
	}
}

