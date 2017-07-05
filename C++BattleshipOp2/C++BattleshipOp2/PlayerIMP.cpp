#include <iostream>
#include <fstream>
#include <sstream>
#include "Player.h"
#include <string>
using namespace std;

void Player::playerTurn() {
	bool valid = false;
	do {
		int r = 0, c = 0;
		cout << "Enter a row" << endl;
		cin >> r;
		cout << "Enter a column" << endl;
		cin >> c;
		if (board[r][c] != 'C' && board[r][c] != 'B' && board[r][c] != 'R' && board[r][c] != 'S' && board[r][c] != 'D' && board[r][c] != 'M') {
			playerBoard[r][c] = 'M';
			cout << "MISS\n";
			valid == true;
		}
		if (board[r][c] == 'C' || 'B' || 'R' || 'S' || 'D') {
			if (board[r][c] == 'C') {
				cout << "hit\n";
				board[r][c] = 'X';
				playerBoard[r][c] = 'X';
				carrierHealth--;
				valid = true;
			}
			if (board[r][c] == 'B') {
				cout << "hit\n";
				board[r][c] = 'X';
				playerBoard[r][c] = 'X';
				battleshipHealth--;
				valid = true;
			}
			if (board[r][c] == 'R') {
				cout << "hit\n";
				board[r][c] = 'X';
				playerBoard[r][c] = 'X';
				cruiserHealth--;
				valid = true;
			}
			if (board[r][c] == 'S') {
				cout << "hit\n";
				board[r][c] = 'X';
				playerBoard[r][c] = 'X';
				submarineHealth--;
				valid = true;
			}
			if (board[r][c] == 'D') {
				cout << "hit\n";
				board[r][c] = 'X';
				playerBoard[r][c] = 'X';
				destroyerHealth--;
				valid = true;
			}
		}
		valid = true;
		turns++;
		actualTurns++;
		saveGame();
	} while (valid != true); 

	cout << "Total health left: \n" << "Carrier " << carrierHealth << "\n"
		<< "BattleShip " << battleshipHealth << "\n"
		<< "Cruiser " << cruiserHealth << "\n"
		<< "Submarine " << submarineHealth << "\n"
		<< "Destroyer " << destroyerHealth << "\n";
	checkShipsHealth();
}
void Player::checkShipsHealth() {
	int shipsLeft = 5;
	if (carrierHealth == 0) {
		cout << "CARRIER HAS SUNK \n";
		shipsLeft--;
		cout << shipsLeft << " Ships left!\n";
	}
	if (battleshipHealth == 0) {
		cout << " BATTLESHIP HAS SUNK \n";
		shipsLeft--;
		cout << shipsLeft << " Ships left!\n";
	}
	if (cruiserHealth == 0) {
		cout << " CRUISER HAS SUNK\n";
		shipsLeft--;
		cout << shipsLeft << " Ships left!\n";
	}
	if (submarineHealth == 0) {
		cout << " SUBMARINE HAS SUNK\n";
		shipsLeft--;
		cout << shipsLeft << " Ships left!\n";
	}
	if (destroyerHealth == 0) {
		cout << " DESTROYER HAS SUNK\n";
		shipsLeft--;
		cout << shipsLeft << " Ships left!\n";
	}
}
bool Player::checkIfGameOver() {
	if (carrierHealth == 0 && battleshipHealth == 0 && cruiserHealth == 0 && submarineHealth == 0 && destroyerHealth == 0) {
		cout << "Game Over!\n";
		return 0;
	}
}

void Player::showPlayerBoard() { 
	cout << "***************************\n";
	cout << "*    0 1 2 3 4 5 6 7 8 9  *\n";
	for (int i = 0; i < ROWS; i++) {
		cout << "*  " << i << " ";
		for (int j = 0; j < COLS; j++) {
			cout << playerBoard[i][j] << " ";
		}
		cout << " *\n";
	}
	cout << "***************************\n";
}
void Player::initializePlayerBoard() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			playerBoard[i][j] = '.';
		}
	}
}

void Player::saveGame() {
	ofstream outputFile;
	outputFile.open("saveGame.txt", ios::out);
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			outputFile << board[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			outputFile << playerBoard[i][j] << " ";
		}
		cout << endl;
	}

	cout << "GAME SAVED" << endl;
}
void Player::saveTurns(Player &player) { 
	ofstream outputFile;
	outputFile.open("saveTurns.txt", ios::out);
	outputFile << player.getActualTurns() << "\n"; 
}
void Player::saveShipsHealth(Player &player) {
	ofstream outputFile;
	outputFile.open("saveShips.txt", ios::out);
	outputFile << player.getCarrierHealth() << "\n";
	outputFile << player.getBattleShipHealth() << "\n";
	outputFile << player.getCruiserHealth() << "\n";
	outputFile << player.getSubmarineHealth() << "\n";
	outputFile << player.getDestroyerHealth() << "\n";
}
void Player::loadGame() {
	ifstream inFile;
	inFile.open("saveGame.txt", ios::in);
	if (!inFile) {
		cout << "Error finding file" << endl;
		exit(1);
	}
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			inFile >> board[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			inFile >> playerBoard[i][j];
		}
		cout << endl;
	}

	cout << "Game loaded" << endl;
}
void Player::loadTurns(Player &player) {
	ifstream inFile;
	string turns = " ";
	inFile.open("saveTurns.txt", ios::in);
	getline(inFile, turns);
	inFile.close();
	player.setActualTurns(atoi(turns.c_str()));
	
	cout << "LOADED TURNS IS " << getActualTurns() << endl;
}
void Player::loadShipsHealth(Player &player) {
	ifstream inFile;
	string carrierHP= " ";
	string battleShipHP= " ";
	string cruiserHP= " ";
	string submarineHP= " ";
	string destroyerHP= " ";
	inFile.open("saveShips.txt", ios::in);
	getline(inFile, carrierHP);
	getline(inFile, battleShipHP);
	getline(inFile, cruiserHP);
	getline(inFile, submarineHP);
	getline(inFile, destroyerHP);
	inFile.close();
	player.setCarrierHealth(atoi(carrierHP.c_str()));
	player.setBattleShipHealth(atoi(battleShipHP.c_str()));
	player.setCruiserHealth(atoi(cruiserHP.c_str()));
	player.setSubmarineHealth(atoi(submarineHP.c_str()));
	player.setDestroyerHealth(atoi(destroyerHP.c_str()));
}
int Player::getTurns() {
	return turns;
}
void Player::setTurns(int pTurns) {
	turns = pTurns;
}
int Player::getActualTurns() {
	return actualTurns;
}
void Player::setActualTurns(int pActualTurns) {
	actualTurns = pActualTurns;
}

void Player::setCarrierHealth(int pHealth) {
	carrierHealth = pHealth;
}
void Player::setBattleShipHealth(int pHealth) {
	battleshipHealth = pHealth;
}
void Player::setCruiserHealth(int pHealth) {
	cruiserHealth = pHealth;
}
void Player::setSubmarineHealth(int pHealth) {
	submarineHealth = pHealth;
}
void Player::setDestroyerHealth(int pHealth) {
	destroyerHealth = pHealth;
}

int Player::getCarrierHealth() {
	return carrierHealth;
}
int Player::getBattleShipHealth() {
	return battleshipHealth;
}
int Player::getCruiserHealth() {
	return cruiserHealth;
}
int Player::getSubmarineHealth() {
	return submarineHealth;
}
int Player::getDestroyerHealth() {
	return destroyerHealth;
}

