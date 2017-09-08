#include "block.h"

block::block(int id, sf::Texture* textures, int textlen) {
	this->id = id;
	for (int i = 0; i < textlen; i++) {
		sprites.push_back(sf::Sprite(textures[i]));
	}
}

void block::render(sf::RenderWindow &window, int x, int y, short data) {
	this->sprites[data].setPosition(x, y);
	window.draw(this->sprites[data]);
}

int block::getId() {
	return id;
}

void block::onUpdate() {}

