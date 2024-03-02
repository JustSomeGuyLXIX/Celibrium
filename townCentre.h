#ifndef townCentre_h
#define townCentre_h

#include <iostream>
#include <string>
#include "intro.h"
#include "isWordPresent.h"
#include "charClass.h"
#include "areaClass.h"
#include "townEvents.h"
#include "forest.h"
using namespace std;
extern Town centre;
extern mainChara player;
extern Guild adven;
string typed;

void guild()
{
    cout << "\n[Celibrium, The Adventurers Guild]" << endl;
    adven.display();
    while (true)
    {
        cout << "\nWhat do you want to do?" << endl;
        getline(cin, typed);

        if (findWords(typed, {"south", "exit", "leave"})) 
        { 
            cout << "\n[Celibrium town centre]" << endl; 
            centre.display();
            return; 
        }
        if (findWords(typed, { "bag","inventory","pocket" })) { player.open(); }

        if (findWords(typed, {"receptionist", "bennett"})) 
        { 
            if (adven.gift == true and player.findItem("collar") == true) { guildCollar(); }
            else { receptEvnt(); }
        }
        if (findWords(typed, {"lady","woman","bags","charlotte"})) { bagloverEvnt(); }

    }
}

void townCentre(bool IntroComp)
{/*checks if you've seen the intro, so it doesn't replay every time you go to town */
    if (IntroComp == false) { IntroComp = Intro(); }
        /* ensures that when the intro/tutorial is finished, it moves to the next if statement*/
    if (IntroComp == true)
    {
        cout << "\n[Celibrium town centre]" << endl;
        centre.display();
        while (true)
        {
            cout << "\nWhat do you want to do?" << endl;
            getline(cin, typed);

            if (findWords(typed, {"bag","inventory","pocket"})) { player.open(); }

            if (findWords(typed, {"floor","ground"}))
            {
                if (centre.lostKey == true or player.findItem("lost key") == true) {}
                else{
                    cout << "You check the floor and find a lost key.\nYou pick it up" << endl;
                    player.addItem("lost key");
                    }
            }
            if (findWords(typed, {"man","help"})) { lostKeyEvnt(); }

            if (findWords(typed, {"blacksmith", "smith", "south"})) { blcksmthEvnt(); }

            if (findWords(typed, {"guild","west"})) { guild(); }

            if (findWords(typed, { "shop","north" })) { shop(); }

            if (isWordPresent(typed, "tavern")) { cout << "You don't think it's a good idea to go there" << endl; }

            if (findWords(typed, { "gate","east" }))
            {
                cout << "You leave the town." << endl;
                sylvaForest();
            }
        }
    }
}

#endif