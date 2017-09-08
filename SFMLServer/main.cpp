#include <iostream>
#include <string>
#include <SFML/Network.hpp>

void out() {
	std::cout << "WORLD" << std::endl;
}

int main() {
	sf::Thread outThread(out);
	outThread.launch();
	
	return 0;
}
