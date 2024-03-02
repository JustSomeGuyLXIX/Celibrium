#ifndef forestEvents_h
#define forestEWvents_h

#include <iostream>
#include <string>
#include "charClass.h"
#include "areaClass.h"
using namespace std;
extern mainChara player;
extern Sylva forest;
extern string typed;
extern Circus Mcgees;
extern Forbidden forbArea;

void fenrirEvnt()
{
	if (player.findItem("dog food") == true)
	{ //if you're completing the event
		cout << "You approach Fenrir with the food in hand, you slowly place the food on the ground and move back" << endl;
		cout << "Fenrir cautiously moves towards the food, then after taking a small bite, stats eating faster than anything you've seen before" << endl;
		cout << "After a while, Bennett shows up with other guild staff, and they took care of the situation\n\"We'll find someone to take care of Fenrir, don't worry\" said Bennett somberly \"Just so you know, the Dragon King's lair is hidden in a cave on top of the mountain that's in this direction.\nGood luck on your journey, I hope I see you again.\"\n" << endl;
		cout << "After everyone left, you decided to stay in the forest to make sure that you got everything you wanted to do done, before moving onto the mountains." << endl;
		player.removeItem("dog food");
		forest.Fenrir = true;
		return;
	}
	if (player.findItem("collar") == true)
	{ //if you try to interact before event is complete, but after its started
		cout << "The wolf looks just as hungary as before, maybe someone can identify the adventurer using the collar you grabbed" << endl;
		return;
	}
	if (player.findItem("circus ticket") == true)
	{//if you try to interact before event is complete, but after its started
		cout << "The wolf looks hungrier than it did before, maybe the nearby circus has some food" << endl;
		return;
	}
	else
	{// you start the event
		cout << "You head towards the mountains, but then you hear a growl.\nYou see a hungry looking wolf next to the bodies of what look like bandits and an adventurer. The wolf will attack you if you go any closer." << endl;
		cout << "Looking around, you spot something on the ground. It's a collar with the name Fenrir on it. Maybe the wolf was the adventurers friend?\nYou put the collar in your bag." << endl;
		player.addItem("collar");
		return;
	}
}

void fenrirCircutEvnt()
{
	if (Mcgees.dogFood == false)
	{
		if (player.findItem("clown nose") == true)
		{
			cout << "You return to the clown and hand him the nose. He handed you the food.\nYou leave the circus." << endl;
			player.removeItem("clown nose");
			player.addItem("dog food");
			Mcgees.dogFood = true;
			return;
		}
		if (Mcgees.clown == true) { cout << "There's no reason to be here now" << endl; return; }
		else
		{
			cout << "You approuch the ticket master and hand him your ticket. \nYou look for someone who might be able to help, and find the Circus' clown." << endl;
			cout << "You explain the situation to him.\nHe tells you that he can help, however you'll need to do something for him first." << endl;
			cout << "\"Go into the forbidden area\" He tells you \"There happens to be a clown nose on the ground somewhere, don't ask why, OKAY!\"" << endl;
			cout << "You're hesitant, but there's nothing else you can do so you agree to it and leave." << endl;
			Mcgees.clown = true;
			return;
		}
	}
	else { cout << "There's no reason to be here now" << endl; return; }
}

void clownNoseEvnt()
{
	cout << "You go into the Forbidden area and look at the ground and find the clown nose." << endl;
	player.addItem("clown nose");
	forbArea.clownNose = true;
	return;
}
#endif