#include "Message/DynamicMessage/DynamicMessage.h"
#include "Message/DynamicMessage/ExampleMessage.h"
#include "Message/VariantMessage/VariantMessage.h"

#include <string>
#include <iostream>
#include <cassert>

int main()
{
	//// In this example it would not be necessary, but usually we're going to use polymorphism when handling messages
	MessageSystems::DynamicMessage* dM = (MessageSystems::DynamicMessage*)new MessageSystems::ExampleMessage("Hello, ");

	MessageSystems::VariantMessage vM;
	vM.type = MessageSystems::MessageType::EXAMPLE;
	vM.setArg<std::string>("argId", "World!");

	// This is the tricky thing. When using this variant approach, if you are using strings identifiers for the arguments,
	// you must check first if that argument exist and the identifier is correct.
	assert(vM.existArg("argId"));
	std::cout << /*((MessageSystems::ExampleMessage*) dM)->stringArg <<*/ (vM.existArg("argId") ? vM.getArg<std::string>("argId") : "") << std::endl;

	delete dM;

	return 0;
}