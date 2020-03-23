#ifndef __Player__
#define __Player__

#include "creature.h"

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);

	void Look(const vector<string>& tokens);
	void Go(const vector<string>& args);
};

#endif __Player__
