#include "Global.h"
#include "Entity.h"
#include "Creature.h"
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const char* title, const char* description, Room* room) :
Creature(title, description, room)
{
}

void Player::Look(const vector<string>& tokens) {

	if (tokens.size() == 1)
		parent->Look();
	else if (Same(tokens[1], "me")) {
		cout << name << endl;
		cout << description << endl;
	}
	else
		cout << "looking somewhere else" << endl;
	
}