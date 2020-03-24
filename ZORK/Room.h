#ifndef __Room__
#define __Room__

#include <list>

#include "Entity.h"
#include "Item.h"

class Exit;

class Room : public Entity
{
	public:
		// Constructor
		Room(const char* name, const char* description);

		// Methods
		void Look() const;
		Exit* GetExit(const string& direction) const;

		// Object Attr
		list<Exit*> exitWays;
		list<Item*> itemsIn;
};

#endif //__Room__