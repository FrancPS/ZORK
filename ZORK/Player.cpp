#include "Entity.h"
#include "Creature.h"
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const char* title, const char* description) :
	Creature(title, description) {
}