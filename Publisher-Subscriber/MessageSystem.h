#ifndef MESSAGE_SYSTEM_H
#define MESSAGE_SYSTEM_H

#include <vector>
#include <unordered_map>

#include "Listener.h"

namespace MessageSystems
{
	class MessageSystem
	{
		typedef void(*Handler)(Listener*, const Message&);

		struct Delegate
		{
			Listener* listener;
			Handler handler;

			Delegate(Listener* l, Handler h) :
				listener{ l }, handler{ h } {}
		};

	public:
		static MessageSystem& instance()
		{
			static MessageSystem instance;
			return instance;
		}
		MessageSystem(MessageSystem const&) = delete;
		void operator=(MessageSystem const&) = delete;
		
		template<typename Object, void (Object::*Method)(const Message& message)>
		void addListener(MessageType type, Listener* listener)
		{
			Delegate d{ listener, &invoke<Object, Method> };
			if (_listeners.find(type) != _listeners.end())
			{
				_listeners[type].push_back(d);
			}
			else
			{
				std::vector<Delegate> listeners{ d };
				_listeners.emplace(type, listeners);
			}
		}

		template<typename Object, void (Object::*Method)(const Message& message)>
		void removeListener(MessageType type, Listener* listener)
		{
			if (_listeners.find(type) != _listeners.end())
			{

				/*auto result = std::find(_listeners[type].begin(), _listeners[type].end(), listener);
				if (result != _listeners[type].end())
				{
					_listeners[type].erase(result);
				}*/
				Handler handler = &invoke<Object, Method>;
				auto it = _listeners[type].begin();
				while (it != _listeners[type].end())
				{
					if (it->listener == listener && it->handler == handler)
						it = _listeners[type].erase(it);
					else
						++it;
				}
			}
		}

		void sendMessage(const Message& m);

	private:
		MessageSystem() {};

		std::unordered_map<MessageType, std::vector<Delegate>> _listeners;

		template<typename Object, void (Object::*Method)(const Message& message)>
		static void invoke(Listener* listener, const Message& m)
		{
			(static_cast<Object*>(listener)->*Method)(m);
		}

	}; // class MessageSystem

} // namespace MessageSystems

#endif // MESSAGE_SYSTEM