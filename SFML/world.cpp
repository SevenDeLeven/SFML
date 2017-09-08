#include "world.h"
#include "block.h"

chunk::chunk(int chunkx, int chunky, blockset blocks) {
	this->chunkx = chunkx;
	this->chunky = chunky;
	this->blocks = blocks;
}
void chunk::render(sf::RenderWindow &window) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			uint32_t block = blocks.blocks[x][y];
			short blockid = (block >> 16) & 0x00FF;
			short blockdata = (block) & 0x00FF;
			block::blocks[blockid]->render(window, x + (chunkx*width), y + (chunky*height), blockdata);
		}
	}
}
void chunk::setblock(int x, int y, short id) {
	uint32_t nblock = ((int)id << 16) | ((int)0);
	blocks.blocks[x][y] = nblock;
}
void chunk::setblock(int x, int y, short id, short data) {
	uint32_t nblock = ((int)id << 16) | ((int)data);
	blocks.blocks[x][y] = nblock;
}
void chunk::setdata(int x, int y, short data) {
	short id = (blocks.blocks[x][y]>>16) & 0x00FF;
	uint32_t nblock = ((int)id << 16) | ((int)data);
	blocks.blocks[x][y] = nblock;
}

int chunk::getChunkX() {
	return chunkx;
}
int chunk::getChunkY() {
	return chunky;
}



void world::loadChunk(int x, int y) {
	//FOR NOW, IT JUST GENERATES A CHUNK FULL OF DIRT... LATER, IT WILL LOAD THE CHUNK FROM THE SERVER OR FILE, WHICHEVER METHOD
	//THAT THE WORLD IS USING TO GET THE CHUNKS
	//IN THE CASE THAT THE CHUNK IS BEING LOADED FROM A FILE, AND IT DOES NOT EXIST, THEN IT GENERATES IT
	for (int i = 0; i < loadedChunks.size(); i++) {
		if (loadedChunks[i].getChunkX() == x && loadedChunks[i].getChunkY() == y) {
			return;
		}
	}
	uint32_t** blocks[chunk::width][chunk::height];
	blockset bl;
	bl.blocks = **blocks; //MAYBE run into the problem of nullptr exception after this function is done?
	loadedChunks.push_back(chunk(x, y, bl));
}

void world::setblock(int x, int y, short id) {
	int chunkx = floor((double)x / chunk::width);
	int chunky = floor((double)y / chunk::height);
	for (int i = 0; i < loadedChunks.size(); i++) {
		loadedChunks[i].setblock(x%chunk::width, y%chunk::height, id);
	}
}
void world::setblock(int x, int y, short id, short data) {
	int chunkx = floor((double)x / chunk::width);
	int chunky = floor((double)y / chunk::height);
	for (int i = 0; i < loadedChunks.size(); i++) {
		loadedChunks[i].setblock(x%chunk::width, y%chunk::height, id, data);
	}
}
void world::setdata(int x, int y, short data) {
	int chunkx = floor((double)x / chunk::width);
	int chunky = floor((double)y / chunk::height);
	for (int i = 0; i < loadedChunks.size(); i++) {
		loadedChunks[i].setblock(x%chunk::width, y%chunk::height, data);
	}
}

void world::render(sf::RenderWindow &window) {
	for (int i = 0; i < loadedChunks.size(); i++) {
		loadedChunks[i].render(window);
	}
}