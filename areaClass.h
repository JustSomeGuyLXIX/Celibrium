//this is where classes, related to areas, are stored
#ifndef areaClass_h
#define areaClass_h

#include <iostream>
#include <string>
using namespace std;

class Area
{
protected:
	string desc;
	// ensures that the description can be updated, and reflects the players actions

public:
	bool nextArea;
	// ensures that players can't instantly go to the next area

	void update(string text) { desc = text; }

	void display() { cout << desc << endl; }

	Area(string DESC) //constructor
	{
		desc = DESC;
		nextArea = false;
	}
};

class Town : public Area
{
public:
	bool lostKey; 
	bool blksmthStr;
	bool blksmthEnd; 
	bool wolf;
	//ensure that certain events can't happen after certain condition is met.
	Town(string DESC) : Area(DESC) //constructor
	{
		lostKey = false;
		blksmthStr = false;
		blksmthEnd = false;
		wolf = false;
	}
};

class Guild : public Area
{
public:
	bool gift;
	bool baglover;
	//ensure that certain events can't happen after certain condition is met.
	Guild(string DESC) : Area(DESC) //constructor
	{
		gift = false;
		baglover = false;
	}
};

class Sylva : public Area
{
public:
	bool Fenrir;
	//ensure that certain events can't happen after certain condition is met.
	Sylva(string DESC) : Area(DESC) //constructor
	{
		Fenrir = false;
	}
};

class Circus : public Area
{
public:
	bool dogFood;
	bool clown;
	//ensure that certain events can't happen after certain condition is met.
	Circus(string DESC) : Area(DESC) //constructor
	{
		dogFood = false;
		clown = false;
	}
};

class Forbidden : public Area
{
public:
	bool clownNose;
	bool ancientWood;
	//ensure that certain events can't happen after certain condition is met.
	Forbidden(string DESC) : Area(DESC) //constructor
	{
		clownNose = false;
		ancientWood = false;
	}
};

#endif