#include "Component.h"

int main()
{
	MessageSystems::Component observer;
	MessageSystems::Component anotherObserver;
	MessageSystems::Component subject;

	subject.addObserver<MessageSystems::Component, &MessageSystems::Component::handleMessage>(MessageSystems::MessageType::EXAMPLE, &observer);
	subject.addObserver<MessageSystems::Component, &MessageSystems::Component::handleMessage>(MessageSystems::MessageType::DEFAULT, &anotherObserver);

	//subject.removeObserver<MessageSystems::Component, &MessageSystems::Component::handleMessage>(MessageSystems::MessageType::EXAMPLE, &observer);
	//subject.removeObserver<MessageSystems::Component, &MessageSystems::Component::handleMessage>(MessageSystems::MessageType::DEFAULT, &anotherObserver);

	MessageSystems::Message m;

	m.type = MessageSystems::MessageType::EXAMPLE;
	subject.sendMessage(m);

	return 0;
}