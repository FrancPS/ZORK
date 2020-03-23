#include "Global.h"
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Creature.h"
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const char* title, const char* description, Room* room) :
Creature(title, description, room)
{
}

void Player::Look(const vector<string>& tokens) {

	if (tokens.size() == 1 || Same(tokens[1], "room") || Same(tokens[1], "around"))
		parent->Look();
	else if (Same(tokens[1], "me")) {
		cout << name << endl;
		cout << description << endl;
	}
	else
		cout << "looking somewhere else" << endl;
}

void Player::Go(const vector<string>& tokens) {
	Exit* exit = GetRoom()->GetExit(tokens[0]);
	
	if (exit == NULL) {
		cout << "\nThere is no exit at '" << tokens[0] << "'.\n";
	}
	else {
		cout << "\nYou take direction " << exit->GetDirectionName((Room*)parent) << "...\n";
		ChangeParent(exit->GetDestinationName((Room*)parent));
		parent->Look();
	}

	/*if (exit->locked)
	{
		cout << "\nThat exit is locked.\n";
	}*/

	
}