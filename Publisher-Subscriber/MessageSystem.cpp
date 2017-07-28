#include "MessageSystem.h"

namespace MessageSystems
{
	void MessageSystem::sendMessage(const Message& m)
	{
		if (_listeners.find(m.type) != _listeners.end())
		{
			std::vector<Delegate> listeners = _listeners[m.type];

			for (Delegate listener : listeners)
				listener.handler(listener.listener, m);
		}
	}

} // namespace MessageSystems