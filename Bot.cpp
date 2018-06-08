#include "Bot.h"
#include <iostream>

GridItem grid_b[9];
GridItem grid_copy[9];

int Xcount_b = 0;
int Ycount_b = 0;

Bot::Bot()
{
}


Bot::~Bot()
{
}

void Bot::init()
{
	grid_b[0].value = 0; grid_b[0].x = 20; grid_b[0].y = 20;
	grid_b[1].value = 0; grid_b[1].x = 220; grid_b[1].y = 20;
	grid_b[2].value = 0; grid_b[2].x = 420; grid_b[2].y = 20;
	grid_b[3].value = 0; grid_b[3].x = 20; grid_b[3].y = 220;
	grid_b[4].value = 0; grid_b[4].x = 220; grid_b[4].y = 220;
	grid_b[5].value = 0; grid_b[5].x = 420; grid_b[5].y = 220;
	grid_b[6].value = 0; grid_b[6].x = 20; grid_b[6].y = 420;
	grid_b[7].value = 0; grid_b[7].x = 220; grid_b[7].y = 420;
	grid_b[8].value = 0; grid_b[8].x = 420; grid_b[8].y = 420;
	for (int i = 0; i < 9; i++)
	{
		grid_copy[i].value = grid_b[i].value;
		grid_copy[i].x = grid_b[i].x;
		grid_copy[i].y = grid_b[i].x;
	}
}

bool Bot::check(int i)
{
	if (grid_b[i].value == 0) return true;
	else return false;
}

void Bot::setX(int i, int x, int y)
{
	grid_b[i].value = 1;
	grid_b[i].x = x;
	grid_b[i].y = y;
}

void Bot::setO(int i, int x, int y)
{
	grid_b[i].value = 2;
	grid_b[i].x = x;
	grid_b[i].y = y;
}

void Bot::clerGrid()
{
	for (int i = 0; i < 9; i++)
	{
		grid_b[i].value = 0;
	}
}

int Bot::getXcount()
{
	return Xcount_b;
}

int Bot::getOcount()
{
	return Ycount_b;
}

void Bot::restart()
{
	clerGrid();
	Xcount_b = 0;
	Ycount_b = 0;
}


int Bot::GameOver()
{
	if (
		(grid_b[0].value == 1 && grid_b[1].value == 1 && grid_b[2].value == 1) ||
		(grid_b[3].value == 1 && grid_b[4].value == 1 && grid_b[5].value == 1) ||
		(grid_b[6].value == 1 && grid_b[7].value == 1 && grid_b[8].value == 1) ||

		(grid_b[0].value == 1 && grid_b[3].value == 1 && grid_b[6].value == 1) ||
		(grid_b[1].value == 1 && grid_b[4].value == 1 && grid_b[7].value == 1) ||
		(grid_b[2].value == 1 && grid_b[5].value == 1 && grid_b[8].value == 1) ||

		(grid_b[0].value == 1 && grid_b[4].value == 1 && grid_b[8].value == 1) ||
		(grid_b[2].value == 1 && grid_b[4].value == 1 && grid_b[6].value == 1)
		)
	{
		Xcount_b++; clerGrid();
		return 1;
	}

	if (
		(grid_b[0].value == 2 && grid_b[1].value == 2 && grid_b[2].value == 2) ||
		(grid_b[3].value == 2 && grid_b[4].value == 2 && grid_b[5].value == 2) ||
		(grid_b[6].value == 2 && grid_b[7].value == 2 && grid_b[8].value == 2) ||

		(grid_b[0].value == 2 && grid_b[3].value == 2 && grid_b[6].value == 2) ||
		(grid_b[1].value == 2 && grid_b[4].value == 2 && grid_b[7].value == 2) ||
		(grid_b[2].value == 2 && grid_b[5].value == 2 && grid_b[8].value == 2) ||

		(grid_b[0].value == 2 && grid_b[4].value == 2 && grid_b[8].value == 2) ||
		(grid_b[2].value == 2 && grid_b[4].value == 2 && grid_b[6].value == 2)
		)
	{
		Ycount_b++; clerGrid();
		return 2;
	}

	int j = 0;
	for (int i = 0; i < 9; i++)
	{
		if (grid_b[i].value != 0) j++;
	}
	if (j == 9) {
		Ycount_b++; Xcount_b++;
		return 3;
	}
	if (Xcount_b == 10 || Ycount_b == 10) { Xcount_b = Ycount_b = 0; }
	return 0;
}

int Bot::bot_play_x()
{

	if (grid_b[0].value == 1 && grid_b[1].value == 1 && grid_b[2].value == 0) { grid_b[2].value = 1; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }
	if (grid_b[0].value == 1 && grid_b[1].value == 0 && grid_b[2].value == 1) { grid_b[1].value = 1; grid_b[1].x = 220; grid_b[1].y = 20; return 0; }
	if (grid_b[0].value == 0 && grid_b[1].value == 1 && grid_b[2].value == 1) { grid_b[0].value = 1; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[3].value == 1 && grid_b[4].value == 1 && grid_b[5].value == 0) { grid_b[5].value = 1; grid_b[5].x = 420; grid_b[5].y = 220; return 0; }
	if (grid_b[3].value == 1 && grid_b[4].value == 0 && grid_b[5].value == 1) { grid_b[4].value = 1; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[3].value == 0 && grid_b[4].value == 1 && grid_b[5].value == 1) { grid_b[3].value = 1; grid_b[3].x = 20; grid_b[3].y = 220; return 0; }

	if (grid_b[6].value == 1 && grid_b[7].value == 1 && grid_b[8].value == 0) { grid_b[8].value = 1; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[6].value == 1 && grid_b[7].value == 0 && grid_b[8].value == 1) { grid_b[7].value = 1; grid_b[7].x = 220; grid_b[7].y = 420; return 0; }
	if (grid_b[6].value == 0 && grid_b[7].value == 1 && grid_b[8].value == 1) { grid_b[6].value = 1; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }




	if (grid_b[0].value == 1 && grid_b[3].value == 1 && grid_b[6].value == 0) { grid_b[6].value = 1; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }
	if (grid_b[0].value == 1 && grid_b[3].value == 0 && grid_b[6].value == 1) { grid_b[3].value = 1; grid_b[3].x = 20; grid_b[3].y = 220; return 0; }
	if (grid_b[0].value == 0 && grid_b[3].value == 1 && grid_b[6].value == 1) { grid_b[0].value = 1; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[1].value == 1 && grid_b[4].value == 1 && grid_b[7].value == 0) { grid_b[7].value = 1; grid_b[7].x = 220; grid_b[7].y = 420; return 0; }
	if (grid_b[1].value == 1 && grid_b[4].value == 0 && grid_b[7].value == 1) { grid_b[4].value = 1; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[1].value == 0 && grid_b[4].value == 1 && grid_b[7].value == 1) { grid_b[1].value = 1; grid_b[1].x = 220; grid_b[1].y = 20; return 0; }

	if (grid_b[2].value == 1 && grid_b[5].value == 1 && grid_b[8].value == 0) { grid_b[8].value = 1; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[2].value == 1 && grid_b[5].value == 0 && grid_b[8].value == 1) { grid_b[5].value = 1; grid_b[5].x = 420; grid_b[5].y = 220; return 0; }
	if (grid_b[2].value == 0 && grid_b[5].value == 1 && grid_b[8].value == 1) { grid_b[2].value = 1; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }



	if (grid_b[0].value == 1 && grid_b[4].value == 1 && grid_b[8].value == 0) { grid_b[8].value = 1; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[0].value == 1 && grid_b[4].value == 0 && grid_b[8].value == 1) { grid_b[4].value = 1; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[0].value == 0 && grid_b[4].value == 1 && grid_b[8].value == 1) { grid_b[0].value = 1; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[2].value == 1 && grid_b[4].value == 1 && grid_b[6].value == 0) { grid_b[6].value = 1; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }
	if (grid_b[2].value == 1 && grid_b[4].value == 0 && grid_b[6].value == 1) { grid_b[4].value = 1; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[2].value == 0 && grid_b[4].value == 1 && grid_b[6].value == 1) { grid_b[2].value = 1; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }



	if (grid_b[0].value == 2 && grid_b[1].value == 2 && grid_b[2].value == 0) { grid_b[2].value = 1; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }
	if (grid_b[0].value == 2 && grid_b[1].value == 0 && grid_b[2].value == 2) { grid_b[1].value = 1; grid_b[1].x = 220; grid_b[1].y = 20; return 0; }
	if (grid_b[0].value == 0 && grid_b[1].value == 2 && grid_b[2].value == 2) { grid_b[0].value = 1; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[3].value == 2 && grid_b[4].value == 2 && grid_b[5].value == 0) { grid_b[5].value = 1; grid_b[5].x = 420; grid_b[5].y = 220; return 0; }
	if (grid_b[3].value == 2 && grid_b[4].value == 0 && grid_b[5].value == 2) { grid_b[4].value = 1; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[3].value == 0 && grid_b[4].value == 2 && grid_b[5].value == 2) { grid_b[3].value = 1; grid_b[3].x = 20; grid_b[3].y = 220; return 0; }

	if (grid_b[6].value == 2 && grid_b[7].value == 2 && grid_b[8].value == 0) { grid_b[8].value = 1; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[6].value == 2 && grid_b[7].value == 0 && grid_b[8].value == 2) { grid_b[7].value = 1; grid_b[7].x = 220; grid_b[7].y = 420; return 0; }
	if (grid_b[6].value == 0 && grid_b[7].value == 2 && grid_b[8].value == 2) { grid_b[6].value = 1; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }




	if (grid_b[0].value == 2 && grid_b[3].value == 2 && grid_b[6].value == 0) { grid_b[6].value = 1; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }
	if (grid_b[0].value == 2 && grid_b[3].value == 0 && grid_b[6].value == 2) { grid_b[3].value = 1; grid_b[3].x = 20; grid_b[3].y = 220; return 0; }
	if (grid_b[0].value == 0 && grid_b[3].value == 2 && grid_b[6].value == 2) { grid_b[0].value = 1; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[1].value == 2 && grid_b[4].value == 2 && grid_b[7].value == 0) { grid_b[7].value = 1; grid_b[7].x = 220; grid_b[7].y = 420; return 0; }
	if (grid_b[1].value == 2 && grid_b[4].value == 0 && grid_b[7].value == 2) { grid_b[4].value = 1; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[1].value == 0 && grid_b[4].value == 2 && grid_b[7].value == 2) { grid_b[1].value = 1; grid_b[1].x = 220; grid_b[1].y = 20; return 0; }

	if (grid_b[2].value == 2 && grid_b[5].value == 2 && grid_b[8].value == 0) { grid_b[8].value = 1; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[2].value == 2 && grid_b[5].value == 0 && grid_b[8].value == 2) { grid_b[5].value = 1; grid_b[5].x = 420; grid_b[5].y = 220; return 0; }
	if (grid_b[2].value == 0 && grid_b[5].value == 2 && grid_b[8].value == 2) { grid_b[2].value = 1; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }



	if (grid_b[0].value == 2 && grid_b[4].value == 2 && grid_b[8].value == 0) { grid_b[8].value = 1; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[0].value == 2 && grid_b[4].value == 0 && grid_b[8].value == 2) { grid_b[4].value = 1; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[0].value == 0 && grid_b[4].value == 2 && grid_b[8].value == 2) { grid_b[0].value = 1; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[2].value == 2 && grid_b[4].value == 2 && grid_b[6].value == 0) { grid_b[6].value = 1; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }
	if (grid_b[2].value == 2 && grid_b[4].value == 0 && grid_b[6].value == 2) { grid_b[4].value = 1; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[2].value == 0 && grid_b[4].value == 2 && grid_b[6].value == 2) { grid_b[2].value = 1; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }

	int i = rand() % 9;
	while (grid_b[i].value != 0) { i = rand() % 9; }

	if (i == 0) { grid_b[0].x = 20; grid_b[0].y = 20; }
	if (i == 1) { grid_b[1].x = 220; grid_b[1].y = 20; }
	if (i == 2) { grid_b[2].x = 420; grid_b[2].y = 20; }
	if (i == 3) { grid_b[3].x = 20; grid_b[3].y = 220; }
	if (i == 4) { grid_b[4].x = 220; grid_b[4].y = 220; }
	if (i == 5) { grid_b[5].x = 420; grid_b[5].y = 220; }
	if (i == 6) { grid_b[6].x = 20; grid_b[6].y = 420; }
	if (i == 7) { grid_b[7].x = 220; grid_b[7].y = 420; }
	if (i == 8) { grid_b[8].x = 420; grid_b[8].y = 420; }

	grid_b[i].value = 1;
	return 1;
}

int Bot::bot_play_o()
{
	if (grid_b[0].value == 2 && grid_b[1].value == 2 && grid_b[2].value == 0) { grid_b[2].value = 2; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }
	if (grid_b[0].value == 2 && grid_b[1].value == 0 && grid_b[2].value == 2) { grid_b[1].value = 2; grid_b[1].x = 220; grid_b[1].y = 20; return 0; }
	if (grid_b[0].value == 0 && grid_b[1].value == 2 && grid_b[2].value == 2) { grid_b[0].value = 2; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[3].value == 2 && grid_b[4].value == 2 && grid_b[5].value == 0) { grid_b[5].value = 2; grid_b[5].x = 420; grid_b[5].y = 220; return 0; }
	if (grid_b[3].value == 2 && grid_b[4].value == 0 && grid_b[5].value == 2) { grid_b[4].value = 2; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[3].value == 0 && grid_b[4].value == 2 && grid_b[5].value == 2) { grid_b[3].value = 2; grid_b[3].x = 20; grid_b[3].y = 220; return 0; }

	if (grid_b[6].value == 2 && grid_b[7].value == 2 && grid_b[8].value == 0) { grid_b[8].value = 2; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[6].value == 2 && grid_b[7].value == 0 && grid_b[8].value == 2) { grid_b[7].value = 2; grid_b[7].x = 220; grid_b[7].y = 420; return 0; }
	if (grid_b[6].value == 0 && grid_b[7].value == 2 && grid_b[8].value == 2) { grid_b[6].value = 2; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }




	if (grid_b[0].value == 2 && grid_b[3].value == 2 && grid_b[6].value == 0) { grid_b[6].value = 2; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }
	if (grid_b[0].value == 2 && grid_b[3].value == 0 && grid_b[6].value == 2) { grid_b[3].value = 2; grid_b[3].x = 20; grid_b[3].y = 220; return 0; }
	if (grid_b[0].value == 0 && grid_b[3].value == 2 && grid_b[6].value == 2) { grid_b[0].value = 2; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[1].value == 2 && grid_b[4].value == 2 && grid_b[7].value == 0) { grid_b[7].value = 2; grid_b[7].x = 220; grid_b[7].y = 420; return 0; }
	if (grid_b[1].value == 2 && grid_b[4].value == 0 && grid_b[7].value == 2) { grid_b[4].value = 2; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[1].value == 0 && grid_b[4].value == 2 && grid_b[7].value == 2) { grid_b[1].value = 2; grid_b[1].x = 220; grid_b[1].y = 20; return 0; }

	if (grid_b[2].value == 2 && grid_b[5].value == 2 && grid_b[8].value == 0) { grid_b[8].value = 2; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[2].value == 2 && grid_b[5].value == 0 && grid_b[8].value == 2) { grid_b[5].value = 2; grid_b[5].x = 420; grid_b[5].y = 220; return 0; }
	if (grid_b[2].value == 0 && grid_b[5].value == 2 && grid_b[8].value == 2) { grid_b[2].value = 2; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }



	if (grid_b[0].value == 2 && grid_b[4].value == 2 && grid_b[8].value == 0) { grid_b[8].value = 2; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[0].value == 2 && grid_b[4].value == 0 && grid_b[8].value == 2) { grid_b[4].value = 2; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[0].value == 0 && grid_b[4].value == 2 && grid_b[8].value == 2) { grid_b[0].value = 2; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[2].value == 2 && grid_b[4].value == 2 && grid_b[6].value == 0) { grid_b[6].value = 2; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }
	if (grid_b[2].value == 2 && grid_b[4].value == 0 && grid_b[6].value == 2) { grid_b[4].value = 2; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[2].value == 0 && grid_b[4].value == 2 && grid_b[6].value == 2) { grid_b[2].value = 2; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }



	if (grid_b[0].value == 1 && grid_b[1].value == 1 && grid_b[2].value == 0) { grid_b[2].value = 2; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }
	if (grid_b[0].value == 1 && grid_b[1].value == 0 && grid_b[2].value == 1) { grid_b[1].value = 2; grid_b[1].x = 220; grid_b[1].y = 20; return 0; }
	if (grid_b[0].value == 0 && grid_b[1].value == 1 && grid_b[2].value == 1) { grid_b[0].value = 2; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[3].value == 1 && grid_b[4].value == 1 && grid_b[5].value == 0) { grid_b[5].value = 2; grid_b[5].x = 420; grid_b[5].y = 220; return 0; }
	if (grid_b[3].value == 1 && grid_b[4].value == 0 && grid_b[5].value == 1) { grid_b[4].value = 2; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[3].value == 0 && grid_b[4].value == 1 && grid_b[5].value == 1) { grid_b[3].value = 2; grid_b[3].x = 20; grid_b[3].y = 220; return 0; }

	if (grid_b[6].value == 1 && grid_b[7].value == 1 && grid_b[8].value == 0) { grid_b[8].value = 2; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[6].value == 1 && grid_b[7].value == 0 && grid_b[8].value == 1) { grid_b[7].value = 2; grid_b[7].x = 220; grid_b[7].y = 420; return 0; }
	if (grid_b[6].value == 0 && grid_b[7].value == 1 && grid_b[8].value == 1) { grid_b[6].value = 2; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }




	if (grid_b[0].value == 1 && grid_b[3].value == 1 && grid_b[6].value == 0) { grid_b[6].value = 2; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }
	if (grid_b[0].value == 1 && grid_b[3].value == 0 && grid_b[6].value == 1) { grid_b[3].value = 2; grid_b[3].x = 20; grid_b[3].y = 220; return 0; }
	if (grid_b[0].value == 0 && grid_b[3].value == 1 && grid_b[6].value == 1) { grid_b[0].value = 2; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[1].value == 1 && grid_b[4].value == 1 && grid_b[7].value == 0) { grid_b[7].value = 2; grid_b[7].x = 220; grid_b[7].y = 420; return 0; }
	if (grid_b[1].value == 1 && grid_b[4].value == 0 && grid_b[7].value == 1) { grid_b[4].value = 2; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[1].value == 0 && grid_b[4].value == 1 && grid_b[7].value == 1) { grid_b[1].value = 2; grid_b[1].x = 220; grid_b[1].y = 20; return 0; }

	if (grid_b[2].value == 1 && grid_b[5].value == 1 && grid_b[8].value == 0) { grid_b[8].value = 2; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[2].value == 1 && grid_b[5].value == 0 && grid_b[8].value == 1) { grid_b[5].value = 2; grid_b[5].x = 420; grid_b[5].y = 220; return 0; }
	if (grid_b[2].value == 0 && grid_b[5].value == 1 && grid_b[8].value == 1) { grid_b[2].value = 2; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }



	if (grid_b[0].value == 1 && grid_b[4].value == 1 && grid_b[8].value == 0) { grid_b[8].value = 2; grid_b[8].x = 420; grid_b[8].y = 420; return 0; }
	if (grid_b[0].value == 1 && grid_b[4].value == 0 && grid_b[8].value == 1) { grid_b[4].value = 2; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[0].value == 0 && grid_b[4].value == 1 && grid_b[8].value == 1) { grid_b[0].value = 2; grid_b[0].x = 20; grid_b[0].y = 20; return 0; }

	if (grid_b[2].value == 1 && grid_b[4].value == 1 && grid_b[6].value == 0) { grid_b[6].value = 2; grid_b[6].x = 20; grid_b[6].y = 420; return 0; }
	if (grid_b[2].value == 1 && grid_b[4].value == 0 && grid_b[6].value == 1) { grid_b[4].value = 2; grid_b[4].x = 220; grid_b[4].y = 220; return 0; }
	if (grid_b[2].value == 0 && grid_b[4].value == 1 && grid_b[6].value == 1) { grid_b[2].value = 2; grid_b[2].x = 420; grid_b[2].y = 20; return 0; }

	int i = rand() % 9;
	while (grid_b[i].value != 0) { i = rand() % 9; }

	if (i == 0) { grid_b[0].x = 20; grid_b[0].y = 20; }
	if (i == 1) { grid_b[1].x = 220; grid_b[1].y = 20; }
	if (i == 2) { grid_b[2].x = 420; grid_b[2].y = 20; }
	if (i == 3) { grid_b[3].x = 20; grid_b[3].y = 220; }
	if (i == 4) { grid_b[4].x = 220; grid_b[4].y = 220; }
	if (i == 5) { grid_b[5].x = 420; grid_b[5].y = 220; }
	if (i == 6) { grid_b[6].x = 20; grid_b[6].y = 420; }
	if (i == 7) { grid_b[7].x = 220; grid_b[7].y = 420; }
	if (i == 8) { grid_b[8].x = 420; grid_b[8].y = 420; }

	grid_b[i].value = 2;
	return 1;
}

GridItem* Bot::getarray()
{
	return grid_b;
}