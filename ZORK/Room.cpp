#include <iostream>

#include "Global.h"
#include "Entity.h"
#include "Room.h"
#include "Exit.h"


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
void Room::Look() {
	// Print the info of the room
	cout << name << endl;
	cout << description << endl;

	// Print the info of the exits in the room
	for (list<Exit*>::const_iterator iter = exitWays.begin(); iter != exitWays.cend(); ++iter)
	{
		Exit* ex = *iter;
		cout << "Direction " << ex->GetDirectionName(this) << " you see " << ex->description << " that leads to " << ex->GetDestinationName(this)->name << endl;
	}
}

// ---- GET EXIT ----
/* Gets the Exit object in a direction given, if exists. Otherwise returns NULL

	Parameters:
		- String
	Return:
		- Exit Object
*/
Exit* Room::GetExit(const string& direction) {
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