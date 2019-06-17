#ifndef engine_h
#define engine_h

#include "SDL.h"
#include <stdio.h>

class Engine 
{
	
public:
	Engine();
	~Engine();

	//
	void init( const char* title, int xpos, int ypos, int width, int height, bool fullscreen );
	
	void handleEvents();
	void update();
	void render();
	void clear();

	bool running() { return isRunning; }

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif /* engine_h */
