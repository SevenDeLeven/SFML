#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include "input.h"
#include "game.cpp"
#include "gameObject.cpp"
#include "player.cpp"
#include "block.cpp"
#include "client.cpp"
#include "textures.cpp"

bool running = true;

int main()
{
	startClient(running);
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	loadTextures();
	sf::Sprite background;
	background.setTexture(textures::BACKGROUND);

	sf::Clock cl;
	long last = cl.getElapsedTime().asMilliseconds();
	long now = cl.getElapsedTime().asMilliseconds();
	double delta = 0;

	player play(400, 300);
	objects.push_back(&play);

	while (window.isOpen() && running)
	{
		now = cl.getElapsedTime().asMilliseconds();
		delta += (now - last) * 60. / 1000.;
		last = now;
		bool updated = false;;
		while (delta > 1.) {
			delta--;
			update();
			updated = true;
		}
		if (updated) {
			window.clear();
			window.draw(background);
			render(window);
			window.display();
		}

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				input::keysPressed[event.key.code] = true;
				if (event.key.code == sf::Keyboard::Space) {
					objects.push_back(&bl);
				}
			}
			if (event.type == sf::Event::KeyReleased) {
				input::keysPressed[event.key.code] = false;
			}
			if (event.type == sf::Event::MouseMoved) {
				input::mx = event.mouseMove.x;
				input::my = event.mouseMove.y;
			}
		}
	}
	running = false;

	return 0;
}
