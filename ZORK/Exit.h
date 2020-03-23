#ifndef __Connection__
#define __Connection__

#include <string>
#include "Entity.h"

class Room;

class Exit : public Entity
{
public:
	Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination);

	const string& GetDirectionName(Room* room);
	Room* GetDestinationName(const Room* room) const;

	string name;
	string opposite_name;
	Room* destination;
};

#endif __Connection__