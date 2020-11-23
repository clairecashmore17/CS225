#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <cmath>
#include "room.h"

using namespace std;

class blueRoom : public room{
private:
	int positionArray[4], imposterPositionArray[4], doorPositionArray[4], userAnswer, gamePassCode, doorPassCode;
	static int doorPassCodeIndex;
	const char numPad[7][18] = { "__1____2____3___\n",
								"|    |    |    |\n",
								"__4____5____6___\n",
								"|    |    |    |\n",
								"__7____8____9___\n",
								"|    |    |    |\n",
								"________________\n" };
public:
	void blueRoomRunThrough();
	void intro(); //We can defo make an abstract class called Room so we can override intro. In addition room can have the user name and other stats
	void gamePasswordCreator();
	void doorPasswordCreator();
	void patternCheck();
	void introMemoryGame();
	void symbolColorMemoryGame();
	void symbolMemoryGame();
	void fastSymbolColorMemoryGame();
	void usleep(__int64 usec);
};
