#ifndef __Creature__
#define __Creature__

#include "Entity.h"

class Room;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);

	Room* GetRoom() const;
};

#endif //__Creature__