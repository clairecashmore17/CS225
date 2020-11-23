#pragma once
// Example of how the storyline could work.
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <istream>
#include <ostream>
#include <fstream>
#include <windows.h>


using namespace std;

class pinkRoom {
private:
	int health = 100;
	int level = 1;
	char playerAnswer;

public:
	int levelUp() { level++; };
	int damage() { health = health - 10; }
	int displayQuestion(int x);
	void displayStory();
	void randomAttack();
};