/*Green Room Code
Game: Rock, Paper Scissors
Description: Code that runs a game of rock paper scissors to best 2 out of 3
Changelog:
11/07/2020: File created and everything thats in it
TODO:
Comment
get an intro
Add dialogue*/

#include "greenRoom.h"

using namespace std;

void greenRoom::rpsGame() {
	unsigned int time_ui = unsigned int(time(NULL));
	int dinoGuyAnswer;
	srand(time_ui);
	while ((victoryCounter < 2) && (userLife > 0)) {
		dinoGuyAnswer = (rand() % 2) + 1;
		cout << "Which will you choose:\n1. Rock\n2. Paper\n3. Scissor\n";
		cin >> userAnswer;

		cout << "On shoot.";
		usleep(1500000);
		system("cls");
		cout << "1...";
		usleep(1000000);
		system("cls");
		cout << "2...";
		usleep(1000000);
		system("cls");
		cout << "3...";
		usleep(1000000);
		system("cls");
		cout << "SHOOT...";
		usleep(1000000);
		system("cls");


		if (userAnswer == 1 && dinoGuyAnswer == 2) {
			cout << "Lose\n";
			userLife--;
		}
		else if (userAnswer == 2 && dinoGuyAnswer == 3) {
			cout << "Lose\n";
			userLife--;
		}
		else if (userAnswer == 3 && dinoGuyAnswer == 1) {
			cout << "Lose\n";
			userLife--;
		}
		else if (userAnswer == dinoGuyAnswer) {
			cout << "Tie\n";
			continue;
		}
		else {
			cout << "Win\n";
			victoryCounter--;
		}
	}
}

void greenRoom::usleep(__int64 usec)
{
	HANDLE timer;
	LARGE_INTEGER ft;

	ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
}
