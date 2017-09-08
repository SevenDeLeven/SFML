#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <SFML/Network.hpp>

enum clientEventType {
	PACKETRECEIVED
};

class cEventPacketReceived {
public:
	sf::Packet packet;
};

class clientEvent {
private:
	clientEventType type;
protected:
	clientEvent(clientEventType type) {
		this->type = type;
	}
public:
	cEventPacketReceived packetReceived;

	clientEventType getType();
	static clientEvent& packetReceivedEvent(sf::Packet &packet);
};


#endif