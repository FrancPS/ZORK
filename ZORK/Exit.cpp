#include "Exit.h"
#include "Entity.h"
#include "Room.h"


// Constructor
Exit::Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination) :
Entity(name, description, origin),
destination(destination), opposite_name(opposite_name), name(name)
{
	origin->exitWays.push_back(this);
	destination->exitWays.push_back(this);
	
}

// ---- GET DIRECTION NAME ---
/* From the Room where you are, returns the name of the direction
	the player must take to "use" this exit.
	If the Room is the parent room of this Exit, you must go "name"
	If the Room is the other side of this Exit, you must go "opposite_name"

	Parameters:
		- Room Object
	Return:
		- String
*/
const string& Exit::GetDirectionName (Room* room)
{
	if (room == parent)
		return name;
	if (room == destination)
		return opposite_name;

	return name; // error ?
}

// ---- GET DESTINATION NAME ---
/* Similarly to GetDirectionName(), returns the Room at the other side
	of this exit, depending on which side of it you are

	Parameters:
		- Room Object
	Return:
		- Room Object
*/
Room* Exit::GetDestinationName(const Room* room) const
{
	if (room == parent)
		return destination;
	if (room == destination)
		return (Room*)parent;

	return NULL;
}

