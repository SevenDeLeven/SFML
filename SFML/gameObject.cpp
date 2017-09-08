#include "gameObject.h"

gameObject::gameObject(sf::Texture &texture, double _x, double _y) {
	pos.setX(_x);
	pos.setY(_y);
	sprite = sf::Sprite(texture);
}

double gameObject::getX() {
	return pos.getX();
}

double gameObject::getY() {
	return pos.getY();
}

sf::Sprite& gameObject::getSprite() {
	return this->sprite;
}

void gameObject::update() {}
void gameObject::render(sf::RenderWindow &window) {}