#ifndef __World__
#define __World__

#include <string>
#include <vector>
#include <list>

using namespace std;

class Room;
class Player;

class World
{
	public:
		World();

		bool Parser(vector<string>& tokens);

	private:
		Player* player;
		list<Room*> rooms;
};

#endif //__World__