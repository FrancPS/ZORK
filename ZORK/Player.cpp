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
	type = PLAYER;
	SetStats(25, 5, 5, 0);
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
		for (list<Entity*>::const_iterator iter = parent->container.begin(); iter != parent->container.cend(); ++iter)
		{
			if (Same((*iter)->name, tokens[1]))
			{
				(*iter)->Look();
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
	
	string direction;
	if (tokens.size() == 1)
		direction = tokens[0];
	else
		direction = tokens[1];

	Exit* exit = GetRoom()->GetExit(direction); // get the exit in the direction given
	
	// if there is no exit in that direction...
	if (exit == NULL) {
		cout << "\nThere is no exit at '" << direction << "'.\n";
	}
	// if there IS an exit...
	else {
		cout << "\nYou take direction " << exit->GetDirectionName((Room*)parent) << "...\n";
		ChangeParent(exit->GetDestination((Room*)parent));	// change the parent of the player (position)
		parent->Look();	// describe the new room
		Victory();
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
		if (thing->type == ITEM)
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
/* Searches an item in the player's inventory, places it down inside the room

	Parameters:
		- Vesctor of strings
	Return:
		- NONE
*/
void Player::Drop(const vector<string>& tokens)
{
	Entity* item = Find(tokens[1]);

	if (item == NULL)
	{
		cout << "You don't have any item with that name." << endl;
	}
	else 
	{
		if (item->type = ITEM) {
			cout << "You drop " << item->name << "..." << endl;
			GetRoom()->itemsIn.push_back((Item*)item);
			item->ChangeParent(parent);
		}
		else
			cout << "How on earth did you get his?" << endl;
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
	cout << "INVENTORY:" << endl;
	if (container.size() == 0)
	{
		cout << "You do not own any item." << endl;
	}
	else 
	{
		// look all the child entities of player
		for (list<Entity*>::const_iterator iter = container.begin(); iter != container.cend(); ++iter)
		{
			if (*iter == weapon)
				cout << "-" << (*iter)->name << " (as weapon)" << endl;
			else if (*iter == armour)
				cout << "-" << (*iter)->name << " (as armour)" << endl;
			else if (*iter == shield)
				cout << "-" << (*iter)->name << " (as shield)" << endl;
			else
				cout << "-" << (*iter)->name << endl;
		}
	}
}

// ---- EQUIP ----
/* Searches an item in the player's inventory, and equips it at its
	corresponding slot.
	Equipping an item changes the stats of the Creature.

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Player::Equip(const vector<string>& tokens)
{
	Entity* thing = Find(tokens[1]);
	
	// No item matched
	if (thing == NULL)
	{
		cout << "Cannot find '" << tokens[1] << "', it is not in your inventory." << endl;
	}
	else 
	{
		if (thing->type = ITEM) {
			Item *item = (Item*)thing;
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
			ApplyModifiers();
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
	Entity* item = Find(tokens[1]);

	if (item != NULL) {
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
		ApplyModifiers();
	}
	else
		cout << "This item is not in your inventory." << endl;
}

// ---- PUT ----
/* Moves an Item from the player's inventory inside another Item
	Items have a container size, and if filled, they can't contain more objects

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Player::Put(const vector<string>& tokens)
{
	Entity* thingIn = Find(tokens[1]);

	// Any of your items matched
	if (thingIn == NULL)
		cout << "Cannot find '" << tokens[1] << "', it is not in your inventory." << endl;
	else
	{
		Entity* cont = parent->Find(tokens[3]);
		
		// Any of the items in the room matched
		if (cont == NULL)
			cout << "Cannot find '" << tokens[3] << "' in this room." << endl;
		else 
		{
			if (cont->type == ITEM) {
				Item* itemContainer = (Item*)cont;
				Item* itemIn = (Item*)thingIn;

				// If you can place something inside the item
				if (itemContainer->isContainer) {
					// Get other items inside the container, and see the space occupied
					int totalSpace = 0;
					Item* it;
					for (list<Entity*>::const_iterator iter = itemContainer->container.begin(); iter != itemContainer->container.cend(); ++iter)
					{
						it = (Item*)(*iter);
						totalSpace = totalSpace + it->itemSize;
					}
					totalSpace = totalSpace + itemIn->itemSize; // Add the space of the new item

					// If the item can fit in
					if (totalSpace <= itemContainer->itemSize) {
						itemIn->ChangeParent(itemContainer);
						cout << "You placed '" << itemIn->name << "' inside '" << itemContainer->name << "'." << endl;
					}
					else
						cout << "'" << itemIn->name << "' cannot fit inside '" << itemContainer->name << "'." << endl;
				}
				// If you cant place anything inside
				else
					cout << "You can't place anything inside '" << itemContainer->name << "'!" << endl;
			}
			else
				cout << "You can't place anything inside '" << cont->name << "'!" << endl;
		}
	}
}

// --- TAKE FROM ---
/* Moves an Item from inside an Item to the player's inventory

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Player::TakeFrom(const vector<string>& tokens)
{
	Entity* itemContainer = parent->Find(tokens[3]);

	if (itemContainer == NULL)
		cout << "Cannot find '" << tokens[3] << "' in this room." << endl;
	else {
		if (itemContainer->type == ITEM) {
			Entity* itemIn = itemContainer->Find(tokens[1]);
			if (itemIn != NULL) {
				if (itemIn->type == ITEM)
				{
					cout << "You take the '" << itemIn->name << "' from '" << itemContainer->name << "' and put it in your backpack." << endl;
					itemIn->ChangeParent(this);
				}
				else
					cout << "How could you... ?" << endl;
			}
			else
				cout << "There is nothing like that inside " << itemContainer->name << endl;
		}
		else
			cout << "Thats not how it works..." << endl;
	}
}

// -- COMBAT --
void Player::Combat(const vector<string>& tokens) {

	Creature* enemy = NULL;

	for (list<Creature*>::const_iterator iter = GetRoom()->creaturesIn.begin(); iter != GetRoom()->creaturesIn.cend(); ++iter)
	{
		if (Same((*iter)->name, tokens[1])) {
			enemy = *iter;
			break;
		}
	}

	if (enemy != NULL) 
	{
		while (IsAlive()) {
			Attack(enemy);
			if (enemy->IsAlive())
				enemy->Attack(this);
			else {
				cout << "You killed " << enemy->name << endl;
				enemy->HP = 0;
				break;
			}
		}

		if (!IsAlive()) {
			HP = 0;
			cout << "YOU DIED" << endl;
			cout << endl << "----------------------------------------------" << endl;
			cout << "((GAME OVER))" << endl;
			gameOver = true;
		}
	}
	else
		cout << "Attack... what?" << endl;
}

// ---- PRINT STATS ----
/* Print to console the stats of the player or the creature he is referring to

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Player::Stats(const vector<string>& tokens) const 
{
	// "stats"
	if (tokens.size() == 1) {
		cout << "Your stats:" << endl;
		PrintStats();
	}
	else {
		// "stats enemy"
		string enemyName;
		if (tokens.size() == 2) {
			enemyName = tokens[1];
		}
		// "stats of enemy"
		else {
			enemyName = tokens[2];
		}

		Creature* cre = NULL;
		for (list<Creature*>::const_iterator iter = GetRoom()->creaturesIn.begin(); iter != GetRoom()->creaturesIn.cend(); ++iter)
		{
			if (Same((*iter)->name, enemyName)) {
				cre = (*iter);
				break;
			}
		}
		if (cre != NULL) {
			cout << cre->name << " stats:" << endl;
			cre->PrintStats();
		}
		else
			cout << "There is no one here with this name." << endl;
	}
}

// ---- LOOT ----
/* Take all the items from a dead creature and puts them into the player's inventory

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Player::Loot(const vector<string>& tokens)
{
	Entity* creat = GetRoom()->Find(tokens[3]);
	Entity* it = NULL;
	
	if (creat->type == CREATURE){
		Creature* cre = (Creature*)creat;
		if (cre->IsAlive())
			cout << "You cannot take its items if it is alive!" << endl;
		else {
			for (list<Entity*>::const_iterator iter = cre->container.begin(); iter != cre->container.cend(); ++iter)
			{
				if (Same((*iter)->name, tokens[1])) {
					it = (*iter);
					break;
				}
			}

			if (it != NULL) {
				if (it->type == ITEM) {
					cout << "You loot " << it->name << " from " << cre->name << " and put it in your backpack." << endl;
					it->ChangeParent(this);
				}
			}
			else
				cout << endl << "You can't find this inside " << cre->name << "'s inventory." << endl;
		}
	}
	else
		cout << "That is not something you can loot." << endl;
}

// ---- VICTORY ----
/* Check the conditions for winning the game. The conditions are:
	- The player has the troll's amulet
	- The player escaped to the Rooftop

	Parameters:
		- NONE
	Return:
		- NONE
*/
void Player::Victory() const
{
	if (GetRoom()->name == "Rooftop") {
		Entity* amulet = Find("Amulet");
		if (amulet != NULL) {
			victory = true;
			gameOver = true;
		}
	}
}

// ---- DRINK ----
/* Player consumes a potion from its inventory

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Player::Drink(const vector<string>& tokens)
{
	Entity* thing = Find(tokens[1]);

	if (thing != NULL) {
		if (thing->type == ITEM) {
			Item* potion = (Item*)thing;
			if (potion->item_type == HP_POTION) {
				HP += potion->combatVal;

				if (HP > GetMaxHP()) {
					HP = GetMaxHP();
				}
				cout << "You drink " << potion->name << " and recover " << potion->combatVal << " HP." << endl;
				cout << "(The potion was consumed)" << endl;
				container.remove(potion);
				delete potion;
			}
			else
				cout << "You cannot drink this!" << endl;
		}
		else
			cout << "You cannot drink this!" << endl;
	}
	else
		cout << "Cannot find '" << tokens[1] << "', it is not in your inventory." << endl;
}