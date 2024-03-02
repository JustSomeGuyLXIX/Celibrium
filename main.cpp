#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "townCentre.h"
#include <string>
using namespace std;
Town centre = Town("You're in the capital city of the country it shares a name with.\nMany people are going about their daily lives, including a well-known blacksmith who is south from where you're standing.\nHowever one man stands out, as he is clearly looking desperately for something on the ground.\nYou also notice that to the west, by the tavern, is The Adventurers Guild, and the north contains a shop.");
mainChara player("temp",30,10);
Guild adven = Guild("Upon entering The Adventurers Guild, you notice that there are many people collecting bounty rewards, preparing for quests, or just talking to their fellow colleagues.\nTwo things catch your attention however. The receptionist, who you think you might be a good idea, and the lady surrounded by many, many bags.\nThe door to leave is to the south.");
Sylva forest = Sylva("You're in Sylva forest, also known as Forest sylva, Sylva sylva, and Forest forest.");
Circus Mcgees = Circus("You enter Old Mcgees Circus.");
Forbidden forbArea = Forbidden("You entered the forbidden section of the forest");

int main()
{
    string name;
    //moved name here so it isnt a global variable, as it doesn't need to be one
    cout << "WELCOME TO..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "celibrium" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    
    cout << "\nWhat is your name, Adventurer?\n" << flush;
    getline(cin, name);
    player.plyrName(name);
    if (name == "Paswurd")
    {
        townCentre(true);
    }
    else
    {
        townCentre(false);
    }

    return 0;
}