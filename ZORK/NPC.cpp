#include "Creature.h"
#include "NPC.h"


// ---- Constructor ----
NPC::NPC(const char* title, const char* description, Room* room) :
Creature(title, description, room)
{
}