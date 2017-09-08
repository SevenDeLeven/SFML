#include "client.h"

clientEventType clientEvent::getType() {
	return type;
}

clientEvent& clientEvent::packetReceivedEvent(sf::Packet &packet) {
	clientEvent ret(PACKETRECEIVED);
	ret.packetReceived.packet = packet;
	return ret;
}

std::vector<clientEvent*> events;

void client(bool &running) {
	while (running) {
		for (int i = 0; i < events.size(); i++) {
			switch (events.at(i)->getType()) {
			case PACKETRECEIVED:
				std::string data("");
				events[i]->packetReceived.packet >> data;

				break;
			}
		}
	}
}

void startClient(bool &running) {
	sf::Thread cThread(client, running);
	cThread.launch();
}