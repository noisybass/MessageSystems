#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"

#include <vector>

namespace MessageSystems
{
	class Entity : MessagesReceiver
	{
	public:
		Entity() = default;
		~Entity() = default;

		void addComponent(Component* c);

		virtual bool acceptMessage(MessageType type) { return true; };
		virtual void handleMessage(const Message& m);
	private:
		std::vector<Component*> _components;

	}; // class Entity

} // namespace MessageSystems

#endif // ENTITY_H