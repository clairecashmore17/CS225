#pragma once
// Final Boss battle
// by Claire Cashmore
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

class finalRoom {
private:
	bool gameOver;
	bool win;
	bool weaponPossesion;
	const int width = 20;
	const int height = 12;
	int badGuyTime;
	int badGuyHealth;
	int x, y, weaponX, weaponY, badGuyX, badGuyY, weaponCollected;
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	//Stores the direction in dir
	eDirection dir;

public:
	finalRoom() {
		gameOver = false, win = false;
		weaponPossesion = false;
		badGuyTime = 0;
		badGuyHealth = 20;
		x, y, weaponX, weaponY, badGuyX = 0, badGuyY = 0, weaponCollected = 0;
	};
	void Setup();
	void Draw();
	void Input();
	bool Logic(bool gameOver);
	void checkWon() {
		if (win == true) {
			cout << "You beat the kid!" << endl;
		}
		else {
			cout << "You died at the hands of a child..." << endl;
		}
	}
	void runGame();
};
