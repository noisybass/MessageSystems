#include "CommunicationPort.h"

namespace MessageSystems
{
	CommunicationPort::~CommunicationPort()
	{
		Communication* current = _coms;
		while (current)
		{
			current->observer->stopCommunication(this);
			//current->subject->stopCommunication(this);
			current = current->next;
		}
		
		while (_coms)
		{
			Communication* aux = _coms->next;
			_coms->next = nullptr;
			_coms = aux;
		}
	}

	void CommunicationPort::stopCommunication(const CommunicationPort* port)
	{
		if (_coms->observer == port || _coms->subject == port)
		{
			Communication* aux = _coms->next;
			_coms->next = nullptr;
			_coms = aux;

		}

		if (_coms)
		{
			Communication* current = _coms;
			while (current->next)
			{
				if (current->next->observer == port || current->next->subject == port)
				{
					Communication* aux = current->next->next;
					current->next->next = nullptr;
					current->next = aux;
				}
				else
					current = current->next;
			}
		}
	}

	void CommunicationPort::sendMessage(const Message& m)
	{
		Communication* current = _coms;
		while (current)
		{
			if (current->type == m.type)
			{
				current->handler(current->observer, m);
			}
			current = current->next;
		}
	}

	void CommunicationPort::addCommunication(Communication* com)
	{
		com->next = _coms;
		_coms = com;
	}

} // namespace MessageSystems