#ifndef WORLD_H
#define WORLD_H

#include <vector>

class chunk;
class world;

#include "block.h"

class blockset {
public:
	uint32_t** blocks;
};

class chunk {
private:
	int chunkx, chunky;
	blockset blocks;
public:
	static const short width = 16;
	static const short height = 16;
	chunk(int chunkx, int chunky, blockset blocks);
	void render(sf::RenderWindow &window);
	void setblock(int x, int y, short id);
	void setblock(int x, int y, short id, short data);
	void setdata(int x, int y, short data);

	int getChunkX();
	int getChunkY();
};

class world {
private:
	std::vector<chunk> loadedChunks;
public:
	void loadChunk(int x, int y);
	void setblock(int x, int y, short id);
	void setblock(int x, int y, short id, short data);
	void setdata(int x, int y, short data);
	void render(sf::RenderWindow &window);
};

#endif