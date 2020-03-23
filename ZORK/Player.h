#ifndef __Player__
#define __Player__

#include "Creature.h"

class Player : public Creature
{
public:
	// Constructor
	Player(const char* name, const char* description, Room* room);

	// Methods
	void Look(const vector<string>& tokens);
	void Go(const vector<string>& args);
};

#endif __Player__
