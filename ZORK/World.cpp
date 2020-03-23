#include <iostream>

#include "World.h"
#include "Global.h"
#include "Entity.h"
#include "Room.h"
#include "Exit.h"


World::World() {
	


	
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
				//player->Look(tokens);
				cout << "the player looked" << endl;
			}
			else
				ret = false;
			break;
		}
		case 2: // commands with one argument ------------------------------
		{
			if (Same(tokens[0], "look") || Same(tokens[0], "l"))
			{
				//player->Look(tokens);
				cout << "the player looked" << endl;
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