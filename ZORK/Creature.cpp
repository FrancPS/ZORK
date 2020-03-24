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
	HP = maxHP = 1;
	mana = maxMana = 0;
	min_damage = 1;
	max_damage = 3;
	min_protection = max_protection = 1;
	weapon = armour = shield = NULL;
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
		cout << HP << "HOLAAAAAAAAAAAAAAAAAAAAAAAA!";
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
	int atk = 0;
	int def = 0;
	if (min_damage == max_damage)
		atk = max_damage;
	else
		atk = rand() % (max_damage - min_damage + 1) + min_damage;
	
	if (min_protection == max_protection)
		def = max_protection;
	else
		def = rand() % (max_protection - min_protection + 1) + min_protection;
	
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