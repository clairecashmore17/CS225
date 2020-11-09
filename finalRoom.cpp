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
	bool gameOver = false, win = false;
	bool weaponPossesion = false;
	const int width = 20;
	const int height = 12;
	int badGuyTime = 0;
	int badGuyHealth = 20;
	int x, y, weaponX, weaponY, badGuyX=0, badGuyY=0, weaponCollected = 0;
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	//Stores the direction in dir
	eDirection dir;

public:
	//finalRoom(bool gameOver = false, bool win = false, bool weaponPossesion = false, const int width = 20, const int height = 12, int badGuyTime = 0, int badGuyHealth = 100, int x, int y, int weaponX, int weaponY, int badGuyX = 0, int badGuyY = 0, int weaponCollected = 0);
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
	
};

// Color Function
void SetColor(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

//Set up our game stats
void finalRoom::Setup() {
	gameOver = false;
	// The direction is 0 so player is not moving originally
	dir = STOP;
	// Coordinates of head to start in center screen
	x = width / 2;
	y = height / 2;

	//Randomly weapons!
	srand(time(0));
	weaponX = rand() % width;
	weaponY = rand() % height;
	


}

//Draw to screen
void finalRoom::Draw() {
	//clears console window terminal
	system("cls");

	// Creates the top wall
	cout << "Collect a weapon(!) to fight the child(&), weapon only has 1 hit!" << endl;
	cout << "collected weapons : " << weaponCollected << endl;
	
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
			else if (i == badGuyY && j == badGuyX && weaponCollected > 0) {
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
		SetColor(4);
		cout << "YOU HAVE A WEAPON" << endl;
		SetColor(7);
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

		// Deals with head going through walls
		if (x >= width) {
			x = 0;
		}
		else if (x < 0) {
			x = width - 1;
		}
		else if (y >= height) {
			y = 0;
		}
		else if (y < 0) {
			y = height - 1;
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
		if ((x+1) == badGuyX && (y+1) == badGuyY && weaponPossesion == true) {
			badGuyHealth -= 10;
			badGuyX = width;
			badGuyY = height;
			weaponPossesion = false;
			SetColor(rand() % 10);
			cout << "Hit!" << endl;
			SetColor(7);
		}
		if ((x + 2) == badGuyX && (y + 2) == badGuyY && weaponPossesion == true) {
			badGuyHealth -= 10;
			badGuyX = width;
			badGuyY = height;
			weaponPossesion = false;
			SetColor(rand() % 10);
			cout << "Hit!" << endl;
			SetColor(7);
		}
		if (x == badGuyX && y == badGuyY && weaponPossesion == true) {
			badGuyHealth -= 10;
			badGuyX = width;
			badGuyY = height;
			weaponPossesion = false;
			SetColor(rand() % 10);
			cout << "Hit!" << endl;
			SetColor(7);
		}

		
		// IF we get weapon
		if (x == weaponX && y == weaponY) {
			weaponCollected += 1;
			weaponPossesion = true;
			//Randomly generates NEW fruits on screen
			srand(time(0));
			weaponX = rand() % width;
			weaponY = rand() % height;

		}
		if (badGuyHealth == 0) {
			gameOver = true;
			win = true;
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
			gameOver = Player.Logic(gameOver);
			if (gameOver == true)
				userInput = 'n';
		}
	}
	Player.checkWon();
	cout << "Game over? " << endl;
	cin >> userInput;
}
