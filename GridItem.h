#pragma once
#include <SDL.h>

class GridItem
{
public:
	GridItem(int value, int x, int y);
	GridItem();
	~GridItem();
	int value;
	int x;
	int y;
};

