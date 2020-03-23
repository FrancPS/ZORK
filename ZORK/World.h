#ifndef __World__
#define __World__

#include <string>
#include <vector>

using namespace std;

class World
{
	public:
		World();

		bool Parser(vector<string>& tokens);
};

#endif //__World__