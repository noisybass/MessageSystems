#ifndef COMMUNICATION_PORT_H
#define COMMUNICATION_PORT_H

#include "Message.h"

namespace MessageSystems
{
	class CommunicationPort
	{
	public:
		virtual ~CommunicationPort();

		template<typename Object, void (Object::*Method)(const Message& m)>
		void addObserver(MessageType type, Object* observer)
		{
			addCommunication(new Communication{ type, observer, this, &invoke<Object, Method> });
			observer->addCommunication(new Communication{ type, observer, this, &invoke<Object, Method> });
		}

		template<typename Object, void (Object::*Method)(const Message& m)>
		void removeObserver(MessageType type, Object* observer)
		{
			Handler handler = &invoke<Object, Method>;

			removeObserver(type, observer, handler);
			observer->removeObserver(type, observer, handler);
		}

		void sendMessage(const Message& m);

	private:
		typedef void (*Handler)(CommunicationPort*, const Message& m);

		struct Communication
		{
			MessageType type;
			CommunicationPort* observer;
			CommunicationPort* subject;
			Handler handler;
			Communication* next;

			Communication(MessageType t, CommunicationPort* obs, CommunicationPort* sub, Handler h) :
				type{ t }, observer{ obs }, subject{ sub }, handler{ h }, next{ nullptr } {}
		};

		Communication* _coms = nullptr;

		void stopCommunication(const CommunicationPort* port);

		template<typename Object, void(Object::*Method)(const Message& message)>
		static void invoke(CommunicationPort* observer, const Message& m)
		{
			(static_cast<Object*>(observer)->*Method)(m);
		}

		void addCommunication(Communication* com);
		void removeObserver(MessageType type, CommunicationPort* observer, Handler handler)
		{
			if (_coms->type == type && _coms->observer == observer && _coms->handler == handler)
			{
				Communication* aux = _coms->next;
				_coms->next = nullptr;
				_coms = aux;
			}
			else
			{
				Communication* current = _coms;
				bool found = false;
				while (!found && current->next)
				{
					if (current->next->type == type && current->next->observer == observer && current->next->handler == handler)
					{
						Communication* aux = current->next->next;
						current->next->next = nullptr;
						current->next = aux;
						found = true;
					}
					else
						current = current->next;
				}
			}
		}
	};

} // namespace MessageSystems

#endif // COMMUNICATION_PORT_H