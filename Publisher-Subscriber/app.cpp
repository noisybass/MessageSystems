#include "Component.h"
#include "MessageSystem.h"

int main()
{
	MessageSystems::Listener* c = (MessageSystems::Listener*)(new MessageSystems::Component());

	MessageSystems::MessageSystem::instance().addListener(MessageSystems::MessageType::EXAMPLE, c);
	MessageSystems::MessageSystem::instance().removeListener(MessageSystems::MessageType::EXAMPLE, c);

	MessageSystems::Message m;

	m.type = MessageSystems::MessageType::EXAMPLE;
	MessageSystems::MessageSystem::instance().sendMessage(m);

	return 0;
}