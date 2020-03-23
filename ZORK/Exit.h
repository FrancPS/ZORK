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
	const string& GetDirectionName(Room* room);
	Room* GetDestinationName(const Room* room) const;

	// Object Attr
	string name;
	string opposite_name;
	Room* destination;
};

#endif __Connection__