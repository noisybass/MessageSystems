#include "Entity.h"

#include <iostream>

namespace MessageSystems
{
	void Entity::addComponent(Component* c)
	{
		_components.push_back(c);
	}

	void Entity::handleMessage(const Message& m)
	{
		// First handle the message
		std::cout << "[Entity] Message received of type: " << m.type << std::endl;

		// And spread the message
		for (Component* c : _components)
			if (c->acceptMessage(m.type))
				c->handleMessage(m);
	}

} // namespace MessageSystems
