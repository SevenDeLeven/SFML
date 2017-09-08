#include "player.h"

player::player(double _x, double _y) : gameObject(textures::PLAYER, _x, _y) {
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void player::update() {
	double speed = 1;
	vector2d forces(0, 0);
	if (sf::Joystick::isConnected(0)) {
		double valX = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
		double valY = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);
		double multX = valX > 10 || valX < -10 ? valX / 100. : 0;
		double multY = valY > 20 || valY < -20 ? valY / 100. : 0;
		forces += vector2d(multX*speed, multY*speed);
	}
	else {
		bool inputx = false;
		bool inputy = false;
		if (input::keysPressed[sf::Keyboard::W]) {
			forces -= vector2d(0, speed);
			inputy = true;
		}
		if (input::keysPressed[sf::Keyboard::A]) {
			forces -= vector2d(speed, 0);
			inputx = true;
		}
		if (input::keysPressed[sf::Keyboard::S]) {
			forces += vector2d(0, speed);
			inputy = true;
		}
		if (input::keysPressed[sf::Keyboard::D]) {
			forces += vector2d(speed, 0);
			inputx = true;
		}
	}
	velocity /= 2;
	forces = speed;
	velocity += forces;
	if (velocity.getMag() > 10.0) {
		velocity = 10.0;
	}
	if (velocity.getMag() < -10.0) {
		velocity = -10.0;
	}
	pos += velocity;
}
void player::render(sf::RenderWindow &window) {
	sprite.setPosition(getX(), getY());
	window.draw(sprite);
}