#ifndef __Entity__
#define __Entity__

#include <string>	// Used in inheritance classes
#include <vector>	// Used in inheritance classes
#include <list>

using namespace std;

class Entity
{
	public:
		// Constructor
		Entity(const char* name, const char* description, Entity* parent);

		// Methods
		virtual void Look();
		void	ChangeParent(Entity* new_parent);

		// Object Attr
		const char* name;
		const char* description;
		Entity* parent;
		list<Entity*> container;
};

#endif //__Entity__