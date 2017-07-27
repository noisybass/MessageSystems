#include "Component.h"

#include <iostream>

namespace MessageSystems
{
	void Component::handleMessage(const Message& m)
	{
		std::cout << "[Component] Message received of type: " << m.type << std::endl;
	}

} // namespace MessageSystems