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
	void displayStory();
};
void playerStats::displayStory() {
	
	if (level == 0) {
		ifstream fin("StoryLevel1.txt");
		string line;
		
		fin >> line;
		getline(fin, line);
		cout << line << endl;
		fin.close();

	}
	else if(level == 1) {
	
	}
	else if (level == 2) {
	
	}
	else if (level == 3) {
	
	}
	else {
	
	}
	
}

int main() {
	playerStats p;
	p.displayStory();
}
