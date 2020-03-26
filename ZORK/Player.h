#ifndef __Player__
#define __Player__

#include "Creature.h"

class Player : public Creature
{
public:
	// Constructor
	Player(const char* name, const char* description, Room* room);

	// Methods
	void Look(const vector<string>& tokens) const;
	void Go(const vector<string>& tokens) override;
	void Take(const vector<string>& tokens);
	void Drop(const vector<string>& tokens);
	void Inventory() const override;
	void Equip(const vector<string>& tokens);
	void UnEquip(const vector<string>& tokens);
	void Put(const vector<string>& tokens);
	void TakeFrom(const vector<string>& tokens);
	void Combat(const vector<string>& tokens);
	void Stats(const vector<string>& tokens) const;
	void Loot(const vector<string>& tokens);
	void Victory() const;
	void Drink(const vector<string>& tokens);

};

#endif __Player__
