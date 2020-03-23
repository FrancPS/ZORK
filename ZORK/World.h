#ifndef __World__
#define __World__

#include <string>
#include <vector>
#include <list>

using namespace std;

class Player;
class Room;
class Exit;

class World
{
	public:
		World();

		bool Parser(vector<string>& tokens);

	private:
		Player* player;
		list<Room*> rooms;
		list<Exit*> exits;
};

#endif //__World__