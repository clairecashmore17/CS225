#include "storyLine.h"

using namespace std;
using namespace std::chrono;

storyLine::storyLine() {
	playerStartTime = system_clock::now();
	cout << "Please enter your name: ";
	getline(cin, playerName);
	//intro
	techGuy.blueRoomRunThrough();
	//interlude
	pinkGirl.displayStory();
	//interlude
	dinoGuy.rpsGame();
	//interlude
	finalGuy.runGame();
	//outro
	playerEndTime = system_clock::now();
	playerDuration = duration_cast<seconds>(playerEndTime - playerStartTime);
	cout << "it took you " << playerDuration.count() << " minutes to complete\n";
}

int main() {
	storyLine player;
}