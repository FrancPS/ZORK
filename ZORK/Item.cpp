#include <iostream>

#include "Item.h"
#include "Entity.h"
#include "Room.h"


// ---- Constructor ----
Item::Item(const char* name, const char* description, Entity* parent, ItemType item_type, int itemSize, bool isContainer, int combatVal) :
Entity(name, description, (Entity*)parent), 
item_type(item_type), itemSize(itemSize), isContainer(isContainer)
{
	if (dynamic_cast<Room*>(parent) != nullptr)
		GetRoom()->itemsIn.push_back(this);
}

// ---- LOOK ----
/* Prints to console the Name and Description of this Item

	Parameters:
		- NONE
	Return:
		- NONE
*/
void Item::Look() const
{
	cout << endl << name << endl;
	cout << description << endl;

	if (isContainer) {
		if (container.size() > 0)
		{
			cout << "It contains: " << endl;
			for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
				cout << (*it)->name << endl;
		}
		else
			cout << "It contains nothing." << endl;
	}
}

