#ifndef __Room__
#define __Room__

#include <list>

#include "entity.h"

class Exit;

class Room : public Entity
{
	public:
		Room(const char* name, const char* description);

		void Look();
		Exit* GetExit(const string& direction);

		list<Exit*> exitWays;
};

#endif //__Room__