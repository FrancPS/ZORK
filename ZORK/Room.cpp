#include <iostream>

#include "Global.h"
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Creature.h"


// ---- CONSTRUCTOR ----
Room::Room(const char* title, const char* description) :
Entity(title, description, NULL)
{
}

// ---- LOOK ----
/* Prints to console the description of this Room, aswell as every Item, Creature
	and Exits that are in this room.

	Parameters:
		- NONE
	Return:
		- NONE
*/
void Room::Look() const
{
	// Print the info of the room
	cout << name << endl;
	cout << description << endl;

	// Print the info of the Exits in the room
	for (list<Exit*>::const_iterator iter = exitWays.begin(); iter != exitWays.cend(); ++iter)
	{
		Exit* ex = *iter;
		cout << "Direction " << ex->GetDirectionName(this) << " you see " << ex->description << " that leads to " << ex->GetDestination(this)->name << endl;
	}
	// Print the info of the Items in the room
	for (list<Item*>::const_iterator iter = itemsIn.begin(); iter != itemsIn.cend(); ++iter)
	{
		Item* it = *iter;
		cout << "There is an item here: " << it->name << endl;
	}
	// Print the info of the other Creatures in the room
	for (list<Creature*>::const_iterator iter = creaturesIn.begin(); iter != creaturesIn.cend(); ++iter)
	{
		Creature* cr = *iter;
		cout << "There is someone else here: " << cr->name;
		if (cr->IsAlive() == false)
			cout << " (dead)";
		cout << endl;
	}
}

// ---- GET EXIT ----
/* Gets the Exit object in a direction given, if exists. Otherwise returns NULL

	Parameters:
		- String
	Return:
		- Exit Object
*/
Exit* Room::GetExit(const string& direction) const {
	// Check every exit in the room
	for (list<Exit*>::const_iterator iter = exitWays.begin(); iter != exitWays.cend(); ++iter)
	{
		Exit* ex = *iter;
		// Return the exit if the direction matches
		if (Same(ex->GetDirectionName(this), direction))
			return ex;
	}
	return NULL;
}