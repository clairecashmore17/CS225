#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include "blueRoom.h"
#include "pinkRoom.h"
#include "greenRoom.h"
#include "finalRoom.h"

using namespace std;
using namespace std::chrono;

class storyLine {
private:
	blueRoom techGuy;
	pinkRoom pinkGirl;
	greenRoom dinoGuy;
	finalRoom finalGuy;
	string playerName;
	system_clock::time_point playerStartTime;
	system_clock::time_point playerEndTime;
	duration<double> playerDuration;
public:
	storyLine();
	//intro;
};