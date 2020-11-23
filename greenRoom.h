#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <cmath>
#include "room.h"

using namespace std;

class greenRoom : public room{
private:
	int userLife;
	int userAnswer;
	int victoryCounter;
public:
	greenRoom() { userLife = 2; userAnswer = 0; victoryCounter = 0; }
	void rpsGame();
	void usleep(__int64 usec);
};
