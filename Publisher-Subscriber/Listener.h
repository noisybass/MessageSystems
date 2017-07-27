#ifndef LISTENER_H
#define LISTENER_H

#include "Message.h"

namespace MessageSystems
{
	class Listener
	{
	public:
		virtual ~Listener() = default;
		virtual void handleMessage(const Message& m) = 0;
	};

} // namespace MessageSystems

#endif // LISTENER_H