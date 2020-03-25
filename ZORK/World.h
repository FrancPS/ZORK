#ifndef __World__
#define __World__

#include <string>
#include <vector>
#include <list>

#include "Player.h"
#include "Room.h"
#include "Exit.h"


class World
{
	public:
		// Constructor
		World();

		// Methods
		const bool Parser(vector<string>& tokens);
		void trollAutoMove(vector<string>& trollDir);

	private:
		// Object Attr
		Player* player;
		list<Room*> rooms;
		list<Exit*> exits;
		list<Item*> items;
		list<Creature*> creatures;
};

#endif //__World__