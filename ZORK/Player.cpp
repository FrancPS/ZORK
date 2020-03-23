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
}

// ---- LOOK ----
/* Prints the description of Something the player is looking at

	Parameters:
		- Vector of strings
	Return:
		- NONE
*/
void Player::Look(const vector<string>& tokens) {

	// "look", "look room" or "look around" -> Describes the Room
	if (tokens.size() == 1 || Same(tokens[1], "room") || Same(tokens[1], "around"))
		parent->Look();
	// "look me" -> Describes the player itself
	else if (Same(tokens[1], "me")) {
		cout << name << endl;
		cout << description << endl;
	}
	// More options...?
	else
		cout << "looking somewhere else" << endl;
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
		ChangeParent(exit->GetDestinationName((Room*)parent));	// change the parent of the player (position)
		parent->Look();	// describe the new room
	}

	/*if (exit->locked)
	{
		cout << "\nThat exit is locked.\n";
	}*/
}