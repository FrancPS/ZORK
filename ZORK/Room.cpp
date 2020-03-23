#include "Entity.h"
#include "Room.h"
#include <iostream>
using namespace std;

Room::Room(const char* title, const char* description) :
	Entity(title, description, NULL)
{
}