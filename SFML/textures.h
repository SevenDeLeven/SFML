#ifndef TEXTURES_H
#define TEXTURES_H

#include <SFML/Graphics.hpp>

const int BLOCKTEXTURES = 2;
std::vector<sf::Texture> blocktex;

namespace textures {
	sf::Texture BACKGROUND, PLAYER;
};

#endif
