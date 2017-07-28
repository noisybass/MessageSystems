#ifndef COMPONENT_H
#define COMPONENT_H

#include "Message.h"
#include "Listener.h"
#include "MessageSystem.h"

namespace MessageSystems
{
	class Component : public Listener
	{
	public:
		Component() = default;
		virtual ~Component() = default;

		virtual void handleMessage(const Message& m);

	}; // class Component

} // namespace MessageSystems

#endif // COMPONENT_H