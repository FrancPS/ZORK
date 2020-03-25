#ifndef __Entity__
#define __Entity__

#include <string>	// Used in inheritance classes
#include <vector>	// Used in inheritance classes
#include <list>

class Room;

using namespace std;

class Entity
{
	public:
		// Constructor
		Entity(const char* name, const char* description, Entity* parent);

		// Methods
		Room* GetRoom() const;
		virtual void Look() const;
		void	ChangeParent(Entity* new_parent);
		Entity* Find(const string& name) const;

		// Object Attr
	public:
		const char* const name;
		const char* description;
		Entity* parent;
		list<Entity*> container;
};

#endif //__Entity__