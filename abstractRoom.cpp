#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class abstractRoom {
private:
	string room;
public:
	void displayIntro();
};
void abstractRoom::displayIntro() {
	cout << "Welcome to Juvenile Escape! Press Q to Play" << endl;
}
