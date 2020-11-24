#include "storyLine.h"

using namespace std;
using namespace std::chrono;

storyLine::storyLine() {
	playerStartTime = system_clock::now();
	cout << "Please enter your name: ";
	getline(cin, playerName);
	interlude("blue");
	techGuy.blueRoomRunThrough();
	interlude("pink");
	pinkGirl.displayStory();
	interlude("green");
	dinoGuy.rpsGame();
	interlude("final");
	finalGuy.runGame();
	interlude("outro");
	playerEndTime = system_clock::now();
	playerDuration = duration_cast<seconds>(playerEndTime - playerStartTime);
	cout << "it took you " << playerDuration.count() << " minutes to complete\n";
}

void storyLine::interlude(string room) {
	if (room == "blue") {
		cout << "You wake up in a strange blue room. Everything around you seems to radiate the color of blue. There was a fair amount of technology placed in out of reach corners of the room. Upon closer inspection, you recognize the small red light to be that of a recording camera. The lens adjusts as you approach it, alerting you that whoever was behind the screen must have been watching closely. A voice soon echoed throughout the room over a speaker system." << endl;
		cout << "“Geez… I was wonderin when you was gonna wake up.I’m sure you don’t know who this voice is, but you will.Meand my buddies have had enough of you adults telling us what to do… now it’s your turn to listen to us!We have set up challenges for you to do in every room.For your sake… I hope you get through.For mine, I hope you don’t!”" << endl;
		cout << "After a quick raspberry into the mic, a new voice approached the intercom." << endl;
		cout << "“Hello.This is my room.My favorite color is blue..I really like blue.Anyways, you old people are always trying to tell me I need to remember to make my bed, clean my room, eat my veggies!Let’s see how you like having to remember so much!” " << endl;
	}
	else if (room == "pink") {
		cout << "After passing the memorization game, a door opened up across the room to a new area. As you walked through the passage, the room jumped from a deep blue to a brilliant pink. Stuffed animals were strewn across the room. A small tea cup set sat in the center of the room with a small sign reading “Sit Hear!”. The misspelling made you scoff as you took a seat. A large monitor at the end of the room sprung to life, revealing a young girl with a white cat in her lap sitting in front of a fireplace." << endl;
		cout << "“I have been especting you.” Based off her lisp, you guessed she must have recently lost her two front teeth. “Now ith thime for you to answer some very importhant questions I have. Old people are always tellin me I should stop asking so many questions… but now you have to help me! You better ansther correcthly though!”" << endl;
	}
	else if (room == "green") {
		cout << "You stumble into the next open door. How long have you been stuck in these rooms? You look around and realize the next theme of the room was green. Dinosaurs and prehistoric plants were plastered all over the walls. To your right you see a human-scaled dinosaur with a red light peering from it’s right eye. It’s jaw dropped to reveal a small speaker." << endl;
		cout << "“Gah, it took you forever to reach my room! I felt like I was going to be sitting here forever! Old people like you are always trying to take away my dinosaur toys in public. Well now I’m going to be fighting you for it. Let’s see how good you can guess my next move!”" << endl;

	}
	else if (room == "final") {
		cout << "You drag yourself into the final room. There was no color, just a large cement arena with hockey sticks spread around the room. In the center stood a small figure, skates on his feet and a hockey stick in his hands." << endl;
		cout << "“I see you’ve made it through my friend’s rooms.Well I wont be as easy to take down.My mom always tells me not to hit people with my hockey stick… but I am tired of being told what to do.I hope you’re quick, or this will be over fast.”" << endl;
	}
	else if (room == "outro") {
		cout << "The kid lay on the floor, defeated and out of breath. You walk over to him and pull the tag out of his shirt. " << endl;
		cout << "“James. If found, please call 943-222-3343.”" << endl;
		cout << "You scoff and look James in the eye." << endl;
		cout << "“James… I’m calling your parents.”" << endl;
		cout << "Fear shot through James’s eyes at the final blow before letting out a long defeated battle cry. You walk out the final door, excited for your freedom." << endl;
	}
	else {
		throw("Something errored in the interlude");
	}
}

int main() {
	storyLine player;
}
