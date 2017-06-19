#include "DynamicMessage.h"
#include "ExampleMessage.h"
#include "VariantMessage.h"

#include <string>
#include <iostream>

int main()
{
	MessageSystems::DynamicMessage* dM = (MessageSystems::DynamicMessage*)new MessageSystems::ExampleMessage("Hello, ");

	MessageSystems::VariantMessage vM;
	vM.type = MessageSystems::MessageType::EXAMPLE;
	vM.setArg<std::string>("argId", "World!");

	std::cout << ((MessageSystems::ExampleMessage*) dM)->stringArg << (vM.existArg("argId") ? vM.getArg<std::string>("argId") : "") << std::endl;

	return 0;
}