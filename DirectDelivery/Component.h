#ifndef COMPONENT_H
#define COMPONENT_H

#include "MessagesReceiver.h"

namespace MessageSystems
{
	// For the purpouse of this example I am implementing the acceptMessage
	// and handleMessage functions in Component class, but usually we will 
	// have to do this in the derived classes. Component should be an abstract class.
	class Component : MessagesReceiver
	{
	public:
		Component() = default;
		virtual ~Component() = default;

		virtual bool acceptMessage(MessageType type);
		virtual void handleMessage(const Message& m);

	}; // class Component

} // namespace MessageSystems

#endif // COMPONENT_H