#include "Entity.h"

int main()
{
	MessageSystems::Entity e;

	e.addComponent(new MessageSystems::Component());
	e.addComponent(new MessageSystems::Component());
	e.addComponent(new MessageSystems::Component());

	MessageSystems::Message m;

	// As components accept the EXAMPLE type the message will be handled by the 
	// entity and its components
	m.type = MessageSystems::MessageType::EXAMPLE;
	e.handleMessage(m);

	// In this case the message will be handled only by the entity, because the
	// components does not have interest inthe type DEFAULT
	m.type = MessageSystems::MessageType::DEFAULT;
	e.handleMessage(m);

	return 0;
}