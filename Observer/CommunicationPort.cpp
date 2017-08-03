#include "CommunicationPort.h"

namespace MessageSystems
{
	CommunicationPort::~CommunicationPort()
	{
		while (!_coms.empty())
		{
			Communication com = _coms.back();
			_coms.pop_back();
			com.observer->stopCommunication(this);
			com.subject->stopCommunication(this);
		}
	}

	void CommunicationPort::stopCommunication(const CommunicationPort* port)
	{
		auto it = _coms.begin();
		while (it != _coms.end())
		{
			if (it->observer == port || it->subject == port)
				it = _coms.erase(it);
			else
				++it;
		}
	}

	void CommunicationPort::sendMessage(const Message& m)
	{
		for (Communication com : _coms)
		{
			if (com.type == m.type)
				com.handler(com.observer, m);
		}
	}

} // namespace MessageSystems