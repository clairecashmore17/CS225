// Example of how the storyline could work.


#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <istream>
#include <ostream>
#include <fstream>


using namespace std;

class playerStats {
private:
	int health = 100;
	int level = 0;

public:
	int levelUp() { level++; };
	int damage() { health = health - 10; }
	void displayQuestion(int x);
	void displayStory();
};

void playerStats::displayQuestion(int level) {
	switch (level) {
		case 1:
		/*Put Question answers here*/

			break;

		case 2:
		/*Put Question answers here*/

			break;
		case 3:
			/*Put Question answers here*/

			break;
		case 4:
			/*Put Question answers here*/

			break;
		case 5:
			/*Put Question answers here*/

			break;
		case 6:
			/*Put Question answers here*/

			break;
		case 7:
			/*Put Question answers here*/

			break;
		case 8:
			/*Put Question answers here*/

			break;
	}
}




void playerStats::displayStory() {
	while (health != 0 && level != 8) {
		if (level == 0) {
			ifstream fin("StoryLevel1.txt");
			string line;

			fin >> line;
			getline(fin, line);
			cout << line << endl;
			fin.close();

		}
		else if (level == 1) {

		}
		else if (level == 2) {

		}
		else if (level == 3) {

		}
		else {

		}
		displayQuestion(level);
	}
	if (health == 0 && level < 8) {
		cout << "You didn't answer the way I wanted you to! Feed them to the gators!" << endl;
	}
	if (level == 8) {
		cout << "You've answered correctly... I guess you aren't dumb after all. Go on, before I change my mind. " << endl;
	}
}

int main() {
	playerStats p;
	
	p.displayStory();
}
