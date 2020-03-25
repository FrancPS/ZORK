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
		void Look() const override;
		bool IsAlive() const;
		void Attack(Creature* enemy);
		void SetStats(int h, int m, int dmg, int def);
		void Equip(Item* item);
		void ApplyModifiers();
		void PrintStats() const;
		virtual void Inventory() const;
		virtual void Go(const vector<string>& tokens);

		// Object Attr
		int HP = 10;   // !!! Is it correct to initialise here?
		int mana = 0;
		int min_damage = 0;
		int max_damage = 0;
		int min_protection = 0;
		int max_protection = 0;
		Item* weapon = NULL;
		Item* armour = NULL;
		Item* shield = NULL;

	private:
		int maxHP = 10;
		int maxMana = 0;
		int base_damage = 2;
		int base_prot = 0;
};

#endif //__Creature__