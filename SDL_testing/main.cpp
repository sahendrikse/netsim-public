/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "engine.h"


Engine* engine = nullptr;


int main(int argc, char* args[])
{
	engine = new Engine();
	engine->init("netsim-engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, true);




	while (engine->running())
	{
		engine->handleEvents();
		engine->update();
		engine->render();
	}

	engine->clear();

	return 0;
}

