#ifndef DYNAMIC_MESSAGE_H
#define DYNAMIC_MESSAGE_H

#include "Message/MessageType.h"

namespace MessageSystems
{
	class DynamicMessage
	{
	public:
		MessageType type;

		virtual ~DynamicMessage();

	protected:
		DynamicMessage() : type(MessageType::DEFAULT) {}
		DynamicMessage(MessageType t) : type(t) {}
		
	}; //class DynamicMessage

} // namespace MessageSystems

#endif // DYNAMIC_MESSAGE_H