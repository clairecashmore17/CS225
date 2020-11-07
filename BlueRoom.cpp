/*
Blue Room code:
Code that creates the first room and puts the player through 4 games to get a numerical code to exit the room.

Note we NEED to make a style guide. One thing I will say is that comments should describe the logic behind code
instead of just describing it.
Last modified: 11/04/2020
Changelog: 
11/02/2020: Made the blueRoom class and filled out its functions
11/04/2020: Implemented the 3 game variants though its jank
TODO:
Make 3 variations of the game (color, extra symbol, faster) implementation for symbol is done but jank color is still a work in progress
comment and document
Change the numPad to align with regular numPads with lower numbers at the bottom ???
*/

#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <cmath>

using namespace std;

class blueRoom {
private:
	int positionArray[4], imposterPositionArray[4], doorPositionArray[4], userAnswer, gamePassCode, doorPassCode;
	static int doorPassCodeIndex;
	const char numPad[7][18] = {"__1____2____3___\n",
						        "|    |    |    |\n",
						        "__4____5____6___\n",
						        "|    |    |    |\n",
						        "__7____8____9___\n",
						        "|    |    |    |\n",
						        "________________\n" };
public:
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

int blueRoom::doorPassCodeIndex = 0;

int main() {
	blueRoom techGuy;

	techGuy.doorPasswordCreator();
	techGuy.intro();
	techGuy.introMemoryGame();
	techGuy.patternCheck();
	techGuy.symbolMemoryGame();
	techGuy.patternCheck();
	techGuy.symbolColorMemoryGame();
	techGuy.patternCheck();
	techGuy.fastSymbolColorMemoryGame();
	techGuy.patternCheck();
}

void blueRoom::intro() {
	cout << "This is a memory game Xs will flash in the grid below. Each correspond to a number remember the number and type in th correct combo to move on." << endl;
	for(int k = 0; k < 7; k++) {
		for (int j = 0; j < 18; j++)
			printf("%c", numPad[k][j]);
	}
	cout << "\nLets start with a warm up shall we?\n";
	usleep(3000000);
	system("cls");
}

void blueRoom::doorPasswordCreator() {
	unsigned int time_ui = unsigned int(time(NULL));
	doorPassCode = 0;
	srand(time_ui);
	for (int i = 0; i < 4; i++) {
		doorPositionArray[i] = (rand() % 8) + 1;
		doorPassCode += doorPositionArray[i] * pow(10, (3 - i));
	}
}

/*I see 2 options the game variants. Either have different functions for each variant
or have like a switch statement in here.

Took your advice and decided to go for the char array instead of the
string.*/
void blueRoom::introMemoryGame() {
	char gameNumPad[7][18] = { "__1____2____3___\n",
						       "|    |    |    |\n",
						       "__4____5____6___\n",
						       "|    |    |    |\n",
						       "__7____8____9___\n",
						       "|    |    |    |\n",
						       "________________\n" };
	gamePasswordCreator();
	for (int i = 0; i < 4; i++) {
		switch (positionArray[i]) {
		case 1:
			gameNumPad[1][2] = 'X';
			break;
		case 2:
			gameNumPad[1][7] = 'X';
			break;
		case 3:
			gameNumPad[1][12] = 'X';
			break;
		case 4:
			gameNumPad[3][2] = 'X';
			break;
		case 5:
			gameNumPad[3][7] = 'X';
			break;
		case 6:
			gameNumPad[3][12] = 'X';
			break;
		case 7:
			gameNumPad[5][2] = 'X';
			break;
		case 8:
			gameNumPad[5][7] = 'X';
			break;
		case 9:
			gameNumPad[5][12] = 'X';
			break;
		}
		for (int k = 0; k < 7; k++) {
			for (int j = 0; j < 18; j++) {
				printf("%c", gameNumPad[k][j]);
			}
		}
		usleep(1000000);
		system("cls");
		for (int k = 0; k < 7; k++) {
			for (int j = 0; j < 18; j++)
				gameNumPad[k][j] = numPad[k][j];
		}
		usleep(10000);
	}
}

/*this just adds some spuff symbols to trick the player. Implementation is janky and spaghetti
but all I'm doing is getting it up and running*/
void blueRoom::symbolMemoryGame() {
	char gameNumPad[7][18] = { "__1____2____3___\n",
						   "|    |    |    |\n",
						   "__4____5____6___\n",
						   "|    |    |    |\n",
						   "__7____8____9___\n",
						   "|    |    |    |\n",
						   "________________\n" };

	gamePasswordCreator();
	for (int i = 0; i < 4; i++) {
		switch (positionArray[i]) {
		case 1:
			gameNumPad[1][2] = 'X';
			break;
		case 2:
			gameNumPad[1][7] = 'X';
			break;
		case 3:
			gameNumPad[1][12] = 'X';
			break;
		case 4:
			gameNumPad[3][2] = 'X';
			break;
		case 5:
			gameNumPad[3][7] = 'X';
			break;
		case 6:
			gameNumPad[3][12] = 'X';
			break;
		case 7:
			gameNumPad[5][2] = 'X';
			break;
		case 8:
			gameNumPad[5][7] = 'X';
			break;
		case 9:
			gameNumPad[5][12] = 'X';
			break;
		}
		switch (imposterPositionArray[i]) {
		case 1:
			gameNumPad[1][2] = 'O';
			break;
		case 2:
			gameNumPad[1][7] = 'O';
			break;
		case 3:
			gameNumPad[1][12] = 'O';
			break;
		case 4:
			gameNumPad[3][2] = 'O';
			break;
		case 5:
			gameNumPad[3][7] = 'O';
			break;
		case 6:
			gameNumPad[3][12] = 'O';
			break;
		case 7:
			gameNumPad[5][2] = 'O';
			break;
		case 8:
			gameNumPad[5][7] = 'O';
			break;
		case 9:
			gameNumPad[5][12] = 'O';
			break;
		}
		for (int k = 0; k < 7; k++) {
			for (int j = 0; j < 18; j++) {
				printf("%c", gameNumPad[k][j]);
			}
		}
		usleep(1000000);
		system("cls");
		for (int k = 0; k < 7; k++) {
			for (int j = 0; j < 18; j++)
				gameNumPad[k][j] = numPad[k][j];
		}
		usleep(10000);
	}
}

/*this just adds some spuff Xs that are a different color from the regular Xs. Logic is wrong.
Currently it doesn't distinguish between imposter and real Xs just changes the color depending
on what is saw first.
Proposed work arounds*/
void  blueRoom::symbolColorMemoryGame() {
	char gameNumPad[7][18] = { "__1____2____3___\n",
						   "|    |    |    |\n",
						   "__4____5____6___\n",
						   "|    |    |    |\n",
						   "__7____8____9___\n",
						   "|    |    |    |\n",
						   "________________\n" };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int evenSymbolFlag = 0; //flag that tells the program which X to change to a specific color

	gamePasswordCreator();
	for (int i = 0; i < 4; i++) {
		switch (positionArray[i]) {
		case 1:
			gameNumPad[1][2] = 'X';
			break;
		case 2:
			gameNumPad[1][7] = 'X';
			break;
		case 3:
			gameNumPad[1][12] = 'X';
			break;
		case 4:
			gameNumPad[3][2] = 'X';
			break;
		case 5:
			gameNumPad[3][7] = 'X';
			break;
		case 6:
			gameNumPad[3][12] = 'X';
			break;
		case 7:
			gameNumPad[5][2] = 'X';
			break;
		case 8:
			gameNumPad[5][7] = 'X';
			break;
		case 9:
			gameNumPad[5][12] = 'X';
			break;
		}
		switch (imposterPositionArray[i]) {
		case 1:
			gameNumPad[1][2] = 'X';
			break;
		case 2:
			gameNumPad[1][7] = 'X';
			break;
		case 3:
			gameNumPad[1][12] = 'X';
			break;
		case 4:
			gameNumPad[3][2] = 'X';
			break;
		case 5:
			gameNumPad[3][7] = 'X';
			break;
		case 6:
			gameNumPad[3][12] = 'X';
			break;
		case 7:
			gameNumPad[5][2] = 'X';
			break;
		case 8:
			gameNumPad[5][7] = 'X';
			break;
		case 9:
			gameNumPad[5][12] = 'X';
			break;
		}
		for (int k = 0; k < 7; k++) {
			for (int j = 0; j < 18; j++) {
				if (gameNumPad[k][j] == 'X') {
					if(((evenSymbolFlag++)%2) != 1)
					   SetConsoleTextAttribute(hConsole, 10); // the for is a green color can change to make it different colors heres the stackoverflow like https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
					else
					   SetConsoleTextAttribute(hConsole, 14); // sets to a yellow color
				}
				printf("%c", gameNumPad[k][j]);
				SetConsoleTextAttribute(hConsole, 7); // makes the text white
			}
		}
		usleep(1000000);
		system("cls");
		for (int k = 0; k < 7; k++) {
			for (int j = 0; j < 18; j++)
				gameNumPad[k][j] = numPad[k][j];
		}
		usleep(10000);
	}
}

/*much too fast version of symbolColorMemoryGame*/
void  blueRoom::fastSymbolColorMemoryGame() {
	char gameNumPad[7][18] = { "__1____2____3___\n",
						   "|    |    |    |\n",
						   "__4____5____6___\n",
						   "|    |    |    |\n",
						   "__7____8____9___\n",
						   "|    |    |    |\n",
						   "________________\n" };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int evenSymbolFlag = 0; //flag that tells the program which X to change to a specific color

	gamePasswordCreator();
	for (int i = 0; i < 4; i++) {
		switch (positionArray[i]) {
		case 1:
			gameNumPad[1][2] = 'X';
			break;
		case 2:
			gameNumPad[1][7] = 'X';
			break;
		case 3:
			gameNumPad[1][12] = 'X';
			break;
		case 4:
			gameNumPad[3][2] = 'X';
			break;
		case 5:
			gameNumPad[3][7] = 'X';
			break;
		case 6:
			gameNumPad[3][12] = 'X';
			break;
		case 7:
			gameNumPad[5][2] = 'X';
			break;
		case 8:
			gameNumPad[5][7] = 'X';
			break;
		case 9:
			gameNumPad[5][12] = 'X';
			break;
		}
		switch (imposterPositionArray[i]) {
		case 1:
			gameNumPad[1][2] = 'X';
			break;
		case 2:
			gameNumPad[1][7] = 'X';
			break;
		case 3:
			gameNumPad[1][12] = 'X';
			break;
		case 4:
			gameNumPad[3][2] = 'X';
			break;
		case 5:
			gameNumPad[3][7] = 'X';
			break;
		case 6:
			gameNumPad[3][12] = 'X';
			break;
		case 7:
			gameNumPad[5][2] = 'X';
			break;
		case 8:
			gameNumPad[5][7] = 'X';
			break;
		case 9:
			gameNumPad[5][12] = 'X';
			break;
		}
		for (int k = 0; k < 7; k++) {
			for (int j = 0; j < 18; j++) {
				if (gameNumPad[k][j] == 'X') {
					if (((evenSymbolFlag++) % 2) != 1)
						SetConsoleTextAttribute(hConsole, 10); // the for is a maroonish color can change to make it different colors heres the stackoverflow like https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
					else
						SetConsoleTextAttribute(hConsole, 14);
				}
				printf("%c", gameNumPad[k][j]);
				SetConsoleTextAttribute(hConsole, 7); // makes the text white
			}
		}
		usleep(500000);
		system("cls");
		for (int k = 0; k < 7; k++) {
			for (int j = 0; j < 18; j++)
				gameNumPad[k][j] = numPad[k][j];
		}
		usleep(10000);
	}
}

void blueRoom::patternCheck() {
	system("cls");
	cout << "Got that? hopefully you did or else. Enter your combo: ";
	cin >> userAnswer;

	if (userAnswer == gamePassCode) {
		cout << "Congrats you get a digit of the code: " << doorPositionArray[doorPassCodeIndex] << endl;
		doorPassCodeIndex++;
	}
	else
		cout << "Unfortunate" << endl;
	if (doorPassCodeIndex == 4) {
		cout << "Well now you should have the code, but the question is can you remember? ";
		cin >> userAnswer;
		if (userAnswer == doorPassCode)
			userAnswer = 0; // placeholder
			//end screen
		else
			cout << "Sorry";
	}
	usleep(5000000);
	system("cls");
}

void blueRoom::gamePasswordCreator() {
	unsigned int time_ui = unsigned int(time(NULL));
	gamePassCode = 0;
	srand(time_ui);
	for (int i = 0; i < 4; i++) {
		positionArray[i] = (rand() % 8) + 1;
		imposterPositionArray[i] = (rand() % 8) + 1;
		gamePassCode += positionArray[i] * pow(10, (3 - i));
		if (positionArray[i] == imposterPositionArray[i]) {
			if (imposterPositionArray[i] == 9)
				imposterPositionArray[i]--;
			else
				imposterPositionArray[i]++;
		}
	}
}

//stolen from stackoverflow
void blueRoom::usleep(__int64 usec)
{
	HANDLE timer;
	LARGE_INTEGER ft;

	ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
}



/*OLD VERSIONS OF FUNCTIONS*/

/*void blueRoom::introMemoryGame() {
	gamePasswordCreator();
	for (int i = 0; i < 4; i++) {
		switch (positionArray[i]) {
		case 1:
			cout << "__1____2____3___" << endl;
			cout << "| X  |    |    |" << endl;
			cout << "__4____5____6___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__7____8____9___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "________________" << endl;
			break;
		case 2:
			cout << "__1____2____3___" << endl;
			cout << "|    | X  |    |" << endl;
			cout << "__4____5____6___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__7____8____9___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "________________" << endl;
			break;
		case 3:
			cout << "__1____2____3___" << endl;
			cout << "|    |    | X  |" << endl;
			cout << "__4____5____6___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__7____8____9___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "________________" << endl;
			break;
		case 4:
			cout << "__1____2____3___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__4____5____6___" << endl;
			cout << "| X  |    |    |" << endl;
			cout << "__7____8____9___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "________________" << endl;
			break;
		case 5:
			cout << "__1____2____3___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__4____5____6___" << endl;
			cout << "|    | X  |    |" << endl;
			cout << "__7____8____9___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "________________" << endl;
			break;
		case 6:
			cout << "__1____2____3___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__4____5____6___" << endl;
			cout << "|    |    | X  |" << endl;
			cout << "__7____8____9___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "________________" << endl;
			break;
		case 7:
			cout << "__1____2____3___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__4____5____6___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__7____8____9___" << endl;
			cout << "| X  |    |    |" << endl;
			cout << "________________" << endl;
			break;
		case 8:
			cout << "__1____2____3___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__4____5____6___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__7____8____9___" << endl;
			cout << "|    | X  |    |" << endl;
			cout << "________________" << endl;
			break;
		case 9:
			cout << "__1____2____3___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__4____5____6___" << endl;
			cout << "|    |    |    |" << endl;
			cout << "__7____8____9___" << endl;
			cout << "|    |    | X  |" << endl;
			cout << "________________" << endl;
			break;
		}
		usleep(1000000);
		system("cls");
		usleep(10000);
	}
}*/
