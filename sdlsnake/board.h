#ifndef BOARD_H_
#define BOARD_H_

#include <SDL.h>

SDL_Rect board_data[];
SDL_Rect board_data2[];
void drawborder(SDL_Surface* surface);
// void translate_coords(surface, board_data);
void drawboard(SDL_Surface* surface, SDL_Rect *Rect, SDL_Rect *Rect2);
#endif /*BOARD_H_*/
