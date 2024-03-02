#ifndef townEvents_h
#define townEvents_h

#include <iostream>
#include <string>
#include "charClass.h"
#include "areaClass.h"
using namespace std;
extern Town centre;
extern mainChara player;
extern Guild adven;
extern string typed;

void lostKeyEvnt()
{
    if (centre.lostKey == true) {}
    else {
        if (player.findItem("lost key") == true)
        {
            cout << "\"THANK YOU!\" exclaimed the man \"I can finally go home\"\nYou hand him the key" << endl;
            player.removeItem("lost key");
            centre.lostKey = true;
            centre.update("You're in the capital city of the country it shares a name with.\nMany people are going about their daily lives, including a well-known blacksmith who is south from where you're standing.\nYou also notice that to the west, by the tavern, is The Adventurers Guild, and the north contains a shop.");
            centre.display();
        }
        else {
            cout << "\"Excuse me?\" asked the man \"Have you seen a key somewhere on the ground?" <<
                " I seem to have lost it.\"" << endl;
            cout << "You tell the man that you haven't seen it\n\"Alright then, sorry to bother you\"" << endl;
        }
    }
}

void blcksmthEvnt()
{
    if (centre.blksmthEnd == true) { cout << "You can't think of anything to request." << endl; return; }
    else if (centre.blksmthStr == true)
    {
        if (player.searchPket() == true)
        {
            cout << "\"YA REALY DID IT\" exclaimed the blacksmith \"Give me a couple mins, could ya.\" \nAfter several minutes she comes back with the sword." << endl;
            cout << "\"AINT SHE A BEAUT, makes me wanna tear up\" She hands you the sword, you thank her then make your leave." << endl;
            player.equip("DracoEversor");
            centre.blksmthEnd = true;
            return;
        }
        else { cout << "\"Ya don't have all the materials, silly\"\nYou apologise and leave." << endl; return; }
    }
    else {
        cout << "\nYou approach the blacksmith\nYou tell her about the bounty and ask what equipment she'd recommend" << endl;
        cout << "\"I reckon' that you'd need the rumoured legendary weapon to stand a chance, if you excuse my bluntness\" she answers." << endl;
        cout << "You ask her what she's referring to" << endl;
        cout << "\"There's a book with instructions that has been passed down my family that claims that if you collect four specific rare items, then you can craft a very powerful weapon\" she continues" << endl;
        cout << "\"\nThose items are: \nGold, can be in any form as it'll be melted anyways,\nAncient wood from Sylva forest, don't cut down none of the trees tho, unless you wanna be executed," << endl;
        cout << "Fairy dust, most easily found up mountains,\nand Dragon bones, best bet is in or near the cave that the Dragon King lives in, as it could have some dead dragons near it." << endl;
        cout << "\nIf ya do find all the materials, I'll make the sword free o' charge, as blacksmithing is both a job and a hobbby to me.\"\nYou thank the blacksmith and leave." << endl;
        centre.blksmthStr = true;
        return;
    }
}

void receptEvnt()
{
    if (adven.gift == true) { cout << "You can't think of anything to say to him" << endl; }
    else 
    {
        cout << "\nYou walk over to the receptionist. \"Hello! my name is Bennett, what can I help you with!\" said the enthusiastic receptionist" << endl;
        cout << "You explain that it's your first time here." << endl;
        cout << "\"Thats ok, " << player.showName() << "!\" said bennet cheerfully \"at the guild, you can view commitions/bounties, talk to people and prepare for your adventure, it basically has everything you'd need regardless of if you're in a team or going solo!" << endl;
        cout << "\nBy the way, since it's your first time here, here's a gift from The Adventuring Guild!\" He hands you 3 potions and a gold coin (which replenishes 20HP) \"I hope these are useful to you!\"" << endl;
        cout << "You thank him, then go back to the entrance." << endl;
        player.addItem("potion");   player.addItem("potion");   player.addItem("potion");
        player.collect("Gold coin");
        adven.gift = true;

        if (adven.baglover == false) { adven.update("Upon entering The Adventurers Guild, you notice that there are many people collecting bounty rewards, preparing for quests, or just talking to their fellow colleagues.\nYou also notice the lady surrounded by many, many bags.\nThe door to leave is to your south.\nBennet is happy to see you alive."); }
        else { adven.update("Upon entering The Adventurers Guild, you notice that there are many people collecting bounty rewards, preparing for quests, or just talking to their fellow colleagues.\nYou also notice the Charlotte examining her massive collection of bags.\nThe door to leave is to your south.\nBennet is happy to see you alive."); }
    }
}

void bagloverEvnt()
{
    if (adven.baglover == true) { cout << "She's too distracted by bags to notice you" << endl; }
    else
    {
        cout << "\n\"WOOOW!!! IS THAT THE SUPER DUPER XTREME COOL SPECIAL BAG OF THE YEAR EDITION XFS124 BACKPACK!!!\" Are the words thrown in your directon. \" MAY I PLEASE HAVE A LOOK!!!\"" << endl;
        cout << "You sigh, then let the girl have a look, before asking for her name. \"THANK YOU SO MUCH I'M CHARLOTTE, CAN I ALSO SEE YOU OPEN YOUR BAG!!!" << endl;
        while (true)
        {
            cout << "What do you say?" << endl;
            getline(cin, typed);

            if (findWords(typed, { "bag","inventory","pocket" })) 
            { 
                player.open(); 
                cout << "\nAAAAAAAAAAAAAHHHHHHHHHH THAAAAAAAAANK YOOOOOOUUUUUUUUU, WHAT'S YOUR NAME...............THANK YOU, " << player.showName() << ". BY THE WAY, THE BAG HAS A POCKET THAT YOU CAN PUT IMPORTANT ITEMS INTO, IT'S VERY USEFULL!!!" << endl;
                adven.baglover = true;
                if (centre.blksmthEnd == false) { player.canCheckPocket = true; }
                else { cout << "\n(You already have the DracoEversor so the pocket wont appear)" << endl; }

                if (adven.gift == false) { adven.update("Upon entering The Adventurers Guild, you notice that there are many people collecting bounty rewards, preparing for quests, or just talking to their fellow colleagues.\nYou also notice the Charlotte examining her massive collection of bags.\nThe door to leave is to your south.\nTalking to the receptionist might be a good idea."); }
                else { adven.update("Upon entering The Adventurers Guild, you notice that there are many people collecting bounty rewards, preparing for quests, or just talking to their fellow colleagues.\nYou also notice the Charlotte examining her massive collection of bags.\nThe door to leave is to your south.\nBennet is happy to see you alive."); }
                return;
            }
        }
    }
}

void guildCollar()
{
    cout << "You realise that Bennett might know something about the wolf.\nYou head towards him, and explain the situation, and show him the collar, as you do this you notice that Bennett looks uoset, though he tries to hide it." << endl;
    cout << "\"I see\" Says Bennett sadly. \n\"Fenrir is Barry's pet wolf... or I guess was his pet wolf. The last tiem I saw Barry, he was preparing to complete a bounty to rid the forest of the local bandits. From what you told me, he must have been killed a couple days ago by those bandits, and now Fenrir is hungry and all on his own.\"" << endl;
    cout << "You ask Bennett if theres anything you can do to help. \nHe informs you of the circus in Sylva forest, and tells you that it would be usefull, if you asked for some food and fed it to Fenrir, while Bennett prepares everything to ensure that Fenrir and the situation are taken care of properly." << endl;
    cout << "Before you walk away, Bennett asks for the collar, then hands you a ticket so \"You don't have to pay to get to the circus\"." << endl;
    player.removeItem("collar");
    player.addItem("circus ticket");
    return;
}

void shop()
{
    cout << "You enter the shop, the items available for purchase are:" << endl;
    cout << "Sword -- 20 coins\nBasic armour -- 20 coins\nPotion -- 10 coins\n\nWill you buy something? or do you want to leave." << endl;
    while (true)
    {
        getline(cin, typed);
        if (findWords(typed,{"leave", "exit"})) { cout << "You leave the shop." << endl; return; }

        if (isWordPresent(typed, "potion")) 
        { 
            if (player.buy(10,"a potion") == true) { player.addItem("potion"); }
            else {}
        }

        if (isWordPresent(typed, "sword"))
        {
            if (player.buy(20, "the sword") == true) { player.equip("Sword"); }
            else {}
        }

        if (isWordPresent(typed, "armour"))
        {
            if (player.buy(20, "the basic armour") == true) { player.armour(50); }
            else {}
        }

        if (findWords(typed, { "bag","inventory","pocket" })) { player.open(); }
    }
}

#endif