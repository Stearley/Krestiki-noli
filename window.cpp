#include "Window.h"
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>

window::window(int width, int height) :
	_width(width), _height(height)
{
	_closed = !init();
}

window::~window()
{
	SDL_DestroyTexture(X_win_texture);
	SDL_DestroyTexture(O_win_texture);
	SDL_DestroyTexture(grid_texture);
	SDL_DestroyTexture(menu_texture);
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool window::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Failed to initialize SDL. \n";
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cerr << "Failed to initialize IMG. \n";
		return false;
	}

	if (TTF_Init() == -1)
	{

		std::cerr << "Failed to initialize TTF. \n";
		return false;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, NULL);
	if (_window == nullptr)
	{
		std::cerr << "Failed to ctreate window. \n";
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == nullptr)
	{
		std::cerr << "Failed to ctreate renderer. \n";
		return false;
	}

	grid_surface = IMG_Load("res/3.png");
	if (grid_surface == nullptr)
	{
		std::cout << "Loading error.\n";
		return false;
	}

	grid_texture = SDL_CreateTextureFromSurface(_renderer, grid_surface);
	SDL_FreeSurface(grid_surface);
	if (grid_texture == nullptr)
	{
		std::cout << "Creating error.\n";
		return false;
	}

	menu_surface = IMG_Load("res/5.png");
	if (menu_surface == nullptr)
	{
		std::cout << "Loading error.\n";
		return false;
	}

	menu_texture = SDL_CreateTextureFromSurface(_renderer, menu_surface);
	SDL_FreeSurface(menu_surface);
	if (menu_texture == nullptr)
	{
		std::cout << "Creating error.\n";
		return false;
	}

	X_win_surface = IMG_Load("res/6.png");
	if (X_win_surface == nullptr)
	{
		std::cout << "Loading error.\n";
		return false;
	}

	X_win_texture = SDL_CreateTextureFromSurface(_renderer, X_win_surface);
	SDL_FreeSurface(X_win_surface);
	if (X_win_texture == nullptr)
	{
		std::cout << "Creating error.\n";
		return false;
	}

	O_win_surface = IMG_Load("res/7.png");
	if (O_win_surface == nullptr)
	{
		std::cout << "Loading error.\n";
		return false;
	}

	O_win_texture = SDL_CreateTextureFromSurface(_renderer, O_win_surface);
	SDL_FreeSurface(O_win_surface);
	if (O_win_texture == nullptr)
	{
		std::cout << "Creating error.\n";
		return false;
	}

	Draw_surface = IMG_Load("res/9.png");
	if (Draw_surface == nullptr)
	{
		std::cout << "Loading error.\n";
		return false;
	}

	Draw_texture = SDL_CreateTextureFromSurface(_renderer, Draw_surface);
	SDL_FreeSurface(Draw_surface);
	if (Draw_texture == nullptr)
	{
		std::cout << "Creating error.\n";
		return false;
	}

	choise_surface = IMG_Load("res/8.png");
	if (choise_surface == nullptr)
	{
		std::cout << "Loading error.\n";
		return false;
	}

	choise_texture = SDL_CreateTextureFromSurface(_renderer, choise_surface);
	SDL_FreeSurface(choise_surface);
	if (choise_texture == nullptr)
	{
		std::cout << "Creating error.\n";
		return false;
	}

	rules_surface = IMG_Load("res/10.png");
	if (rules_surface == nullptr)
	{
		std::cout << "Loading error.\n";
		return false;
	}

	rules_texture = SDL_CreateTextureFromSurface(_renderer, rules_surface);
	SDL_FreeSurface(rules_surface);
	if (rules_texture == nullptr)
	{
		std::cout << "Creating error.\n";
		return false;
	}

	return true;
}

void window::draw_grid_background()
{
	SDL_RenderPresent(_renderer);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, grid_texture, NULL, NULL);
}

void window::draw_menu_background()
{
	SDL_RenderPresent(_renderer);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, menu_texture, NULL, NULL);
}

void window::draw_X_win_background()
{
	SDL_RenderPresent(_renderer);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, X_win_texture, NULL, NULL);
}

void window::draw_O_win_background()
{
	SDL_RenderPresent(_renderer);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, O_win_texture, NULL, NULL);
}

void window::draw_Draw_background()
{
	SDL_RenderPresent(_renderer);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, Draw_texture, NULL, NULL);
}

void window::draw_choise_background()
{
	SDL_RenderPresent(_renderer);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, choise_texture, NULL, NULL);
}

void window::draw_rules_background()
{
	SDL_RenderPresent(_renderer);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, rules_texture, NULL, NULL);
}

void window::pollevents(SDL_Event &event)
{
	switch (event.type)
	{
	case SDL_QUIT:
		state = 66; break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			state = 66; break;
		}
	case SDL_MOUSEBUTTONDOWN:
	{
		if (event.button.x > 600)
		{
			if (event.button.y > 460 && event.button.y < 600) state = 0;
			if (event.button.y > 320 && event.button.y < 460) { restart = true; }
		}
	}

	default: break;
	}
}

void window::menu_pollevents()
{
	SDL_Event menu_event;
	if (SDL_PollEvent(&menu_event))
	{
		switch (menu_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (menu_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (menu_event.button.x >= 110 && menu_event.button.x <= 700 && menu_event.button.y >= 290 && menu_event.button.y <= 370)
			{
				state = 1;
			}
			if (menu_event.button.x >= 110 && menu_event.button.x <= 700 && menu_event.button.y >= 190 && menu_event.button.y <= 270)
			{
				state = 4;
			}
			if (menu_event.button.x >= 110 && menu_event.button.x <= 700 && menu_event.button.y >= 390 && menu_event.button.y <= 470)
			{
				state = 8;
			}
			if (menu_event.button.x >= 110 && menu_event.button.x <= 700 && menu_event.button.y >= 490 && menu_event.button.y <= 570)
			{
				state = 66;
			}

		default: break;
		}
	}
}

void window::X_win_pollevents()
{
	SDL_Event X_win_event;
	if (SDL_PollEvent(&X_win_event))
	{
		switch (X_win_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (X_win_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (X_win_event.button.x >= 400 && X_win_event.button.x <= 800 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 1;
			}

			if (X_win_event.button.x >= 0 && X_win_event.button.x <= 400 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 0;
			}

		default: break;
		}
	}
}

void window::O_win_pollevents()
{
	SDL_Event O_win_event;
	if (SDL_PollEvent(&O_win_event))
	{
		switch (O_win_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (O_win_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (O_win_event.button.x >= 400 && O_win_event.button.x <= 800 && O_win_event.button.y >= 300 && O_win_event.button.y <= 600)
			{
				state = 1;
			}

			if (O_win_event.button.x >= 0 && O_win_event.button.x <= 400 && O_win_event.button.y >= 300 && O_win_event.button.y <= 600)
			{
				state = 0;
			}

		default: break;
		}
	}
}

void window::Draw_pollevents()
{
	SDL_Event X_win_event;
	if (SDL_PollEvent(&X_win_event))
	{
		switch (X_win_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (X_win_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (X_win_event.button.x >= 400 && X_win_event.button.x <= 800 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 1;
			}

			if (X_win_event.button.x >= 0 && X_win_event.button.x <= 400 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 0;
			}

		default: break;
		}
	}
}

void window::choise_pollevents()
{
	SDL_Event choise_event;
	if (SDL_PollEvent(&choise_event))
	{
		switch (choise_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (choise_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (choise_event.button.x >= 0 && choise_event.button.x <= 200 && choise_event.button.y >= 0 && choise_event.button.y <= 200)
			{
				state = 0;
			}

			if (choise_event.button.x >= 0 && choise_event.button.x <= 400 && choise_event.button.y >= 300 && choise_event.button.y <= 600)
			{
				state = 5;
			}

			if (choise_event.button.x >= 400 && choise_event.button.x <= 800 && choise_event.button.y >= 300 && choise_event.button.y <= 600)
			{
				state = 6;
			}

		default: break;
		}
	}
}

void window::X_win_pveX()
{
	SDL_Event X_win_event;
	if (SDL_PollEvent(&X_win_event))
	{
		switch (X_win_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (X_win_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (X_win_event.button.x >= 400 && X_win_event.button.x <= 800 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 5;
			}

			if (X_win_event.button.x >= 0 && X_win_event.button.x <= 400 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 0;
			}

		default: break;
		}
	}
}

void window::X_win_pveO()
{
	SDL_Event X_win_event;
	if (SDL_PollEvent(&X_win_event))
	{
		switch (X_win_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (X_win_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (X_win_event.button.x >= 400 && X_win_event.button.x <= 800 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 6;
			}

			if (X_win_event.button.x >= 0 && X_win_event.button.x <= 400 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 0;
			}

		default: break;
		}
	}
}

void window::O_win_pveX()
{
	SDL_Event O_win_event;
	if (SDL_PollEvent(&O_win_event))
	{
		switch (O_win_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (O_win_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (O_win_event.button.x >= 400 && O_win_event.button.x <= 800 && O_win_event.button.y >= 300 && O_win_event.button.y <= 600)
			{
				state = 5;
			}

			if (O_win_event.button.x >= 0 && O_win_event.button.x <= 400 && O_win_event.button.y >= 300 && O_win_event.button.y <= 600)
			{
				state = 0;
			}

		default: break;
		}
	}
}

void window::O_win_pveO()
{
	SDL_Event O_win_event;
	if (SDL_PollEvent(&O_win_event))
	{
		switch (O_win_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (O_win_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (O_win_event.button.x >= 400 && O_win_event.button.x <= 800 && O_win_event.button.y >= 300 && O_win_event.button.y <= 600)
			{
				state = 6;
			}

			if (O_win_event.button.x >= 0 && O_win_event.button.x <= 400 && O_win_event.button.y >= 300 && O_win_event.button.y <= 600)
			{
				state = 0;
			}

		default: break;
		}
	}
}

void window::draw_pveX()
{
	SDL_Event X_win_event;
	if (SDL_PollEvent(&X_win_event))
	{
		switch (X_win_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (X_win_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (X_win_event.button.x >= 400 && X_win_event.button.x <= 800 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 5;
			}

			if (X_win_event.button.x >= 0 && X_win_event.button.x <= 400 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 0;
			}

		default: break;
		}
	}
}

void window::draw_pveO()
{
	SDL_Event X_win_event;
	if (SDL_PollEvent(&X_win_event))
	{
		switch (X_win_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (X_win_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (X_win_event.button.x >= 400 && X_win_event.button.x <= 800 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 6;
			}

			if (X_win_event.button.x >= 0 && X_win_event.button.x <= 400 && X_win_event.button.y >= 300 && X_win_event.button.y <= 600)
			{
				state = 0;
			}

		default: break;
		}
	}
}

void window::rules_events()
{
	SDL_Event choise_event;
	if (SDL_PollEvent(&choise_event))
	{
		switch (choise_event.type)
		{
		case SDL_QUIT:
			state = 66; break;
		case SDL_KEYDOWN:
			switch (choise_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				state = 66; break;
			}
		case SDL_MOUSEBUTTONDOWN:

			if (choise_event.button.x >= 600 && choise_event.button.x <= 800 && choise_event.button.y >= 400 && choise_event.button.y <= 600)
			{
				state = 0;
			}

		default: break;
		}
	}
}