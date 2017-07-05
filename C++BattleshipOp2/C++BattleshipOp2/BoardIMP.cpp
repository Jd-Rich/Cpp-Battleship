#include "Board.h"
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

//constructor
Board::Board() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = '.';
		}
	}
}

//functions
int Board::randomDirection(int min, int max) { //removes bias from lower end
	int n = max - min + 1;
	int remainder = RAND_MAX % n;
	int x;
	do {
		x = rand();
	} while (x >= RAND_MAX - remainder);

	return min + x % n;
}
void Board::clearBoard() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = '~';
		}
	}
}
void Board::showBoard() {
	cout << "***************************\n";
	cout << "*    0 1 2 3 4 5 6 7 8 9  *\n";
	for (int i = 0; i < ROWS; i++) {
		cout << "*  " << i << " ";
		for (int j = 0; j < COLS; j++) {
			cout << board[i][j] << " ";
		}
		cout << " *\n";
	}
	cout << "***************************\n";
}
//---------SHIPS-----------------//
void Board::placeCarrier() { //---5 spots
	bool goodRowNum = false;
	bool goodColNum = false;
	int direction = randomDirection(1, 4);
	if (direction == 1) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (r < 5) { //down
				goodRowNum = true;
				if (board[r][c] == '.') {
					for (int i = 0; i < carrier; i++) {
						board[r + i][c] = 'C';
					}
				}
			}
		} while (goodRowNum != true);
	}
	if (direction == 2) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (r > 5) { //up
				goodRowNum = true;
				if (board[r][c] == '.') {
					for (int i = 0; i < carrier; i++) {
						board[r - i][c] = 'C';
					}
				}
			}
		} while (goodRowNum != true);
	}
	if (direction == 3) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (c > 5) { //left
				goodColNum = true;
				if (board[r][c] == '.') {
					for (int i = 0; i < carrier; i++) {
						board[r][c - i] = 'C';
					}
				}
			}
		} while (goodColNum != true);
	}
	if (direction == 4) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (c < 5) { //right
				goodColNum = true;
				if (board[r][c] == '.') {
					for (int i = 0; i < carrier; i++) {
						board[r][c + i] = 'C';
					}
				}
			}
		} while (goodColNum != true);
	}
}
void Board::placeBattleship() { //---4 spots
	bool goodRowNum = false;
	bool goodColNum = false;
	int direction = randomDirection(1, 4);
	if (direction == 1) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (r < 4) { //down  //may need 6? originally r < 5
				if (board[r][c] == '.' && board[r + 1][c] != 'C' && board[r + 2][c] != 'C' && board[r + 3][c] != 'C') {
					goodRowNum = true;
					for (int i = 0; i < battleship; i++) {
						board[r + i][c] = 'B';
					}
				}
			}
		} while (goodRowNum != true);
	}
	if (direction == 2) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (r > 5) { //up
				if (board[r][c] == '.' && board[r - 1][c] != 'C' && board[r - 2][c] != 'C' && board[r - 3][c] != 'C') {
					goodRowNum = true;
					for (int i = 0; i < battleship; i++) {
						board[r - i][c] = 'B';
					}
				}
			}
		} while (goodRowNum != true);
	}
	if (direction == 3) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (c > 4) { //left ---was 5
				if (board[r][c] == '.' && board[r][c - 1] != 'C' && board[r][c - 2] != 'C' && board[r][c - 3] != 'C') {
					goodColNum = true;
					for (int i = 0; i < battleship; i++) {
						board[r][c - i] = 'B';
					}
				}
			}
		} while (goodColNum != true);
	}
	if (direction == 4) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (c < 6) { //right -- was 5
				if (board[r][c] == '.' && board[r][c + 1] != 'C' && board[r][c + 2] != 'C' && board[r][c + 3] != 'C') {
					goodColNum = true;
					for (int i = 0; i < battleship; i++) {
						board[r][c + i] = 'B';
					}
				}
			}
		} while (goodColNum != true);
	}
}
void Board::placeCruiser() { //---3 spots
	bool goodRowNum = false;
	bool goodColNum = false;
	int direction = randomDirection(1, 4);
	if (direction == 1) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (r < 7) {   //down
				if (board[r][c] == '.' && board[r + 1][c] != 'C' && board[r + 2][c] != 'C' && board[r + 3][c] != 'C'
					&& board[r + 1][c] != 'B' && board[r + 2][c] != 'B' && board[r + 3][c] != 'B') {
					goodRowNum = true;
					for (int i = 0; i < cruiser; i++) {
						board[r + i][c] = 'R';
					}
				}
			}
		} while (goodRowNum != true);
	}
	if (direction == 2) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (r > 3) { //up
				if (board[r][c] == '.' && board[r - 1][c] != 'C' && board[r - 2][c] != 'C' && board[r - 3][c] != 'C'
					&& board[r - 1][c] != 'B' && board[r - 2][c] != 'B' && board[r - 3][c] != 'B') {
					goodRowNum = true;
					for (int i = 0; i < cruiser; i++) {
						board[r - i][c] = 'R';
					}
				}
			}
		} while (goodRowNum != true);
	}
	if (direction == 3) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (c > 4) {  //left
				if (board[r][c] == '.' && board[r][c - 1] != 'C' && board[r][c - 2] != 'C' && board[r][c - 3] != 'C'
					&& board[r][c - 1] != 'B' && board[r][c - 2] != 'B' && board[r][c - 3] != 'B') {
					goodColNum = true;
					for (int i = 0; i < cruiser; i++) {
						board[r][c - i] = 'R';
					}
				}
			}
		} while (goodColNum != true);
	}
	if (direction == 4) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (c < 6) { //right 
				if (board[r][c] == '.' && board[r][c + 1] != 'C' && board[r][c + 2] != 'C' && board[r][c + 3] != 'C'
					&& board[r][c + 1] != 'B' && board[r][c + 2] != 'B' && board[r][c + 3] != 'B') {
					goodColNum = true;
					for (int i = 0; i < cruiser; i++) {
						board[r][c + i] = 'R';
					}
				}
			}
		} while (goodColNum != true);
	}
}
void Board::placeSubmarine() { //---3 spots
	bool goodRowNum = false;
	bool goodColNum = false;
	int direction = randomDirection(1, 4);
	if (direction == 1) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (r < 7) {   //down
				if (board[r][c] == '.' && board[r + 1][c] != 'C' && board[r + 2][c] != 'C' && board[r + 3][c] != 'C'
					&& board[r + 1][c] != 'B' && board[r + 2][c] != 'B' && board[r + 3][c] != 'B'
					&& board[r + 1][c] != 'R' && board[r + 2][c] != 'R' && board[r + 3][c] != 'R') {
					goodRowNum = true;
					for (int i = 0; i < submarine; i++) {
						board[r + i][c] = 'S';
					}
				}
			}
		} while (goodRowNum != true);
	}
	if (direction == 2) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (r > 3) { //up
				if (board[r][c] == '.' && board[r - 1][c] != 'C' && board[r - 2][c] != 'C' && board[r - 3][c] != 'C'
					&& board[r - 1][c] != 'B' && board[r - 2][c] != 'B' && board[r - 3][c] != 'B'
					&& board[r - 1][c] != 'R' && board[r - 2][c] != 'R' && board[r - 3][c] != 'R') {
					goodRowNum = true;
					for (int i = 0; i < submarine; i++) {
						board[r - i][c] = 'S';
					}
				}
			}
		} while (goodRowNum != true);
	}
	if (direction == 3) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (c > 4) {  //left
				if (board[r][c] == '.' && board[r][c - 1] != 'C' && board[r][c - 2] != 'C' && board[r][c - 3] != 'C'
					&& board[r][c - 1] != 'B' && board[r][c - 2] != 'B' && board[r][c - 3] != 'B'
					&& board[r][c - 1] != 'R' && board[r][c - 2] != 'R' && board[r][c - 3] != 'R') {
					goodColNum = true;
					for (int i = 0; i < submarine; i++) {
						board[r][c - i] = 'S';
					}
				}
			}
		} while (goodColNum != true);
	}
	if (direction == 4) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (c < 6) { //right 
				if (board[r][c] == '.' && board[r][c + 1] != 'C' && board[r][c + 2] != 'C' && board[r][c + 3] != 'C'
					&& board[r][c + 1] != 'B' && board[r][c + 2] != 'B' && board[r][c + 3] != 'B'
					&& board[r][c + 1] != 'R' && board[r][c + 2] != 'R' && board[r][c + 3] != 'R') {
					goodColNum = true;
					for (int i = 0; i < submarine; i++) {
						board[r][c + i] = 'S';
					}
				}
			}
		} while (goodColNum != true);
	}
}
void Board::placeDestroyer() { //---2 spots
	bool goodRowNum = false;
	bool goodColNum = false;
	int direction = randomDirection(1, 4);
	if (direction == 1) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (r < 8) {   //down
				if (board[r][c] == '.' && board[r + 1][c] != 'C' && board[r + 2][c] != 'C' && board[r + 3][c] != 'C'
					&& board[r + 1][c] != 'B' && board[r + 2][c] != 'B' && board[r + 3][c] != 'B'
					&& board[r + 1][c] != 'R' && board[r + 2][c] != 'R' && board[r + 3][c] != 'R'
					&& board[r + 1][c] != 'S' && board[r + 2][c] != 'S' && board[r + 3][c] != 'S') {
					goodRowNum = true;
					for (int i = 0; i < destroyer; i++) {
						board[r + i][c] = 'D';
					}
				}
			}
		} while (goodRowNum != true);
	}
	if (direction == 2) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (r > 2) { //up
				if (board[r][c] == '.' && board[r - 1][c] != 'C' && board[r - 2][c] != 'C' && board[r - 3][c] != 'C'
					&& board[r - 1][c] != 'B' && board[r - 2][c] != 'B' && board[r - 3][c] != 'B'
					&& board[r - 1][c] != 'R' && board[r - 2][c] != 'R' && board[r - 3][c] != 'R'
					&& board[r - 1][c] != 'S' && board[r - 2][c] != 'S' && board[r - 3][c] != 'S') {
					goodRowNum = true;
					for (int i = 0; i < destroyer; i++) {
						board[r - i][c] = 'D';
					}
				}
			}
		} while (goodRowNum != true);
	}
	if (direction == 3) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (c > 3) {  //left
				if (board[r][c] == '.' && board[r][c - 1] != 'C' && board[r][c - 2] != 'C' && board[r][c - 3] != 'C'
					&& board[r][c - 1] != 'B' && board[r][c - 2] != 'B' && board[r][c - 3] != 'B'
					&& board[r][c - 1] != 'R' && board[r][c - 2] != 'R' && board[r][c - 3] != 'R'
					&& board[r][c - 1] != 'S' && board[r][c - 2] != 'S' && board[r][c - 3] != 'S') {
					goodColNum = true;
					for (int i = 0; i < destroyer; i++) {
						board[r][c - i] = 'D';
					}
				}
			}
		} while (goodColNum != true);
	}
	if (direction == 4) {
		do {
			int r = rand() % ROWS;
			int c = rand() % COLS;
			if (c < 7) { //right 
				if (board[r][c] == '.' && board[r][c + 1] != 'C' && board[r][c + 2] != 'C' && board[r][c + 3] != 'C'
					&& board[r][c + 1] != 'B' && board[r][c + 2] != 'B' && board[r][c + 3] != 'B'
					&& board[r][c + 1] != 'R' && board[r][c + 2] != 'R' && board[r][c + 3] != 'R'
					&& board[r][c + 1] != 'S' && board[r][c + 2] != 'S' && board[r][c + 3] != 'S') {
					goodColNum = true;
					for (int i = 0; i < destroyer; i++) {
						board[r][c + i] = 'D';
					}
				}
			}
		} while (goodColNum != true);
	}
}
void Board::setShips() {
	placeCarrier();
	placeBattleship();
	placeCruiser();
	placeSubmarine();
	placeDestroyer();
}
