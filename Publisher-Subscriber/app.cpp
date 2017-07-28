#include "Component.h"
#include "MessageSystem.h"

int main()
{
	MessageSystems::Listener* c = (MessageSystems::Listener*)(new MessageSystems::Component());
	MessageSystems::Component c2;

	MessageSystems::MessageSystem::instance().addListener<MessageSystems::Listener, &MessageSystems::Listener::handleMessage>(MessageSystems::MessageType::EXAMPLE, c);
	MessageSystems::MessageSystem::instance().addListener<MessageSystems::Component, &MessageSystems::Component::handleMessage>(MessageSystems::MessageType::EXAMPLE, &c2);
	MessageSystems::MessageSystem::instance().removeListener<MessageSystems::Listener, &MessageSystems::Listener::handleMessage>(MessageSystems::MessageType::EXAMPLE, c);

	MessageSystems::Message m;

	m.type = MessageSystems::MessageType::EXAMPLE;
	MessageSystems::MessageSystem::instance().sendMessage(m);

	return 0;
}