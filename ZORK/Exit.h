#ifndef __Connection__
#define __Connection__

#include <string>
#include "Entity.h"

class Room;

class Connection : public Entity
{
public:
	Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination, bool one_way = false);

};

#endif __Connection__