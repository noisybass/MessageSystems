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
			Communication com{ type, observer, this, &invoke<Object, Method> };
			_coms.push_back(com);
			observer->_coms.push_back(com);
		}

		template<typename Object, void (Object::*Method)(const Message& m)>
		void removeObserver(MessageType type, Object* observer)
		{
			Handler handler = &invoke<Object, Method>;

			auto it = _coms.begin();
			while (it != _coms.end())
			{
				if (it->type == type && it->observer == observer && it->handler == handler)
					it = _coms.erase(it);
				else
					++it;
			}

			it = observer->_coms.begin();
			while (it != observer->_coms.end())
			{
				if (it->type == type && it->observer == observer && it->handler == handler)
					it = observer->_coms.erase(it);
				else
					++it;
			}
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

			Communication(MessageType t, CommunicationPort* obs, CommunicationPort* sub, Handler h) :
				type{ t }, observer{ obs }, subject{ sub }, handler{ h } {}
		};

		std::vector<Communication> _coms;

		void stopCommunication(const CommunicationPort* port);

		template<typename Object, void(Object::*Method)(const Message& message)>
		static void invoke(CommunicationPort* observer, const Message& m)
		{
			(static_cast<Object*>(observer)->*Method)(m);
		}
	};

} // namespace MessageSystems

#endif // COMMUNICATION_PORT_H