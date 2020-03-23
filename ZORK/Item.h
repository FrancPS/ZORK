#ifndef __Item__
#define __Item__

#include "Entity.h"

class Room;

class Item : public Entity
{
public:
	// Constructor
	Item(const char* name, const char* description, Room* parent);

	// Methods
	void Look() const;
};

#endif //__Item__
