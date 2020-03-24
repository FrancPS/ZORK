#ifndef __Creature__
#define __Creature__

#include "Entity.h"
#include "Room.h"

class Creature : public Entity
{
public:
	// Constructor
	Creature(const char* name, const char* description, Room* room);

	// Methods
	Room* GetRoom() const;
	void Look(const vector<string>& args) const;
	bool IsAlive() const;

	// Object Attr
	int HP;
	int maxHP;
	int mana;
	int maxMana;
	int min_damage;
	int max_damage;
	int min_protection;
	int max_protection;
	Item* weapon;
	Item* armour;
	Item* shield;
};

#endif //__Creature__