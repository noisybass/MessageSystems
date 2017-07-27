#ifndef COMPONENT_H
#define COMPONENT_H

#include "Message.h"
#include "Listener.h"
#include "MessageSystem.h"

namespace MessageSystems
{
	// For the purpouse of this example I am implementing the acceptMessage
	// and handleMessage functions in Component class, but usually we will 
	// have to do this in the derived classes. Component should be an abstract class.
	class Component : Listener
	{
	public:
		Component() = default;
		virtual ~Component() = default;

		virtual void handleMessage(const Message& m);

	}; // class Component

} // namespace MessageSystems

#endif // COMPONENT_H