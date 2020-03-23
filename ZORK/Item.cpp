#include "Entity.h"
#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(const char* title, const char* description) :
	Entity(title, description) {

}