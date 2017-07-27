#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"

#include <vector>

namespace MessageSystems
{
	class Entity
	{
	public:
		Entity() = default;
		~Entity() = default;

		void addComponent(Component* c);
	private:
		std::vector<Component*> _components;

	}; // class Entity

} // namespace MessageSystems

#endif // ENTITY_H