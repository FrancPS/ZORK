#ifndef __NPC__
#define __NPC__

class NPC : public Creature
{
public:
	// Constructor
	NPC(const char* name, const char* description, Room* room);
};

#endif //__NPC__