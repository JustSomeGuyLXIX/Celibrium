// this is where the classes, related to characters, are stored
#ifndef charClass_h
#define charClass_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class inventory
{
protected:
	vector<string> bag;
	vector<string> pocket;
	string weapon;
	int balance;

public:
	bool canCheckPocket; //is true if you talked to baglover charlotte

	void addItem(string item) { bag.emplace_back(item); }

	void open()
	{	
		cout << "your currently equipped weapon is The " << weapon << " and you have " << balance << " coins" << endl;

		cout << "\nThe items in your bag include:" << endl;
		for (string i : bag)
		{
			cout << i << endl;
		}
		if (canCheckPocket == true)
		{
			cout << "\nIn a seperate pocket, you have:" << endl;
			for (string i : pocket)
			{
				cout << i << endl;
			}
		}

	}
	void removeItem(string item)
	{	
		int pos = 0; //used to locate position of elemnent
		for (string i : bag)
		{
			if (i == item)
			{
				bag.erase(bag.begin()+pos);
			}
			else {
				pos++;
			}
		}
	}
	bool findItem(string item)
	{
		for (string i : bag)
		{
			if (i == item)
			{
				return true;
			}
			else {}
		}
		return false;
	}

	void collect(string item) { pocket.emplace_back(item); }

	bool searchPket()
	{
		int count = 0;
		for (string i : pocket)
		{
			if (i == "Gold coin" or i == "Ancient wood" or i == "Fairy dust" or i == "Dragon bones") { count++; }
		}
		if (count == 4)
		{
			canCheckPocket = false;
			return true;
		}
		else {
			return false;
		}
	}
	void makeMoney(int money) { balance = balance + money; }
	bool buy(int cost, string product)
	{
		if (cost > balance) { cout << "Sorry, you can't afford it\n" << endl; return false; }
		else { cout << "You bought " << product << "\n" << endl; balance = balance - cost; return true; }
	}
};

class entity
{
protected:
	string name;
	int maxHP;
	int HP;
	int Att;

public:
	void showHP() { cout << HP << "/" << maxHP << endl; }

	bool reduceHP(int damage)
	{ // reduces HP, then checks if it's below zero, if yes return true
		HP = HP - damage;
		if (HP <= 0) { return true; }
		else { return false; }
	}
	void addHP(int health)
	{ //add helth to HP while making sure that it doesn't go over maxHP.
		HP = HP + health;
		if (HP > maxHP) { HP = maxHP; }
	}
	string showName() { return name; }

	entity(string NAME, int MAXHP, int ATT) //constructor
	{
		name = NAME;
		maxHP = MAXHP;
		HP = MAXHP;
		Att = ATT;
	}
};

class mainChara : public entity, public inventory
{
public:
	void plyrName(string input) { name = input; }

	void equip(string newWep)
	{ //if statements to automatically switch weapons if the new weapon is stronger, then update Att.
		if (newWep == "DracoEversor") { weapon = newWep; Att = 50; }
		if (newWep == "Sword")
		{
			int newAtt = 20;
			if (Att < newAtt)
			{
				weapon = newWep;
				Att = newAtt;
			}
		}
	}

	void armour(int MHP)
	{ 
		if (MHP > maxHP) { maxHP = MHP; }
	}

	mainChara(string NAME, int MAXHP, int ATT) : entity(NAME, MAXHP, ATT) { weapon = "broom"; canCheckPocket = false; balance = 100; }
};

#endif