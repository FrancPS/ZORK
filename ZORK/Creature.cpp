#include "Creature.h"
#include "Room.h"



// ---- Constructor ----
Creature::Creature(const char* title, const char* description, Room* room) :
Entity(title, description, (Entity*)room) 
{

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


