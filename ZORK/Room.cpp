#include "Global.h"
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include <iostream>
using namespace std;

Room::Room(const char* title, const char* description) :
	Entity(title, description, NULL)
{
}

void Room::Look() {
	// Print the info of the room
	cout << name << endl;
	cout << description << endl;

	// Print the info of the exits in the room
	for (list<Exit*>::const_iterator iter = exitWays.begin(); iter != exitWays.cend(); ++iter)
	{
		Exit* ex = *iter;
		cout << "Direction " << ex->GetDirectionName(this) << " you see " << ex->description << " that leads to " << ex->GetDestinationName(this)->name << endl;
	}
}

Exit* Room::GetExit(const string& direction) {
	for (list<Exit*>::const_iterator iter = exitWays.begin(); iter != exitWays.cend(); ++iter)
	{
		Exit* ex = *iter;
		if (Same(ex->GetDirectionName(this), direction))
			return ex;
	}
	return NULL;
}