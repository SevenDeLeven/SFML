#ifndef BLOCK_H
#define BLOCK_H

class block;

#include "textures.h"
#include "gameObject.h"

class block {
private:
	int id;
protected:
	std::vector<sf::Sprite> sprites;
	block(int id, sf::Texture* textures, int textlen);
public:
	static block* blocks[2];
	void update() {}
	void render(sf::RenderWindow &window, int x, int y, short data);
	int getId();
	virtual void onUpdate();
};

class air : public block {
private:
protected:
public:

};

class dirt : public block {
private:
protected:
public:
	
};
#endif