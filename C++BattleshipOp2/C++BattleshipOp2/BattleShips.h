#pragma once
#include <iostream>
using namespace std;

class BattleShips {
protected:
	const int carrier = 5;
	const int battleship = 4;
	const int cruiser = 3;
	const int submarine = 3;
	const int destroyer = 2;
public:
	//pure virtual function
	virtual void setShips() = 0;
};