#ifndef DYNAMIC_MESSAGE_H
#define DYNAMIC_MESSAGE_H

#include "MessageType.h"

namespace MessageSystems
{
	class DynamicMessage
	{
	public:
		MessageType type;

		DynamicMessage() : type(MessageType::DEFAULT) {}
		DynamicMessage(MessageType t) : type(t) {}
		
		virtual ~DynamicMessage() = default;

	}; //class DynamicMessage

} // namespace MessageSystems

#endif // DYNAMIC_MESSAGE_H