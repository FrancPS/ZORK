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
	cout << "the player does " << tokens[0] << endl;
	cout << parent->description << endl;
}