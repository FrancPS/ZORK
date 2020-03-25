#include <iostream>

#include "World.h"
#include "Global.h"
#include "Entity.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"

// ---- CONSTRUCTOR ---
World::World() {

	// ROOMS
	Room* const room1 = new Room("Room1", "This is a room with stuff inside.");
	rooms.push_back(room1);
	Room* const room2 = new Room("Room2", "This is another room.");
	rooms.push_back(room2);

	// EXITS
	Exit* const exit = new Exit("EAST", "WEST", "an exit", room1, room2);
	exits.push_back(exit);

	// PLAYER
	player = new Player("Xesk", "You are you", room1);

	// CREATURES
	Creature* butler = new Creature("Butler", "It's James, the house Butler.", room1);
	creatures.push_back(butler);

	// ITEMS
	Item* const box = new Item("Box", "This is an item.", room1);
	box->isContainer = true;
	Item* const shield = new Item("sh", "This is a shield.", butler, SHIELD);
	shield->itemSize = 1;
	shield->combatVal = 3;

	// EQUIP CREATURES
	butler->Equip(shield);
	
}

// ---- PARSER ----
/* "Language interpreter". Reads the words of a list of strings and calls the
	functions relative to the actions indicated in the strings

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
const bool World::Parser(vector<string>& tokens) const
{
	bool ret = true;
	if (tokens.size() > 0 && tokens[0].length() > 0) { // parse only if the token list is not empty
		switch (tokens.size())
		{
		case 1: // commands with no arguments ------------------------------
		{
			if (Same(tokens[0], "look") || Same(tokens[0], "l"))
			{
				player->Look(tokens);
			}
			else if (Same(tokens[0], "north") || Same(tokens[0], "n"))
			{
				player->Go({ "north" });
			}
			else if (Same(tokens[0], "south") || Same(tokens[0], "s"))
			{
				player->Go({ "south" });
			}
			else if (Same(tokens[0], "east") || Same(tokens[0], "e"))
			{
				player->Go({ "east" });
			}
			else if (Same(tokens[0], "west") || Same(tokens[0], "w"))
			{
				player->Go({ "west" });
			}
			else if (Same(tokens[0], "inventory") || Same(tokens[0], "i"))
			{
				player->Inventory();
			}
			else if (Same(tokens[0], "stats") || Same(tokens[0], "st"))
			{
				player->Stats(tokens);
			}
			else
				ret = false;
			break;
		}
		case 2: // commands with one argument ------------------------------
		{
			if (Same(tokens[0], "look") || Same(tokens[0], "l"))
			{
				player->Look(tokens);
			}
			else if (Same(tokens[0], "take") || Same(tokens[0], "pick"))
			{
				player->Take(tokens);
			}
			else if (Same(tokens[0], "drop"))
			{
				player->Drop(tokens);
			}
			else if (Same(tokens[0], "equip") || Same(tokens[0], "eq"))
			{
				player->Equip(tokens);
			}
			else if (Same(tokens[0], "unequip") || Same(tokens[0], "uneq"))
			{
				player->UnEquip(tokens);
			}
			else if (Same(tokens[0], "attack") || Same(tokens[0], "atk"))
			{
				player->Combat(tokens);
			}
			else if (Same(tokens[0], "stats") || Same(tokens[0], "st"))
			{
				player->Stats(tokens);
			}
			else
				ret = false;
			break;
		}
		case 3:
			if (Same(tokens[0], "stats") || Same(tokens[0], "st"))
			{
				player->Stats(tokens);
			}
			else
				ret = false;
			break;


		case 4: // commands with 3 argument ------------------------------
		{
			if (Same(tokens[0], "take") || Same(tokens[0], "pick"))
			{
				player->TakeFrom(tokens);
			}
			else if (Same(tokens[0], "put") || Same(tokens[0], "place"))
			{
				player->Put(tokens);
			}
			else if (Same(tokens[0], "loot"))
			{
				player->Loot(tokens);
			}
			else
				ret = false;
			break;
		}
		default:
			ret = false;
		}
	}
	return ret;
}