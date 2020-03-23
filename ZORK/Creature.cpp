#include "Creature.h"
#include "Room.h"



// ---- Constructor ----
Creature::Creature(const char* title, const char* description, Room* room) :
Entity(title, description, (Entity*)room) 
{
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


