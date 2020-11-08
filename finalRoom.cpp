// Final Boss battle
// by Claire Cashmore
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
//Stores the direction in dir
eDirection dir;
class finalRoom {
private:
	bool gameOver = false;
	bool weaponPossesion = false;
	const int width = 20;
	const int height = 20;
	int badGuyTime = 0;
	int badGuyHealth = 100;
	int x, y, weaponX, weaponY, badGuyX, badGuyY, score;
	

public:
	void Setup();
	void Draw();
	void Input();
	bool Logic(bool gameOver);
	//void anotherRound();
};

// Color Function
void SetColor(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

//Set up our game stats
void finalRoom::Setup() {
	gameOver = false;
	// The direction is 0 so snake is not moving originally
	dir = STOP;
	// Coordinates of head to start in center screen
	x = width / 2;
	y = height / 2;

	//Randomly weapons!
	srand(time(0));
	weaponX = rand() % width;
	weaponY = rand() % height;
	score = 0;

	//Bad Guy's original location
	badGuyX = width / 2;
	badGuyY = height / 2;
}

//Draw to screen
void finalRoom::Draw() {
	//clears console window terminal
	system("cls");

	// Creates the top wall
	for (int i = 0; i < width + 2; i++)
		cout << "_";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//Left wall
			if (j == 0)
				cout << "|";
			// Creates the head
			if (i == y && j == x) {
				SetColor(2);
				cout << "O";
				SetColor(7);
			}
			// creates the weapon
			else if (i == weaponY && j == weaponX) {
				SetColor(14);
				cout << "!";
				SetColor(7);
			}
			//creates bad guy
			else if (i == badGuyY && j == badGuyX && score == 0) {
				SetColor(4);
				cout << "&";
				SetColor(7);
			}
			// Empty Playing Space   
			else {
					cout << " ";
			}
			// Right wall    
			if (j == width - 1)
				cout << "|";

		}
		cout << endl;
	}
	// Bottom wall
	for (int i = 0; i < width + 2; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "Bad Guy Health: " << badGuyHealth << endl;
	if (weaponPossesion == false) {
		cout << "NO WEAPON IN HAND" << endl;
	}
	else {
		cout << "YOU HAVE A WEAPON" << endl;
	}
}

// User Input for MOVING!

void finalRoom::Input() {

	// Sets  W A S D to UP LEFT DOWN RIGHT
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}

}

//Apply Our Created Functions with Logic
bool finalRoom::Logic(bool gameOver) {
	 
	//BAD GUY
	while (badGuyHealth > 0) {
		// this deals with the situation of going "through" walls
		if (badGuyX >= width) {
			badGuyX = 0;
			badGuyTime = rand() % 10;
		}
		else if (badGuyX < 0) {
			badGuyX = width - 1;
			badGuyTime = rand() % 10;
		}
		else if (badGuyY >= height) {
			badGuyY = 0;
			badGuyTime = rand() % 10;
		}
		else if (badGuyY < 0) {
			badGuyY = height - 1;
			badGuyTime = rand() % 10;
		}
		//This deals with movement of bad guy around playing field 
		//Notes: badGuyTime is to have random X and Y movements around the map
		else {
			if (badGuyTime < 25) {
				badGuyX++;
				badGuyTime = rand() % 100;
			}
			else if (badGuyTime > 24 && badGuyTime < 50) {
				badGuyY--;
				badGuyTime = rand() % 100;
			}
			else if (badGuyTime > 49 && badGuyTime < 75) {
				badGuyX--;
				badGuyTime = rand() % 100;
			}
			else if (badGuyTime > 74 && badGuyTime < 100) {
				badGuyY--;
				badGuyTime = rand() % 100;
			}
			else if (badGuyTime == 100) {
				badGuyTime = 0;
			}
		}



		// Movement of head
		switch (dir) {
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		default:
			break;
		}

		// Ends game if you hit bad guy without weapon
		if (x == badGuyX && y == badGuyY && weaponPossesion == false) {

			gameOver = true;
		}
		else if (x == badGuyX && y == badGuyY && weaponPossesion == true) {
			badGuyHealth -= 10;
			badGuyX = width;
			badGuyY = height;
			weaponPossesion = false;
		}
		// Ends game if you run into walls
		if (x > width || x < 0 || y > height || y < 0)
			gameOver = true;

		// IF we get weapon
		if (x == weaponX && y == weaponY) {

			weaponPossesion = true;
			//Randomly generates NEW fruits on screen
			srand(time(0));
			weaponX = rand() % width;
			weaponY = rand() % height;

		}
	}
	return gameOver;
}

int main() {
	
	char userInput;
	bool gameOver = false;
	finalRoom Player;
	cout << "Are you ready to play? y or n: ";
	cin >> userInput;
	while (userInput == 'y') {

		Player.Setup();
		while (!gameOver) {
			Player.Draw();
			Player.Input();
			Player.Logic(gameOver);
		}
	}
	cout << "Game over" << endl;

}
