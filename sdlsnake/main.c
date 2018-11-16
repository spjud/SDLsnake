#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "board.h"



/* Two macro's that find the lesser or greater of two values */

#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)

/*
 * Clear the surface by filling it with 0x00000000(black).
 */
void clear_screen(SDL_Surface *surface)
{
		if(SDL_FillRect(surface, NULL, 0x00000000) < 0){
				fprintf(stderr, "Unable to clear the surface. Error returned: %s\n", SDL_GetError());
				SDL_Quit();
				exit(EXIT_FAILURE);
		}
}


void setboard(SDL_Window *window)
{
	int done = 0;
	SDL_Event event;
	SDL_Surface *surface;
	surface = SDL_GetWindowSurface(window);


	drawboard(surface, board_data, board_data2);
while(!done){

		 // clear_screen(surface);
		 SDL_UpdateWindowSurface(window);
					 while(SDL_PollEvent(&event)) {
						switch (event.type) {
							case SDL_QUIT:
							done = 1;
							break;
							case SDL_WINDOWEVENT:
							if (event.window.event == SDL_WINDOWEVENT_SHOWN) {
							SDL_SetWindowPosition(window, 50, 50);
							break;
							 }
						 }
					 }


				 }

}



int main(void)
{
		const size_t bufsize = 100;

		/* Change the screen width and height to your own liking */
		const int screen_w = 1600;
		const int screen_h = 900;

		char errmsg[bufsize];
		SDL_Window *window;

		/* Initialize SDL */
		if (SDL_Init(SDL_INIT_VIDEO) < -1) {
				snprintf(errmsg, bufsize, "Unable to initialize SDL.");
				goto error;
		}

		/* Create a 1600x900 window */
		window = SDL_CreateWindow("yeet",
															SDL_WINDOWPOS_UNDEFINED,
															SDL_WINDOWPOS_UNDEFINED,
															screen_w, screen_h,
															0);

								if (!window) {
				snprintf(errmsg, bufsize, "Unable to get video surface.");
				goto error;
		}

		/* Start bouncing some objects */
		setboard(window);

		/* Shut down SDL */
		SDL_Quit();

		/* Wait a little bit jic something went wrong (so that printfs can be read) */
		SDL_Delay(5000);

		return 0;

		/* Upon an error, print message and quit properly */
error:
		fprintf(stderr, "%s Error returned: %s\n", errmsg, SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
}
