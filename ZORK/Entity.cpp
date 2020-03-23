#include "Entity.h"
#include <iostream>
using namespace std;



Entity::Entity(const char* name, const char* description, Entity* parent) :
name(name), description(description), parent(parent)
{
	if (parent != NULL)
		parent->container.push_back(this);
}

void Entity::Look()
{
	cout << name << endl;
	cout << description << endl;
}

void Entity::ChangeParent(Entity* new_parent)
{
	if (parent != NULL)
		parent->container.remove(this);

	parent = new_parent;

	if (parent != NULL)
		parent->container.push_back(this);
}