#include <iostream>

#include "World.h"
#include "Global.h"
#include "Entity.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"

vector<string> trollPath = { "east", "north", "west", "south" };

// ---- CONSTRUCTOR ---
World::World() {

	// ROOMS
	Room* forest = new Room("Forest", "You are surrounded by tall trees. It feels like a huge forest someone could get lost easily.");
	rooms.push_back(forest);
	Room* house = new Room("House", "You are inside a beautiful but small white house.");
	rooms.push_back(house);
	Room* basement = new Room("Basement", "The basement features old furniture and dim light.");
	rooms.push_back(basement);
	Room* mazeE = new Room("Maze Entrance", "You enter a dark and narrow corridor excavated in the underground that splits into three. \n"
		"As you get to the crossroad, the doorway from where you came collapses. You are trapped!");
	rooms.push_back(mazeE);
	Room* bones = new Room("Bone Room", "You follow the corridor to a room with an extinguished firecamp in a corner,\nand human bones scattered all around the floor.\n"
		"There is a rotting corpse in a corner");
	rooms.push_back(bones);
	Room* maze1 = new Room("Maze1", "You are in a small room that splits the corridor in two directions.");
	rooms.push_back(maze1);
	Room* maze2 = new Room("Maze2", "Another small room with a torch hanging on the wall.");
	rooms.push_back(maze2);
	Room* maze3 = new Room("Maze3", "Another small room with two torches hanging on the wall.");
	rooms.push_back(maze3);
	Room* maze4 = new Room("Maze4", "This bifurcation also splits the corridor in two directions.");
	rooms.push_back(maze4);
	Room* mazeExit = new Room("Circular Room", "You are in a circular room with torches in the wall, and a flat stone in the center.\n"
		"The stone has a circle of carved runes that emit some magical energy.");
	rooms.push_back(mazeExit);
	Room* roof = new Room("Rooftop", "The magic circle has teleported you to... THE ROOFTOP OF THE HOUSE!.");
	rooms.push_back(roof);

	// EXITS
	Exit* ex1 = new Exit("WEST", "EAST", "Little path", house, forest);
	exits.push_back(ex1);
	Exit* ex2 = new Exit("DOWN", "UP", "Stairs", house, basement);
	//ex2->locked = true;
	exits.push_back(ex2);
	Exit* ex3 = new Exit("EAST", "WEST", "Doorway", basement, mazeE);
	exits.push_back(ex3);
	Exit* exB1 = new Exit("EAST", "WEST", "Corridor", mazeE, bones);
	exits.push_back(exB1);
	Exit* exB2 = new Exit("SOUTH", "NORTH", "Corridor", mazeE, bones);
	exits.push_back(exB2);
	Exit* exM1 = new Exit("NORTH", "SOUTH", "Corridor", mazeE, maze1);
	exits.push_back(exM1);
	Exit* exM11 = new Exit("EAST", "WEST", "Corridor", maze1, maze2);
	exits.push_back(exM11);
	Exit* exM12 = new Exit("NORTH", "SOUTH", "Corridor", maze1, maze4);
	exits.push_back(exM12);
	Exit* exM2 = new Exit("NORTH", "SOUTH", "Corridor", maze2, maze3);
	exits.push_back(exM2);
	Exit* exM3 = new Exit("WEST", "EAST", "Corridor", maze3, maze4);
	exits.push_back(exM3);
	Exit* exM4 = new Exit("WEST", "EAST", "Corridor", maze4, mazeExit);
	exits.push_back(exM4);
	Exit* exME = new Exit("UP", "DOWN", "Teleport", mazeExit, roof); // true for one way
	//exME->locked = true;
	exits.push_back(exME);

	// PLAYER
	player = new Player("Hero", "You are an awesome adventurer!", forest);

	// CREATURES
	Creature* butler = new Creature("Butler", "It's James, the house Butler.", house);
	butler->SetStats(15, 0, 3, 0);
	creatures.push_back(butler);

	Creature* troll = new Creature("Troll", "It's an enormous Troll! You see he is wearing a shiny amulet on his neck.", maze1);
	troll->SetStats(40, 0, 7, 3);
	creatures.push_back(troll);

	Creature* corpse = new Creature("Soldier", "It's the rotting body of someone, possibly a soldier or an adventurer like you.\nOne leg has been... bitten? by something big.", bones);
	corpse->SetStats(0, 0, 3, 0);
	creatures.push_back(corpse);

	// ITEMS
	Item* mailbox = new Item("Mailbox", "Looks like it might contain something.", house);
	mailbox->isContainer = true;
	items.push_back(mailbox);

	Item* key = new Item("Key", "Old iron key.", mailbox);
	key->itemSize = 1;
	//ex2->key = key;

	Item* sword = new Item("Sword", "A simple old and rusty sword.", forest, WEAPON);
	sword->combatVal = 6;
	Item* sword2(sword);
	sword2->parent = butler;
	items.push_back(sword);

	Item* shield = new Item("Shield", "An old wooden shield.", butler, SHIELD);
	shield->combatVal = 3;
	items.push_back(shield);

	Item* amulet = new Item("Amulet", "A shiny magical amulet.", troll, COMMON);
	//exME->key = amulet;
	items.push_back(amulet);

	Item* potion = new Item("Potion", "A magical beverage to recover vitality.", corpse, HP_POTION);
	potion->combatVal = 15;
	items.push_back(potion);

	// EQUIP CREATURES
	butler->Equip(shield);
	butler->Equip(sword2);
}

// ---- PARSER ----
/* "Language interpreter". Reads the words of a list of strings and calls the
	functions relative to the actions indicated in the strings

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
const bool World::Parser(vector<string>& tokens)
{
	bool ret = true;
	if (tokens.size() > 0 && tokens[0].length() > 0) { // parse only if the token list is not empty
		switch (tokens.size())
		{
		case 1: // commands with no arguments ------------------------------
		{
			if (Same(tokens[0], "look") || Same(tokens[0], "l"))
			{
				trollAutoMove(trollPath);
				player->Look(tokens);
			}
			else if (Same(tokens[0], "north") || Same(tokens[0], "n"))
			{
				trollAutoMove(trollPath);
				player->Go({ "north" });
			}
			else if (Same(tokens[0], "south") || Same(tokens[0], "s"))
			{
				trollAutoMove(trollPath);
				player->Go({ "south" });
			}
			else if (Same(tokens[0], "east") || Same(tokens[0], "e"))
			{
				trollAutoMove(trollPath);
				player->Go({ "east" });
			}
			else if (Same(tokens[0], "west") || Same(tokens[0], "w"))
			{
				trollAutoMove(trollPath);
				player->Go({ "west" });
			}
			else if (Same(tokens[0], "up"))
			{
				trollAutoMove(trollPath);
				player->Go({ "up" });
			}
			else if (Same(tokens[0], "down"))
			{
				trollAutoMove(trollPath);
				player->Go({ "down" });
			}
			else if (Same(tokens[0], "inventory") || Same(tokens[0], "i"))
			{
				trollAutoMove(trollPath);
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
			else if (Same(tokens[1], "north") || Same(tokens[1], "n"))
			{
				trollAutoMove(trollPath);
				player->Go({ "north" });
			}
			else if (Same(tokens[1], "south") || Same(tokens[1], "s"))
			{
				trollAutoMove(trollPath);
				player->Go({ "south" });
			}
			else if (Same(tokens[1], "east") || Same(tokens[1], "e"))
			{
				trollAutoMove(trollPath);
				player->Go({ "east" });
			}
			else if (Same(tokens[1], "west") || Same(tokens[1], "w"))
			{
				trollAutoMove(trollPath);
				player->Go({ "west" });
			}
			else if (Same(tokens[0], "up"))
			{
				trollAutoMove(trollPath);
				player->Go({ "up" });
			}
			else if (Same(tokens[0], "down"))
			{
				trollAutoMove(trollPath);
				player->Go({ "down" });
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
			else if (Same(tokens[0], "drink"))
			{
				player->Drink(tokens);
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

// ----------------------------------------------------
void World::trollAutoMove(vector<string>& trollDir) {
	// Search the creature troll
	for (list<Creature*>::iterator it = creatures.begin(); it != creatures.end(); ++it) {
		if ((*it)->name == "Troll") {
			if ((*it)->IsAlive()) {
				// Leave a message if the player is in tha same room
				if (player->GetRoom() == (*it)->GetRoom())
					cout << "Troll went " << trollDir[0] << "..." << endl;

				(*it)->Go({ trollDir[0] }); // Troll changes room

				// Update vector for the next future direction
				trollDir.push_back(trollDir[0]);
				trollDir.erase(trollDir.begin());
			}
			break;
		}
	}
	
}