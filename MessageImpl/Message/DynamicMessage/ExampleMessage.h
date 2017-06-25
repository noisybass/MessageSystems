#ifndef EXAMPLE_MESSAGE_H
#define EXAMPLE_MESSAGE_H

#include "DynamicMessage.h"

#include <string>

namespace MessageSystems
{
	class ExampleMessage : DynamicMessage
	{
	public:
		
		std::string stringArg;

		ExampleMessage() : DynamicMessage(MessageType::EXAMPLE) {}
		ExampleMessage(std::string s) : DynamicMessage(MessageType::EXAMPLE), stringArg(s) {}

	}; //class ExampleMessage

} // namespace MessageSystems

#endif // EXAMPLE_MESSAGE_H