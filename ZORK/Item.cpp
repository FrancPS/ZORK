#include <iostream>

#include "Item.h"
#include "Entity.h"
#include "Room.h"


// ---- Constructor ----
Item::Item(const char* name, const char* description, Room* parent, ItemType item_type) :
Entity(name, description, (Entity*)parent), item_type(item_type)
{
	parent->itemsIn.push_back(this);
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

	/*list<Entity*> stuff;
	FindAll(ITEM, stuff);

	if (stuff.size() > 0)
	{
		cout << "It contains: " << "\n";
		for (list<Entity*>::const_iterator it = stuff.begin(); it != stuff.cend(); ++it)
			cout << (*it)->name << "\n";
	}*/
}