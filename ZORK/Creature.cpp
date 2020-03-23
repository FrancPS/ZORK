#include "Room.h"
#include "Creature.h"

#include <iostream>

using namespace std;

Creature::Creature(const char* title, const char* description, Room* room) :
Entity(title, description, (Entity*)room) 
{

}