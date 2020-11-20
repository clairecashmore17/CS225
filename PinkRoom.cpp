/*
PinkRoom code:
Game: Multiple Choice
Code that creates the pink room and puts the player through a series of questions that they must answer according to the little girl in charge.
Last modified: 11/20/2020
Changelog:
11/20/20: I commented it out and addded the proper header.
*/


#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <istream>
#include <ostream>
#include <fstream>
#include <windows.h>


using namespace std;

class playerStats {
private:
	int health = 100;
	int level = 1;
	char playerAnswer;

public:
	int levelUp() { level++; };
	int damage() { health = health - 10; }
	int displayAnswer(int x);
	void displayStory();
	void randomAttack();
};


// Color Function
void SetColor(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}
void playerStats::randomAttack() {
	int attack = rand() % 6;
	SetColor(4);
	if (attack == 0) {
		cout << "You were pelted with weighted stuffed animals." << endl;
	}
	else if (attack == 1) {
		cout << "You were shot with 3 lbs of glitter." << endl;
	}
	else if (attack == 2) {
		cout << "You were force fed old brussel sprouts." << endl;
	}
	else if (attack == 4) {
		cout << "You were forced to step on a lego." << endl;
	}
	else if (attack == 5) {
		cout << "You were attacked by a small pink poodle." << endl;
	}
	else if (attack == 6) {
		cout << "You were forced to sleep with your hand in warm water." << endl;
	}
	SetColor(7);
}

// This function displays the multiple choice as well as "grades" the user based on their response
int playerStats::displayAnswer(int level) {
	switch (level) {
	case 1:
		/*Put Question answers here*/
		cout << "A.) Yes, of course." << endl;
		cout << "B.) No that's a lie." << endl;
		cout << "Enter your answer:" << endl;
		cin >> playerAnswer;
		if (playerAnswer == 'b' || playerAnswer == 'B') {
			level++;
			cout << "That seems understandable.... moving on. " << endl;
		}
		else {
			health -= 10;

			cout << "That's not what I wanted to hear! " << endl;
			randomAttack();
			cout << "Try again... " << endl << endl;
		}

		break;

	case 2:
		/*Put Question answers here*/
		cout << "A.) Yes, if you believe hard enough." << endl;
		cout << "B.) No, that's a myth" << endl;
		cout << "Enter your answer:" << endl;
		cin >> playerAnswer;
		if (playerAnswer == 'A' || playerAnswer == 'a') {
			level++;
			cout << "That seems understandable.... moving on. " << endl;
		}
		else {
			health -= 10;
			cout << "That's not what I wanted to hear!" << endl;
			randomAttack();
			cout << "Try again... " << endl << endl;
		}

		break;
	case 3:
		/*Put Question answers here*/
		cout << "A.) I think you might be schizophrenic" << endl;
		cout << "B.) It's your conscious!" << endl;
		cout << "C.) You must have imaginary friends." << endl;
		cout << "Enter your answer:" << endl;
		cin >> playerAnswer;
		if (playerAnswer == 'a' || playerAnswer == 'A') {
			level++;
			cout << "That seems understandable.... moving on. " << endl;
		}
		else {
			health -= 10;
			cout << "That's not what I wanted to hear!" << endl;
			randomAttack();
			cout << "Try again... " << endl << endl;
		}
		break;
	case 4:
		/*Put Question answers here*/
		cout << "A.) Tuna" << endl;
		cout << "B.) Pork" << endl;
		cout << "C.) I'm sorry... what? " << endl;
		cout << "Enter your answer:" << endl;
		cin >> playerAnswer;
		if (playerAnswer == 'b' || playerAnswer == 'B') {
			level++;
			cout << "That seems understandable.... moving on. " << endl;
		}
		else {
			health -= 10;
			cout << "That's not what I wanted to hear!" << endl;
			randomAttack();
			cout << "Try again... " << endl << endl;
		}
		break;
	case 5:
		/*Put Question answers here*/
		cout << "A.) They come back as zombies." << endl;
		cout << "B.) They stick around as ghosts and haunt you" << endl;
		cout << "C.) Nothing, there is no afterlife." << endl;
		cout << "D.) They go to heaven or hell." << endl;
		cout << "Enter your answer:" << endl;
		cin >> playerAnswer;
		if (playerAnswer == 'd' || playerAnswer == 'D') {
			level++;
			cout << "That seems understandable.... moving on. " << endl;
		}
		else {
			health -= 10;
			cout << "That's not what I wanted to hear!" << endl;
			randomAttack();
			cout << "Try again... " << endl << endl;
		}
		break;
	case 6:
		/*Put Question answers here*/
		cout << "A.) 90 degrees" << endl;
		cout << "B.) 70 degrees" << endl;
		cout << "C.) 120 degrees" << endl;
		cout << "D.) 200 degrees" << endl;
		cout << "Enter your answer:" << endl;
		cin >> playerAnswer;
		if (playerAnswer == 'c' || playerAnswer == 'C') {
			level++;
			cout << "That seems understandable.... moving on. " << endl;
		}
		else {
			health -= 10;
			cout << "That's not what I wanted to hear!" << endl;
			randomAttack();
			cout << "Try again... " << endl << endl;
		}
		break;
	case 7:
		/*Put Question answers here*/
		cout << "A.) 7 days" << endl;
		cout << "B.) 3 days" << endl;
		cout << "C.) 14 days" << endl;
		cout << "D.) 2 months" << endl;
		cout << "E.) You don't need to eat to survive." << endl;
		cout << "Enter your answer:" << endl;
		cin >> playerAnswer;
		if (playerAnswer == 'd' || playerAnswer == 'D') {
			level++;
			cout << "That seems understandable.... moving on. " << endl;
		}
		else {
			health -= 10;
			cout << "That's not what I wanted to hear!" << endl;
			randomAttack();
			cout << "Try again... " << endl << endl;
		}
		break;
	case 8:
		/*Put Question answers here*/
		cout << "A.) 4 people" << endl;
		cout << "B.) 1 person" << endl;
		cout << "C.) You shouldn't think to kill someone.." << endl;
		cout << "D.) Have you killed someone?" << endl;
		cout << "E.) 100 Souls must be sacrificed." << endl;
		cout << "Enter your answer:" << endl;
		cin >> playerAnswer;
		if (playerAnswer == 'C' || playerAnswer == 'c') {
			level++;
			cout << "That seems understandable.... moving on. \n\n " << endl << endl;
		}
		else {
			health -= 10;
			cout << "\n\nThat's not what I wanted to hear!" << endl;
			randomAttack();
			cout << "Try again... " << endl << endl;
		}
		break;
	}
	return level;
}


// This function displays the questions drawn from files.
void playerStats::displayStory() {
	while (health != 0 && level != 8) {
		cout << "Your health is : ";;
		SetColor(2);
		cout << health << endl;
		SetColor(7);
		if (level == 1) {
			ifstream fin("StoryLevel1.txt");
			string line;

			fin >> line;
			getline(fin, line);
			cout << line << endl;
			fin.close();
			level = displayAnswer(level);

		}
		else if (level == 2) {
			ifstream fin("StoryLevel2.txt");
			string line;

			fin >> line;
			getline(fin, line);
			cout << line << endl;
			fin.close();
			level = displayAnswer(level);
		}
		else if (level == 3) {
			ifstream fin("StoryLevel3.txt");
			string line;

			fin >> line;
			getline(fin, line);
			cout << line << endl;
			fin.close();
			level = displayAnswer(level);
		}
		else if (level == 4) {
			ifstream fin("StoryLevel4.txt");
			string line;

			fin >> line;
			getline(fin, line);
			cout << line << endl;
			fin.close();
			level = displayAnswer(level);
		}
		else if (level == 5) {
			ifstream fin("StoryLevel5.txt");
			string line;

			fin >> line;
			getline(fin, line);
			cout << line << endl;
			fin.close();
			level = displayAnswer(level);
		}
		else if (level == 6) {
			ifstream fin("StoryLevel6.txt");
			string line;

			fin >> line;
			getline(fin, line);
			cout << line << endl;
			fin.close();
			level = displayAnswer(level);
		}
		else if (level == 7) {
			ifstream fin("StoryLevel7.txt");
			string line;

			fin >> line;
			getline(fin, line);
			cout << line << endl;
			fin.close();
			level = displayAnswer(level);
		}
		else if (level == 8) {
			ifstream fin("StoryLevel8.txt");
			string line;

			fin >> line;
			getline(fin, line);
			cout << line << endl;
			fin.close();
			level = displayAnswer(level);
		}

	}

	//If the player loses their health before level 8, they are in game over.
	if (health == 0 && level < 8) {
		cout << "You didn't answer the way I wanted you to! Feed them to the gators!" << endl;
	}
	// If they reach level 8, they win and move on.
	if (level == 8) {
		cout << "You've answered correctly... I guess you aren't dumb after all. Go on, before I change my mind. " << endl;
	}
}

int main() {
	playerStats p;

	p.displayStory();
}
