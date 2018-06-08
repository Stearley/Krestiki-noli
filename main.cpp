#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "elements.h"
#include "Grid.h"
#include <SDL_ttf.h>

void GameWindowEventHadler(window &window, elements &elements)
{
	SDL_Event game_event;
	if (SDL_PollEvent(&game_event))
	{
		elements.pollevents(game_event);
		window.pollevents(game_event);
	}
}

void GameBot_x_EventHadler(window &window, elements &elements)
{
	SDL_Event game_event;
	if (SDL_PollEvent(&game_event))
	{
		elements.pve_pollevents_x(game_event);
		window.pollevents(game_event);
	}
}

void GameBot_o_EventHadler(window &window, elements &elements)
{
	SDL_Event game_event;
	if (SDL_PollEvent(&game_event))
	{
		elements.pve_pollevents_o(game_event);
		window.pollevents(game_event);
	}
}

int main(int argc, char**argv)
{
	Grid grid;
	Bot bot;
	window window(800, 600);
	elements elements(window, grid, bot);

	while (!window.isclosed())
	{
		if (window.state == 0)
		{
			while (window.state == 0)
			{
				bot.restart();
				grid.restart();
				window.draw_menu_background();
				window.menu_pollevents();
			}
		}

		if (window.state == 1)
		{
			while (window.state == 1)
			{
				elements.draw();
				GameWindowEventHadler(window, elements);
				window.draw_grid_background();
				grid.GameOver();
				if (elements.Xc == 10 && elements.Oc != 10) { grid.restart(); window.state = 2; }
				if (elements.Oc == 10 && elements.Xc != 10) { grid.restart(); window.state = 3; }
				if (elements.Oc == 10 && elements.Xc == 10) { grid.restart(); window.state = 7; }
				if (window.restart)
				{
					grid.restart();
					window.restart = false;
				}
			}
		}

		if (window.state == 2)
		{
			while (window.state == 2)
			{
				window.draw_X_win_background();
				window.X_win_pollevents();
			}
		}

		if (window.state == 3)
		{
			while (window.state == 3)
			{
				window.draw_O_win_background();
				window.O_win_pollevents();
			}
		}

		if (window.state == 7)
		{
			while (window.state == 7)
			{
				window.draw_Draw_background();
				window.Draw_pollevents();
			}
		}

		if (window.state == 8)
		{
			while (window.state == 8)
			{
				window.draw_rules_background();
				window.rules_events();
			}
		}

		if (window.state == 4)
		{
			while (window.state == 4)
			{
				window.draw_choise_background();
				window.choise_pollevents();
			}
		}

		if (window.state == 5)
		{
			while (window.state == 5)
			{
				bot.bot_turn = 1;
				bot.hum_turn = 2;
				elements.draw_pve();
				GameBot_x_EventHadler(window, elements);
				window.draw_grid_background();
				bot.GameOver();
				if (elements.Xc == 10 && elements.Oc != 10) { grid.restart(); window.state = 11; }
				if (elements.Oc == 10 && elements.Xc != 10) { grid.restart(); window.state = 12; }
				if (elements.Oc == 10 && elements.Xc == 10) { grid.restart(); window.state = 13; }
				if (window.restart)
				{
					bot.restart();
					window.restart = false;
				}
			}
		}

		if (window.state == 6)
		{
			while (window.state == 6)
			{
				bot.bot_turn = 1;
				bot.hum_turn = 2;
				elements.draw_pve();
				GameBot_o_EventHadler(window, elements);
				window.draw_grid_background();
				bot.GameOver();
				if (elements.Xc == 10 && elements.Oc != 10) { grid.restart(); window.state = 14; }
				if (elements.Oc == 10 && elements.Xc != 10) { grid.restart(); window.state = 15; }
				if (elements.Oc == 10 && elements.Xc == 10) { grid.restart(); window.state = 16; }
				if (window.restart)
				{
					bot.restart();
					window.restart = false;
				}
			}
		}

		if (window.state == 11)
		{
			while (window.state == 11)
			{
				window.draw_X_win_background();
				window.X_win_pveX();
			}
		}

		if (window.state == 12)
		{
			while (window.state == 12)
			{
				window.draw_O_win_background();
				window.O_win_pveX();
			}
		}

		if (window.state == 13)
		{
			while (window.state == 13)
			{
				window.draw_Draw_background();
				window.draw_pveX();
			}
		}

		if (window.state == 14)
		{
			while (window.state == 14)
			{
				window.draw_X_win_background();
				window.X_win_pveO();
			}
		}

		if (window.state == 15)
		{
			while (window.state == 15)
			{
				window.draw_O_win_background();
				window.O_win_pveO();
			}
		}

		if (window.state == 16)
		{
			while (window.state == 16)
			{
				window.draw_Draw_background();
				window.draw_pveO();
			}
		}

		if (window.state == 66)
		{
			break;
		}
		window.isclosed();
	}
	return 0;
}