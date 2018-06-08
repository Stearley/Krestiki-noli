#pragma once

#include "window.h"
#include <string>
#include "Grid.h"
#include "Bot.h"
#include <SDL_ttf.h>

class elements : public window
{
public:
	elements(const window & window, Grid & grid, Bot & bot);
	~elements();
	int Xc = 0;
	int Oc = 0;
	void draw();
	void draw_pve();
	void _switch();
	void pve_pollevents_x(SDL_Event &event);
	void pve_pollevents_o(SDL_Event &event);
	void pollevents(SDL_Event &event);
	int _x, _y;

private:
	SDL_Texture *_xotex1 = nullptr;
	SDL_Texture *_xotex2 = nullptr;
	SDL_Texture *_tex = nullptr;
	SDL_Surface *_xosurf1 = nullptr;
	SDL_Surface *_xosurf2 = nullptr;
	TTF_Font *font = nullptr;
	SDL_Surface* text_surface[11];
	SDL_Texture* text_texture[11];
	Grid grid;
	Bot bot;
};

