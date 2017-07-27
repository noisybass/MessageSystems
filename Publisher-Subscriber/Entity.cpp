#include "Entity.h"

#include <iostream>

namespace MessageSystems
{
	void Entity::addComponent(Component* c)
	{
		_components.push_back(c);
	}

} // namespace MessageSystems
