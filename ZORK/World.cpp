#include <iostream>

#include "World.h"
#include "Global.h"
#include "Entity.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"


World::World() {

	// ROOMS
	Room* room1 = new Room("Room1", "This is a room with stuff inside.");
	rooms.push_back(room1);


	// PLAYER
	player = new Player("Xesk", "You are you", room1);
}

bool World::Parser(vector<string>& tokens)
{
	bool ret = true;
	if (tokens.size() > 0 && tokens[0].length() > 0) {
		switch (tokens.size())
		{
		case 1: // commands with no arguments ------------------------------
		{

			if (Same(tokens[0], "look") || Same(tokens[0], "l"))
			{
				player->Look(tokens);
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