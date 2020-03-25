#include <iostream>
#include <chrono>
#include <thread>

#include "Global.h"
#include "Creature.h"
#include "Room.h"



// ---- Constructor ----
Creature::Creature(const char* title, const char* description, Room* room) :
Entity(title, description, (Entity*)room) 
{
	if (title != "Xesk") {
		room->creaturesIn.push_back(this);
	}
}

// ---- GET ROOM ----
/* Get the Room where this object is located

	Parameters: 
		- NONE
	Return:
		- The Room Obj
*/
Room* Creature::GetRoom() const
{
	return (Room*)parent;
}

// ---- LOOK ----
/* Prints the description of the creature

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Creature::Look() const
{
	if (IsAlive())
	{
		cout << name << endl;
		cout << description << endl;
	}
	else
	{
		cout << name << "'s corpse" << endl;
		cout << "Here lies dead: " << description << endl;
	}
}

// ---- IS ALIVE ----
/* Returns true if this creature is alive, false if not

	Parameters:
		- NONE
	Return:
		- Boolean
*/
bool Creature::IsAlive() const
{
	return HP > 0;
}

// ---- ATTACK ----
/* Calulates a RNG for the damage of this creature and another for the enemy's
	defense, and substracts the corresponding HP of the resulting attack to the enemy

	Parameters:
		- Creature
	Return:
		- NONE
*/
void Creature::Attack(Creature* enemy)
{
	int atk = base_damage;
	int def = enemy->base_prot;
	if (min_damage == max_damage)
		atk += max_damage;
	else
		atk += rand() % (max_damage - min_damage + 1) + min_damage;
	
	if (enemy->min_protection == enemy->max_protection)
		def += enemy->max_protection;
	else
		def += rand() % (enemy->max_protection - enemy->min_protection + 1) + enemy->min_protection;
	
	int dmg = atk - def;
	if (dmg < 0)
		dmg = 0;
	enemy->HP -= dmg;

	cout << name << " attacks:\t" << atk << " damage." << endl;
	cout << enemy->name << " defends:\t" << def << " absorbed." << endl;
	cout << enemy->name << " looses:\t-" << dmg << " health points." << endl << endl;

	// Wait some time for the next attack
	using namespace std::this_thread;	// sleep_for
	using namespace std::chrono;		// nanoseconds
	sleep_for(seconds(1));
}

// ---- SET STATS ----
/* Setter for the initial base class of this Creature
	(health, mana, base damage, base defense)

	Parameters:
		- Int
		- Int
		- Int
		- Int
	Return:
		- NONE
*/
void Creature::SetStats(int h, int m, int dmg, int def) {
	HP = maxHP = h;
	mana = maxMana = m;
	base_damage = dmg;
	base_prot = def;
}

// ---- EQUIP ----
/* Equips an item to its corresponding slot.
	Equipping an item changes the stats of the Creature.

	Parameters:
		- Item Object
	Return:
		- NONE
*/
void Creature::Equip(Item* item)
{
	// equip the item on its equipment slot
	switch (item->item_type)
	{
	case WEAPON:
		weapon = item;
		break;

	case ARMOUR:
		armour = item;
		break;

	case SHIELD:
		shield = item;
		break;

	default:
		break;
	}
	ApplyModifiers();
}

// ---- APPLY MODIFIERS ----
/* Gets the combat values for the current equipped items,
	and adds them to the combat attributes of the Creature.

	Parameters:
		- NONE
	Return:
		- NONE
*/
void Creature::ApplyModifiers()
{
	// ATTACK
	if (weapon != NULL) {
		// if a weapon is equipped
		max_damage = weapon->combatVal;
		min_damage = (int)weapon->combatVal / 2;
	}
	else {
		// if a weapon is not equipped
		max_damage = 0;
		min_damage = 0;
	}
	// DEFENSE
	if (armour != NULL && shield != NULL) {
		// if shield and armour are equipped
		max_protection = armour->combatVal + shield->combatVal;
		min_protection = (int)(armour->combatVal / 2 + shield->combatVal / 2);
	}
	else if (armour != NULL && shield == NULL) {
		// if only armour is equipped
		max_protection = armour->combatVal;
		min_protection = (int)(armour->combatVal / 2);
	}
	else if (armour == NULL && shield != NULL) {
		// if only shield is equipped
		max_protection = shield->combatVal;
		min_protection = (int)(shield->combatVal / 2);
	}
	else {
		// if no protection is equipped
		max_protection = 0;
		min_protection = 0;
	}
}