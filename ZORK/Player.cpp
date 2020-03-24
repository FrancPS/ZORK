#include <iostream>

#include "Player.h"
#include "Global.h"
#include "Room.h"
#include "Exit.h"
#include "Creature.h"


// ---- CONSTRUCTOR ----
Player::Player(const char* title, const char* description, Room* room) :
Creature(title, description, room)
{
	HP = maxHP = 25;
	mana = maxMana = 5;
}

// ---- LOOK ----
/* Prints the description of Something the player is looking at

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Player::Look(const vector<string>& tokens) const {

	// "look", "look room" or "look around" -> Describes the Room
	if (tokens.size() == 1 || Same(tokens[1], "room") || Same(tokens[1], "around"))
		parent->Look();
	// "look me" -> Describes the player itself
	else if (Same(tokens[1], "me")) {
		cout << name << endl;
		cout << description << endl;
	}
	// "look (name)" -> Describes something in particular in the room
	else if (tokens.size() > 1)
	{
		bool found = false;
		for (list<Entity*>::const_iterator it = parent->container.begin(); it != parent->container.cend(); ++it)
		{
			if (Same((*it)->name, tokens[1]))
			{
				(*it)->Look();
				found = true;
				break;
			}
		}
		if (!found)
			cout << "There is nothing like that here..." << endl;
	}
	// More options...?
	else
		cout << "Looking somewhere else" << endl;
}

// ---- GO ----
/* Moves the player to another Room. The tokens indicate which direction to take.

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Player::Go(const vector<string>& tokens) {
	Exit* exit = GetRoom()->GetExit(tokens[0]); // get the exit in the direction given
	
	// if there is no exit in that direction...
	if (exit == NULL) {
		cout << "\nThere is no exit at '" << tokens[0] << "'.\n";
	}
	// if there IS an exit...
	else {
		cout << "\nYou take direction " << exit->GetDirectionName((Room*)parent) << "...\n";
		ChangeParent(exit->GetDestination((Room*)parent));	// change the parent of the player (position)
		parent->Look();	// describe the new room
	}
}

// --- TAKE ---
/* Moves an Item from the room to the player's inventory

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Player::Take(const vector<string>& tokens)
{
	Entity* thing = parent->Find(tokens[1]);
	
	if (thing == NULL){
		cout << "There is nothing here with that name." << endl;
	}
	else {
		if (static_cast<Item*>(thing) != nullptr)
		{
			cout << "You take the " << thing->name << " and put it in your backpack." << endl;
			GetRoom()->itemsIn.remove((Item*)thing);
			thing->ChangeParent(this);
		}
		else
			cout << "How could you... ? " << endl;
	}
}

// ---- DROP ----
void Player::Drop(const vector<string>& tokens)
{
	Item* item = (Item*)Find(tokens[1]);

	if (item == NULL)
	{
		cout << "There is no item on you with that name." << endl;
	}
	else 
	{
		cout << "You drop " << item->name << "..." << endl;
		GetRoom()->itemsIn.push_back(item);
		item->ChangeParent(parent);
	}
}

// ---- INVENTORY ----
/* Prints the name of everything the player has in its possession

	Parameters:
		- NONE
	Return:
		- NONE
*/
void Player::Inventory() const
{
	if (container.size() == 0)
	{
		cout << "You do not own any item." << endl;
	}
	else 
	{
		// look all the child entities of player
		for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
		{
			if (*it == weapon)
				cout << "\n" << (*it)->name << " (as weapon)" << endl;
			else if (*it == armour)
				cout << "\n" << (*it)->name << " (as armour)";
			else if (*it == shield)
				cout << "\n" << (*it)->name << " (as armour)";
			else
				cout << (*it)->name << endl;
		}
	}
}

// ---- EQUIP ----
/* Searches an item in the player's inventory, and equips it at its
	corresponding slot

	Parameters:
		- Vesctor of strings
	Return:
		- NONE
*/
void Player::Equip(const vector<string>& tokens)
{
	Item* item = (Item*)Find(tokens[1]);
	
	// No item matched
	if (item == NULL)
	{
		cout << "Cannot find '" << tokens[1] << "', it is not in your inventory." << endl;
	}
	else 
	{
		// equip the item on its equipment slot
		switch (item->item_type)
		{
		case WEAPON:
			weapon = item;
			cout << "You equip " << item->name << " as a Weapon." << endl;
			break;

		case ARMOUR:
			armour = item;
			cout << "You equip " << item->name << " as Armour." << endl;
			break;

		case SHIELD:
			shield = item;
			cout << "You equip " << item->name << " as a Shield." << endl;
			break;

		default:
			cout << item->name << " cannot be equipped." << endl;
			break;
		}
	}
}

// ---- UNEQUIP ----
/* Empties an equipment slot if the matched item is equiped there

	Parameters:
		- Vesctor of strings
	Return:
		- NONE
*/
void Player::UnEquip(const vector<string>& tokens)
{
	if (Same(weapon->name, tokens[1])) {
		weapon = NULL;
		cout << "You un-equip " << tokens[1] << "..." << endl;
	}
	else if (Same(armour->name, tokens[1])) {
		armour = NULL;
		cout << "You un-equip " << tokens[1] << "..." << endl;
	}
	else if (Same(shield->name, tokens[1])) {
		shield = NULL;
		cout << "You un-equip " << tokens[1] << "..." << endl;
	}
	else
		cout << "You are not wearing this!" << endl;
}