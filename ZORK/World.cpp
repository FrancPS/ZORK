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
	Room* room1 = new Room("Room1", "This is a room with stuff inside.");
	rooms.push_back(room1);
	Room* room2 = new Room("Room2", "This is another room.");
	rooms.push_back(room2);

	// EXITS
	Exit* exit = new Exit("EAST", "WEST", "an exit", room1, room2);
	exits.push_back(exit);

	// PLAYER
	player = new Player("Xesk", "You are you", room1);
	player->HP = player->maxHP = 25;
	player->mana = player->maxMana = 5;

	// ITEMS
	Item* item = new Item("Item", "This is an item.", room1);
	Item* shield = new Item("sh", "This is a shield.", room1, SHIELD);

	
}

// ---- PARSER ----
/* "Language interpreter". Reads the words of a list of strings and calls the
	functions relative to the actions indicated in the strings

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
bool World::Parser(vector<string>& tokens)
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
			else if (Same(tokens[0], "equip") || Same(tokens[0], "eq"))
			{
				player->Equip(tokens);
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