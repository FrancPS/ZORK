#include <iostream>

#include "Global.h"
#include "Entity.h"



// ---- Constructor ----
Entity::Entity(const char* name, const char* description, Entity* parent) :
name(name), description(description), parent(parent)
{
	if (parent != NULL)
		parent->container.push_back(this);
}

// ---- LOOK ----
/* Prints to console the Name and Description of this Entity

	Parameters:
		- NONE
	Return:
		- NONE
*/
void Entity::Look() const
{
	cout << name << endl;
	cout << description << endl;
}

// ---- CHANGE PARENT ----
/* Changes the parent Entity of this Entity

	Parameters:
		- Entity Object
	Return:
		- NONE
*/
void Entity::ChangeParent(Entity* new_parent)
{
	// If it has a parent, remove it from its parent container list
	if (parent != NULL)
		parent->container.remove(this);

	// Set the new parent
	parent = new_parent;

	// If the new parent is not NULL, add it to its container list
	if (parent != NULL)
		parent->container.push_back(this);
}

// ---- FIND ----
/* Finds something contained in this Entity that matches a given name

	Parameters:
		- String
	Return:
		- Entity Object
*/
Entity* Entity::Find(const string& name) const
{
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if (Same((*it)->name, name))
			return *it;
	}
	return NULL;
}