#pragma once
#include"GridItem.h"
#include <string>

class Grid
{
public:
	Grid();
	~Grid();
	void init();
	bool check(int i);
	int getXcount();
	int getOcount();
	GridItem* getarray();
	void setX(int i, int x, int y);
	void setO(int i, int x, int y);
	void restart();

	int GameOver();
	void clerGrid();

	int x = 0;
	int y = 0;
	SDL_Texture *texture = nullptr;
};


