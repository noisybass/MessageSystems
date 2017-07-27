#include "MessageSystem.h"

namespace MessageSystems
{

	void MessageSystem::addListener(MessageType type, Listener* listener)
	{
		if (_listeners.find(type) != _listeners.end())
		{
			_listeners[type].push_back(listener);
		}
		else
		{
			std::vector<Listener*> listeners{ listener };
			_listeners.emplace(type, listeners);
		}
	}

	void MessageSystem::removeListener(MessageType type, Listener* listener)
	{
		if (_listeners.find(type) != _listeners.end())
		{

			auto result = std::find(_listeners[type].begin(), _listeners[type].end(), listener);
			if (result != _listeners[type].end())
			{
				_listeners[type].erase(result);
			}
		}
	}

	void MessageSystem::sendMessage(const Message& m)
	{
		if (_listeners.find(m.type) != _listeners.end())
		{
			std::vector<Listener*> listeners = _listeners[m.type];

			for (Listener* receiver : listeners)
				receiver->handleMessage(m);
		}
	}

} // namespace MessageSystems