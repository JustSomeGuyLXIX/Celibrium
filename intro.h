#ifndef intro_h
#define intro_h

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "isWordPresent.h"
using namespace std;
extern string typed;

bool Intro()
{
    cout << "\n[Celibrium castle, Throneroom]\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));

    cout << "SWOOOOOSH, SWOOOOOOSH, CRAAAAAAAAAAASH\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));

    cout << "\"I am the Dragon King, I house the strength of all the dragons in the world combined.\"" << endl <<
        "\"If you wish for me to not destroy the world, I require you to surrender all your treasure to me\"\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(10000));

    cout << "SWOOOOOSH, SWOOOOOOSH, SWOOOOOOSH\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "\"Your highness, what should we do?\"" << " asked a guard." << endl;
    this_thread::sleep_for(chrono::milliseconds(4500));
    cout << "\"The Dragon King is a serious threat, we've already sent many knights\"" << " replied the king" << endl <<
        "\"All we can do is set a bounty and hope for the best, or surrender to the Dragon King's demands.\"\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(10000));

    cout << "[Celibrium town centre, The Chilly Cavern Tavern]" << endl;
    this_thread::sleep_for(chrono::milliseconds(4000));
    cout << "Upon entering the tavern, you notice the bounty board." << endl <<
        "On it you see a bounty for 10000 gold, you decide to accept it..." << endl;
    this_thread::sleep_for(chrono::milliseconds(7000));
    cout << "after a drink of course.\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));

    cout << "1 hour later" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "You look around the tavern..." << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "There is a gentle, quiet atmosphere as it's still early in the morning, people currently aren't in the mood to talk to strangers" << endl <<
        "The door is on the west side of the tavern, with the bar on the north.\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(7000));

    while (true)
    {
        cout << "What do you want to do?" << endl;
        getline(cin, typed);

        if (isWordPresent(typed,"west"))
        {
            cout << "You leave.\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            return true;
        }

        if (findWords(typed, {"door","leave","exit"}))
        { //looks for multiple words
            cout << "You head towards the door, then..." << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            cout << "\"STOP\" " << "said the tavern owner." << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            cout << "\"You've been here a while, I can't risk letting drunks leave my tavern, cause if you cause trouble, I get in trouble for serving you." << endl;
            cout << "that's why, I won't let you leave, unless... " << endl;
            this_thread::sleep_for(chrono::milliseconds(7000));
            cout << "you can say the compass direction the door is in, if you do that, then I'll know that you're sober enough to leave.\"" << endl;

            while (true)
            {
                cout << "\nWhat do you say?" << endl;
                getline(cin, typed);
                if (isWordPresent(typed, "west"))
                { //lookos for 1 word
                    cout << "\"Y'know, if this were some sort of movement tutorial in some kind of game, I'd congratulate ya" << endl;
                    this_thread::sleep_for(chrono::milliseconds(4000));
                    cout << "But it's not, bye bye.\"" << endl;
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    cout << "You finally leave.\n" << endl;
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    return true;
                }
                else { cout << "\"What?\" " << "said the tavern owner." << endl; }
            }
        }
    }
}

#endif