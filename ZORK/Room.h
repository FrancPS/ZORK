#ifndef __Room__
#define __Room__

#include <list>

#include "Entity.h"

class Exit;

class Room : public Entity
{
	public:
		// Constructor
		Room(const char* name, const char* description);

		// Methods
		void Look();
		Exit* GetExit(const string& direction);

		// Object Attr
		list<Exit*> exitWays;
};

#endif //__Room__