#include "Grid.h"
#include <SDL.h>
#include <iostream>

GridItem grid[9];

int Xcount = 0;
int Ycount = 0;

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::init()
{
	for (int i = 0; i < 9; i++)
	{
		grid[i].x = 0;
		grid[i].y = 0;
		grid[i].value = 0;
	}
}

bool Grid::check(int i)
{
	if (grid[i].value == 0) return true;
	else return false;
}

void Grid::setX(int i, int x, int y)
{
	grid[i].value = 1;
	grid[i].x = x;
	grid[i].y = y;
}

void Grid::setO(int i, int x, int y)
{
	grid[i].value = 2;
	grid[i].x = x;
	grid[i].y = y;
}

GridItem* Grid::getarray()
{
	return grid;
}

void Grid::clerGrid()
{
	for (int i = 0; i < 9; i++)
	{
		grid[i].value = 0;
	}
}

int Grid::GameOver()
{
	if (
		(grid[0].value == 1 && grid[1].value == 1 && grid[2].value == 1) ||
		(grid[3].value == 1 && grid[4].value == 1 && grid[5].value == 1) ||
		(grid[6].value == 1 && grid[7].value == 1 && grid[8].value == 1) ||

		(grid[0].value == 1 && grid[3].value == 1 && grid[6].value == 1) ||
		(grid[1].value == 1 && grid[4].value == 1 && grid[7].value == 1) ||
		(grid[2].value == 1 && grid[5].value == 1 && grid[8].value == 1) ||

		(grid[0].value == 1 && grid[4].value == 1 && grid[8].value == 1) ||
		(grid[2].value == 1 && grid[4].value == 1 && grid[6].value == 1)
		)
	{
		Xcount++; clerGrid();
		return 1;
	}

	if (
		(grid[0].value == 2 && grid[1].value == 2 && grid[2].value == 2) ||
		(grid[3].value == 2 && grid[4].value == 2 && grid[5].value == 2) ||
		(grid[6].value == 2 && grid[7].value == 2 && grid[8].value == 2) ||

		(grid[0].value == 2 && grid[3].value == 2 && grid[6].value == 2) ||
		(grid[1].value == 2 && grid[4].value == 2 && grid[7].value == 2) ||
		(grid[2].value == 2 && grid[5].value == 2 && grid[8].value == 2) ||

		(grid[0].value == 2 && grid[4].value == 2 && grid[8].value == 2) ||
		(grid[2].value == 2 && grid[4].value == 2 && grid[6].value == 2)
		)
	{
		Ycount++; clerGrid();
		return 2;
	}

	int j = 0;
	for (int i = 0; i < 9; i++)
	{
		if (grid[i].value != 0) j++;
	}
	if (j == 9) {
		Ycount++; Xcount++;  clerGrid();
		return 3;
	}
	if (Xcount == 10 || Ycount == 10) { Xcount = Ycount = 0; }
	return 0;
}

int Grid::getXcount()
{
	return Xcount;
}

int Grid::getOcount()
{
	return Ycount;
}

void Grid::restart()
{
	clerGrid();
	Xcount = 0;
	Ycount = 0;
}