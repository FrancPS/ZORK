#ifndef __Entity__
#define __Entity__

#include <string>
#include <vector>
#include <list>

using namespace std;

class Entity
{
	public:
		Entity(const char* name, const char* description, Entity* parent);

		virtual void Look() const;

	public:
		const char* name;
		const char* description;
		Entity* parent;
		list<Entity*> container;
};

#endif //__Entity__