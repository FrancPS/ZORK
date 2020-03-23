#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include <iostream>
using namespace std;

Exit::Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination, bool one_way) :
	Entity(name, description),
	closed(false), locked(false), key(NULL), one_way(one_way), destination(destination), opposite_name(opposite_name)
{

}


