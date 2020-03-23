#include "Entity.h"
#include <iostream>
using namespace std;



Entity::Entity(const char* name, const char* description, Entity* parent) :
name(name), description(description), parent(parent)
{

}

void Entity::Look() const
{
	cout << name << endl;
	cout << description << endl;
}