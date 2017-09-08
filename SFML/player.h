#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class player;

#include "textures.h"
#include "input.h"
#include "vector2d.h"
#include "gameObject.h"

class player : public gameObject {
private:
	vector2d velocity;
public:
	player(double _x, double _y);
	virtual void update();
	virtual void render(sf::RenderWindow &window);
};

#endif
