#include "game.h"

void update() {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->update();
	}
}

void render(sf::RenderWindow &window) {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->render(window);
	}
}