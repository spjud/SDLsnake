#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "board.h"
#include "drawline.h"

  SDL_Rect board_data[] = {
  {
  .x = 400,
  .y = 200,
  .w = 20,
  .h = 20
  }
  };
  SDL_Rect board_data2[] = {
  {
    .x = 420,
    .y = 200,
    .w = 20,
    .h = 20
  }
  };

void drawborder(SDL_Surface* surface){
// upper border
  draw_line(surface, 400,199, 1200, 199, 0xffa550);
  draw_line(surface, 400,198, 1200, 198, 0xffa500);
  draw_line(surface, 400,197, 1200, 197, 0xffa500);
  draw_line(surface, 400,196, 1200, 196 , 0xffa500);
//lower border
draw_line(surface, 400,600, 1200, 600, 0xffa550);
draw_line(surface, 400,601, 1200, 601, 0xffa500);
draw_line(surface, 400,602, 1200, 602, 0xffa500);
draw_line(surface, 400,603, 1200, 603 , 0xffa500);
//sides
draw_line(surface, 400,200, 1200, 200, 0xffa550);
draw_line(surface, 399,200, 1199, 200, 0xffa500);
draw_line(surface, 398,200, 1198, 200, 0xffa500);
draw_line(surface, 397,200, 1197, 200 , 0xffa500);
}

void drawboard(SDL_Surface* surface, SDL_Rect* Rect, SDL_Rect* Rect2){
  drawborder(surface);
  int x = Rect->x;
  int y = Rect2->x;
  for (int j = 0; j < 20; j++) {
  for (int i = 0; i < 20 ; i++) {
  SDL_FillRect(surface, Rect, 0xFFFFFF);
  SDL_FillRect(surface, Rect2, 0xA9A9A9);
    Rect->x += 40;
    Rect2->x += 40;
  }
  Rect->y += 20;
  Rect2->y += 20;

  if(j % 2 == 0){
      Rect->x = y;
      Rect2->x = x;
      } else {
    Rect->x = x;
    Rect2->x = y;
    }
  }

}
