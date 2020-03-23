#include "Entity.h"
#include "Creature.h"
#include <iostream>
using namespace std;

Creature::Creature(const char* title, const char* description) :
	Entity(title, description) {

}