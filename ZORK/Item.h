#ifndef __Item__
#define __Item__

#include "Entity.h"

class Room;

enum ItemType
{
	COMMON,
	WEAPON,
	ARMOUR,
	SHIELD
};

class Item : public Entity
{
public:
	// Constructor
	Item(const char* name, const char* description, Room* parent, ItemType item_type = COMMON);

	// Methods
	void Look() const;

	// Object Attr
	ItemType item_type;
};

#endif //__Item__
