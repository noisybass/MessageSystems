#ifndef COMPONENT_H
#define COMPONENT_H

#include "Message.h"
#include "CommunicationPort.h"

namespace MessageSystems
{
	class Component : public CommunicationPort
	{
	public:
		Component() = default;

		virtual void handleMessage(const Message& m);

	}; // class Component

} // namespace MessageSystems

#endif // COMPONENT_H