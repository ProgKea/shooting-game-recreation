#include "init.h"

#define RESOLUTION 16 / 9

SDL_Window *win = NULL;
SDL_Renderer *renderer = NULL;

void init_sdl2() 
{
  if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
    fprintf(stderr, "Failed to init SDL: %s\n", SDL_GetError());
  }

  win = SDL_CreateWindow("bad game", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 900 * RESOLUTION, 900,
                         SDL_WINDOW_SHOWN);
  if (win == NULL) {
    fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
  }

  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
  }
}
