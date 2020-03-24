#include <iostream>

#include "Creature.h"
#include "Room.h"



// ---- Constructor ----
Creature::Creature(const char* title, const char* description, Room* room) :
Entity(title, description, (Entity*)room) 
{
	if (title != "Xesk") {
		room->creaturesIn.push_back(this);
	}
	HP = maxHP = 1;
	mana = maxMana = 0;
	min_damage = max_damage = 1;
	min_protection = max_protection = 0;
	weapon = armour = shield = NULL;
}

// ---- GET ROOM ----
/* Get the Room where this object is located

	Parameters: 
		- NONE
	Return:
		- The Room Obj
*/
Room* Creature::GetRoom() const
{
	return (Room*)parent;
}

// ---- LOOK ----
/* Prints the description of the creature

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Creature::Look(const vector<string>& args) const
{
	if (IsAlive())
	{
		cout << name << endl;
		cout << description << endl;
	}
	else
	{
		cout << name << "'s corpse" << endl;
		cout << "Here lies dead: " << description << endl;
	}
}

// ---- IS ALIVE ----
/* Returns true if this creature is alive, false if not

	Parameters:
		- NONE
	Return:
		- Boolean
*/
bool Creature::IsAlive() const
{
	return HP > 0;
}
