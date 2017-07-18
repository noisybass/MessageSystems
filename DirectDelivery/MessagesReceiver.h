#ifndef MESSAGES_RECEIVER_H
#define MESSAGES_RECEIVER_H

#include "Message.h"

namespace MessageSystems
{
	class MessagesReceiver
	{
	public:
		virtual ~MessagesReceiver() = default;
		virtual bool acceptMessage(MessageType type) = 0;
		virtual void handleMessage(const Message& m) = 0;

	}; // class MessagesReceiver

} // namespace MessageSystems

#endif // MESSAGES_RECEIVER_H