#include "Entity.h"
#include "Creature.h"
#include "NPC.h"
#include <iostream>
using namespace std;

NPC::NPC(const char* title, const char* description, Room* room) :
	Creature(title, description, room) {

}