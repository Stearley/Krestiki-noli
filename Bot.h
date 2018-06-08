#pragma once
#include "GridItem.h"

class Bot
{
public:
	Bot();
	~Bot();

	void init();
	bool check(int i);
	int bot_turn;
	int hum_turn;
	int getXcount();
	int getOcount();
	GridItem* getarray();
	void setX(int i, int x, int y);
	void setO(int i, int x, int y);
	void restart();

	int bot_play_x();
	int bot_play_o();
	int GameOver();
	void clerGrid();
};


