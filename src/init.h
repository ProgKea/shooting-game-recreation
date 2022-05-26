#ifndef INIT_H
#define INIT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "guns.h"

#define HEIGHT 900
#define WIDTH 900 * RESOLUTION

extern SDL_Window *win;
extern SDL_Renderer * renderer;

void init_sdl2();

#endif
