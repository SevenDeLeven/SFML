#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class gameObject;

#include "vector2d.h"
#include "textures.h"

class gameObject {
protected:
	sf::Sprite sprite;
	vector2d pos;
public:
	gameObject(sf::Texture &texture, double _x, double _y);
	
	double getX();
	double getY();
	sf::Sprite& getSprite();

	virtual void update();
	virtual void render(sf::RenderWindow &window);
};
#endif
