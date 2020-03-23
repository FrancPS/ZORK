#include <iostream>

#include "Item.h"
#include "Entity.h"
#include "Room.h"


// ---- Constructor ----
Item::Item(const char* name, const char* description, Room* parent) :
Entity(name, description, (Entity*)parent)
{
	parent->itemsIn.push_back(this);
}

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