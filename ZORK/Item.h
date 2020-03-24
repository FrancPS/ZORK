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
	Item(const char* name, const char* description, Room* parent, ItemType item_type = COMMON, int itemSize = 1, bool isContainer = false);

	// Methods
	void Look() const override;

	// Object Attr
	const ItemType item_type;
	int itemSize;
	bool isContainer;
};

#endif //__Item__
