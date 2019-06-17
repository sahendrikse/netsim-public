#include "engine.h"
#include <iostream>

SDL_Texture* gTex;

Engine::Engine() 
{}

Engine::~Engine()
{}

void Engine::init( const char* title, int xpos, int ypos, int width, int height, bool fullscreen )
{
	//Initial window flags
	int flags = 0;

	if ( fullscreen )
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}


	//Initialise SDL
	if ( SDL_Init( SDL_INIT_EVERYTHING ) == 0 )
	{
		//Create window
		window = SDL_CreateWindow( title, xpos, ypos, width, height, flags );

		if (window) 
		{
			printf( "Window loaded successfully!\n" );
		}
		
		//Create renderer
		renderer = SDL_CreateRenderer( window, -1, 0 );

		if (renderer)
		{
			SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
			printf("Renderer loaded successfully!\n");
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	SDL_Surface* gSurface = IMG_Load("C:\Users\stehe\Desktop\key.png");
	gTex = SDL_CreateTextureFromSurface(renderer, gSurface);

	SDL_FreeSurface(gSurface);


}

void Engine::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent( &event );

	switch ( event.type )
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

}

void Engine::update()
{
	cnt++;
	std::cout << cnt << std::endl;;
}

void Engine::render()
{
	SDL_RenderClear( renderer );
	SDL_RenderCopy(renderer, gTex, NULL, NULL);
	SDL_RenderPresent( renderer );

}

void Engine::clear()
{
	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( renderer );
	SDL_Quit();
	printf( "Engine cleared successfully!\n" );

}

