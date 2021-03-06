#ifndef __Item__
#define __Item__

#include "Entity.h"

class Room;

enum ItemType
{
	COMMON,
	WEAPON,
	ARMOUR,
	SHIELD,
	HP_POTION
};

class Item : public Entity
{
public:
	// Constructor
	Item(const char* name, const char* description, Entity* parent, ItemType item_type = COMMON, int itemSize = 1, bool isContainer = false, int combatVal = 0);

	// Methods
	void Look() const override;

	// Object Attr
	const ItemType item_type;
	int itemSize;
	bool isContainer;
	int combatVal;
};

#endif //__Item__
