#ifndef __Connection__
#define __Connection__

#include <string>

#include "Entity.h"
#include "Room.h"

class Exit : public Entity
{
public:
	// Constructor
	Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination);

	//Methods
	const char* GetDirectionName(const Room* room) const;
	Room* GetDestination(const Room* room) const;

	// Object Attr
	const char* opposite_name;
	Room* destination;
};

#endif __Connection__