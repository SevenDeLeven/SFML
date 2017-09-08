#include "textures.h"

void loadTextures() {
	textures::BACKGROUND.loadFromFile("background.png");
	textures::PLAYER.loadFromFile("player.png");
	for (int i = 0; i < BLOCKTEXTURES; i++) {
		blocktex.push_back(sf::Texture());
	}
	blocktex[0].create(32, 32);
	blocktex[1].loadFromFile("dirt.png");
}