#ifndef MESSAGE_SYSTEM_H
#define MESSAGE_SYSTEM_H

#include <vector>
#include <unordered_map>

#include "Listener.h"

namespace MessageSystems
{
	class MessageSystem
	{
	public:
		static MessageSystem& instance()
		{
			static MessageSystem instance;
			return instance;
		}
		
		void addListener(MessageType type, Listener* listener);
		void removeListener(MessageType type, Listener* listener);

		void sendMessage(const Message& m);
	private:
		std::unordered_map<MessageType, std::vector<Listener*>> _listeners;

		MessageSystem() {};

	public:
		MessageSystem(MessageSystem const&) = delete;
		void operator=(MessageSystem const&) = delete;

	}; // class MessageSystem

} // namespace MessageSystems

#endif // MESSAGE_SYSTEM