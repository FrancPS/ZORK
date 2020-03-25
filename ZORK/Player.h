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
	void Go(const vector<string>& args);
	void Take(const vector<string>& args);
	void Drop(const vector<string>& args);
	void Inventory() const override;
	void Equip(const vector<string>& args);
	void UnEquip(const vector<string>& args);
	void Put(const vector<string>& tokens);
	void TakeFrom(const vector<string>& args);
	void Combat(const vector<string>& tokens);
	void Stats(const vector<string>& tokens) const;

};

#endif __Player__
