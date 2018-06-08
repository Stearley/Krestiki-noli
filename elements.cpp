#include "elements.h"
#include "Grid.h"
#include "GridItem.h"
#include <SDL_image.h>
#include <iostream>
#include <string>

elements::elements(const window & window, Grid & grid, Bot & bot)
	: window(window), grid(grid), bot(bot)
{
	_xosurf1 = IMG_Load("res/1.png");
	_xosurf2 = IMG_Load("res/2.png");
	if (_xosurf1 == nullptr || _xosurf2 == nullptr)
	{
		std::cout << "Failed to create surf.\n";
	}

	_xotex1 = SDL_CreateTextureFromSurface(_renderer, _xosurf1);
	_xotex2 = SDL_CreateTextureFromSurface(_renderer, _xosurf2);
	if (_xotex1 == nullptr || _xotex2 == nullptr)
	{
		std::cout << "Failed to create texture.\n";
	}

	SDL_FreeSurface(_xosurf1);
	SDL_FreeSurface(_xosurf2);

	font = TTF_OpenFont("res/4.ttf", 200);
	if (!font)
	{
		std::cerr << "Failed to load font\n";
	}

	text_surface[0] = TTF_RenderText_Solid(font, "0", { 0, 0, 0, 255 });
	text_surface[1] = TTF_RenderText_Solid(font, "1", { 0, 0, 0, 255 });
	text_surface[2] = TTF_RenderText_Solid(font, "2", { 0, 0, 0, 255 });
	text_surface[3] = TTF_RenderText_Solid(font, "3", { 0, 0, 0, 255 });
	text_surface[4] = TTF_RenderText_Solid(font, "4", { 0, 0, 0, 255 });
	text_surface[5] = TTF_RenderText_Solid(font, "5", { 0, 0, 0, 255 });
	text_surface[6] = TTF_RenderText_Solid(font, "6", { 0, 0, 0, 255 });
	text_surface[7] = TTF_RenderText_Solid(font, "7", { 0, 0, 0, 255 });
	text_surface[8] = TTF_RenderText_Solid(font, "8", { 0, 0, 0, 255 });
	text_surface[9] = TTF_RenderText_Solid(font, "9", { 0, 0, 0, 255 });
	text_surface[10] = TTF_RenderText_Solid(font, "10", { 0, 0, 0, 255 });
	for (int i = 0; i < 11; i++)
	{
		if (!text_surface[i])
		{
			std::cerr << "Failed to create text surface\n";
		}
	}

	for (int i = 0; i < 11; i++)
	{
		text_texture[i] = SDL_CreateTextureFromSurface(_renderer, text_surface[i]);
	}
	for (int i = 0; i < 11; i++)
	{
		if (!text_texture[i])
		{
			std::cerr << "Failed to create text texture\n";
		}
	}

	for (int i = 0; i < 11; i++)
	{
		SDL_FreeSurface(text_surface[i]);
	}

}

elements::~elements()
{
	SDL_DestroyTexture(_xotex1);
	SDL_DestroyTexture(_xotex2);
	for (int i = 0; i < 11; i++)
	{
		SDL_DestroyTexture(text_texture[i]);
	}
}

void elements::draw()
{
	GridItem *ngrid = grid.getarray();
	Xc = grid.getXcount();
	Oc = grid.getOcount();

	for (int i = 0; i < 9; i++)
	{
		if (ngrid[i].value != 0)
		{
			int x = ngrid[i].x;
			int y = ngrid[i].y;
			if (ngrid[i].value == 1) { _tex = _xotex1; }
			else
				if (ngrid[i].value == 2) { _tex = _xotex2; }
				else { _tex = nullptr; }
				SDL_Rect rect = { x, y, 160, 160 };
				SDL_RenderCopy(_renderer, _tex, NULL, &rect);
		}
		SDL_Rect Xcount_rect = { 600, 0, 200, 100 };
		SDL_Rect Ocount_rect = { 600, 100, 200, 100 };
		SDL_RenderCopy(_renderer, text_texture[Xc], NULL, &Xcount_rect);
		SDL_RenderCopy(_renderer, text_texture[Oc], NULL, &Ocount_rect);
	}
}

int currplayer = 1;

void elements::pollevents(SDL_Event &event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_KP_7:
			if (grid.check(0)) {
				if (currplayer == 1) { grid.setX(0, 20, 20); _switch(); }
				else { grid.setO(0, 20, 20); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_8:
			if (grid.check(1)) {
				if (currplayer == 1) { grid.setX(1, 220, 20); _switch(); }
				else { grid.setO(1, 220, 20); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_9:
			if (grid.check(2)) {
				if (currplayer == 1) { grid.setX(2, 420, 20); _switch(); }
				else { grid.setO(2, 420, 20); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_4:
			if (grid.check(3)) {
				if (currplayer == 1) { grid.setX(3, 20, 220); _switch(); }
				else { grid.setO(3, 20, 220); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_5:
			if (grid.check(4)) {
				if (currplayer == 1) { grid.setX(4, 220, 220); _switch(); }
				else { grid.setO(4, 220, 220); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_6:
			if (grid.check(5)) {
				if (currplayer == 1) { grid.setX(5, 420, 220); _switch(); }
				else { grid.setO(5, 420, 220); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_1:
			if (grid.check(6)) {
				if (currplayer == 1) { grid.setX(6, 20, 420); _switch(); }
				else { grid.setO(6, 20, 420); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_2:
			if (grid.check(7)) {
				if (currplayer == 1) { grid.setX(7, 220, 420); _switch(); }
				else { grid.setO(7, 220, 420); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_3:
			if (grid.check(8)) {
				if (currplayer == 1) { grid.setX(8, 420, 420); _switch(); }
				else { grid.setO(8, 420, 420); _switch(); }
			}
			else break;
			break;


		case SDLK_ESCAPE:
			_closed = true; break;

		default: break;
		}
	}

	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.x < 600)
		{
			int x = (event.button.x / 200);
			int y = (event.button.y / 200);

			if (grid.check(x + 3 * y)) {
				if (currplayer == 1) { grid.setX(x + 3 * y, 20 + x * 200, 20 + y * 200); _switch(); }
				else { grid.setO(x + 3 * y, 20 + x * 200, 20 + y * 200); _switch(); }
			}
		}
	}
}


void elements::_switch()
{
	if (currplayer == 1)
	{
		currplayer = 2;
	}
	else currplayer = 1;
}

void elements::pve_pollevents_x(SDL_Event &event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.x < 600)
		{
			int x = (event.button.x / 200);
			int y = (event.button.y / 200);

			if (bot.check(x + 3 * y)) {
				if (currplayer == 1) { bot.bot_play_x(); _switch(); }
				else { bot.setO(x + 3 * y, 20 + x * 200, 20 + y * 200); _switch(); }
			}
		}
	}
}

void elements::draw_pve()
{
	GridItem *ngrid = bot.getarray();
	Xc = bot.getXcount();
	Oc = bot.getOcount();

	for (int i = 0; i < 9; i++)
	{
		if (ngrid[i].value != 0)
		{
			int x = ngrid[i].x;
			int y = ngrid[i].y;
			if (ngrid[i].value == 1) { _tex = _xotex1; }
			else
				if (ngrid[i].value == 2) { _tex = _xotex2; }
				else { _tex = nullptr; }
				SDL_Rect rect = { x, y, 160, 160 };
				SDL_RenderCopy(_renderer, _tex, NULL, &rect);
		}
		SDL_Rect Xcount_rect = { 600, 0, 200, 100 };
		SDL_Rect Ocount_rect = { 600, 100, 200, 100 };
		SDL_RenderCopy(_renderer, text_texture[Xc], NULL, &Xcount_rect);
		SDL_RenderCopy(_renderer, text_texture[Oc], NULL, &Ocount_rect);
	}
}

void elements::pve_pollevents_o(SDL_Event &event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.x < 600)
		{
			int x = (event.button.x / 200);
			int y = (event.button.y / 200);

			if (bot.check(x + 3 * y)) {
				if (currplayer == 1) { bot.setX(x + 3 * y, 20 + x * 200, 20 + y * 200); _switch(); }
				else { bot.bot_play_o(); _switch(); }
			}
		}
	}
}