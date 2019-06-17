/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



int main(int argc, char* args[])
{
	//Start up SDL, create window
	if (!init())
	{
		printf("Failed to initialise!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Apply image
			SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );

			//Update surface
			SDL_UpdateWindowSurface( gWindow );

			//Wait five seconds
			SDL_Delay( 5000 );
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

