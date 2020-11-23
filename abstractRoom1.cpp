#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class abstractRoom {
private:
	string room;
public:
	virtual void displayIntro() = 0;
};
