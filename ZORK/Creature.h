#ifndef __Creature__
#define __Creature__

#include "Entity.h"
#include "Room.h"

class Creature : public Entity
{
public:
	// Constructor
	Creature(const char* name, const char* description, Room* room);

	// Methods
	Room* GetRoom() const;
};

#endif //__Creature__