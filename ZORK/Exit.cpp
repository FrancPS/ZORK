#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include <iostream>
using namespace std;

Exit::Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination) :
Entity(name, description, origin),
destination(destination), opposite_name(opposite_name), name(name)
{
	origin->exitWays.push_back(this);
	destination->exitWays.push_back(this);
	
}

// ----------------------------------------------------
const string& Exit::GetDirectionName (Room* room)
{
	if (room == parent)
		return name;
	if (room == destination)
		return opposite_name;

	return "ERROR"; // error ?
}

// ----------------------------------------------------
Room* Exit::GetDestinationName(const Room* room) const
{
	if (room == parent)
		return destination;
	if (room == destination)
		return (Room*)parent;

	return NULL;
}

