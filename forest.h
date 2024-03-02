#ifndef forest_h
#define forest_h

#include <iostream>
#include <string>
#include "isWordPresent.h"
#include "charClass.h"
#include "areaClass.h"
#include "townCentre.h"
#include "forestEvents.h"

using namespace std;
extern string typed;
extern mainChara player;
extern Sylva forest;
extern Town centre;
extern Circus Mcgees;
extern Forbidden forbArea;

void circusLocal()
{
	cout << "\n[Sylva forest, Old McGees Circus]" << endl;
	Mcgees.display();
	if (player.findItem("circus ticket") == false)
	{
		cout << "You approuch the ticket master, who tells you to come back when you have a ticket.\nYou leave the circus." << endl;
	}
	else { fenrirCircutEvnt(); }
	cout << "\n[Sylva forest]" << endl;
	forest.display();
}

void forbiddenArea()
{ 
	forbArea.display();
	while (true)
	{
		cout << "\nYou think about your next move as you don't want to get caught." << endl;
		cout << "What do you want to do?" << endl;
		getline(cin, typed);

		if (findWords(typed, { "west", "leave", "exit"}))
		{// i think it sometimes returns to town function, tho i could be bad at reading.
			cout << "You quickly leave the area." << endl;
			forest.display();
			return;
		}
		if (findWords(typed, { "bag","inventory","pocket" })) { player.open(); }
		if (forbArea.clownNose == false and Mcgees.clown == true) { if (findWords(typed, { "search", "ground", "clown", "nose" })) { clownNoseEvnt(); } }
		if (findWords(typed, { "ancient", "wood" }))
		{
			if (forbArea.ancientWood == true) {}
			else {
				cout << "You search around and find a big broken branch from one of the trees.\nYou grab the branch and put it in your bag pocket." << endl;
				player.collect("Ancient wood");
				forbArea.ancientWood = true;
			}
		}
	}
}

void sylvaForest()
{
	cout << "\n[Sylva forest]" << endl;
	forest.display();

	while (true)
	{
		string cheat;
		cout << "\nWhat do you want to do?" << endl;
		getline(cin, typed);

		if (findWords(typed, { "bag","inventory","pocket" })) { player.open(); }

		if (findWords(typed, { "wolf", "fenrir", "north", "mountain", "mountains" })) 
		{
			if (forest.Fenrir == true)
			{ //if event is complete, you can go to the next area
				cout << "You leave the forest." << endl;
				//tain.start();
			}
			else {
				fenrirEvnt();
			}
		}
		
		if (isWordPresent(typed, "asdfg"))  
		{ //give yourself an item to test things by skipping parts of the game that dont you dont need to test
			getline(cin, cheat);
			player.addItem(cheat);
		}
		if (isWordPresent(typed, "qwert"))
		{ //give yourself an item to test things by skipping parts of the game that dont you dont need to test
			getline(cin, cheat);
			player.collect(cheat);
		}

		if (findWords(typed, { "circus","south" })) { circusLocal(); }
		if (findWords(typed, { "forbidden","east" })) { forbiddenArea(); }

		if (findWords(typed, { "town", "west" })) 
		{
			cout << "You leave the forest" << endl; 
			cout << "\n[Celibrium town centre]" << endl;
			centre.display();
			return;
		}
	}
}

#endif