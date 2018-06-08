#pragma once
#include <SDL.h>
#include <string>

class window
{
public:
	window(int width, int height);
	~window();

	int state = 0;
	bool restart = false;
	void pollevents(SDL_Event &event);
	void menu_pollevents();
	void X_win_pollevents();
	void O_win_pollevents();
	void X_win_pveX();
	void O_win_pveX();
	void draw_pveX();
	void X_win_pveO();
	void O_win_pveO();
	void draw_pveO();
	void rules_events();
	void Draw_pollevents();
	void choise_pollevents();
	void draw_grid_background();
	void draw_menu_background();
	void draw_X_win_background();
	void draw_O_win_background();
	void draw_Draw_background();
	void draw_choise_background();
	void draw_rules_background();
	inline bool isclosed() const { return _closed; }
	SDL_Renderer *_renderer = nullptr;
	bool _closed = false;

private:
	bool init();
	std::string _title = "tic-tac-toe";
	int _width = 800;
	int _height = 600;
	SDL_Window *_window = nullptr;
	SDL_Texture *grid_texture = nullptr;
	SDL_Surface *grid_surface = nullptr;
	SDL_Texture *menu_texture = nullptr;
	SDL_Surface *menu_surface = nullptr;
	SDL_Texture *Draw_texture = nullptr;
	SDL_Surface *Draw_surface = nullptr;
	SDL_Texture *X_win_texture = nullptr;
	SDL_Surface *X_win_surface = nullptr;
	SDL_Texture *O_win_texture = nullptr;
	SDL_Surface *O_win_surface = nullptr;
	SDL_Texture *choise_texture = nullptr;
	SDL_Surface *choise_surface = nullptr;
	SDL_Texture *rules_texture = nullptr;
	SDL_Surface *rules_surface = nullptr;
};
