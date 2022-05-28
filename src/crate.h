#ifndef CRATE_H
#define CRATE_H

#include <SDL2/SDL.h>
#include <assert.h>

#include "entity.h"

#define MAX_CRATES 10
#define CRATE_GAP 100
#define CRATE_Y 800

void create_crates(SDL_Renderer *renderer, int startx);
void render_crates(SDL_Renderer *renderer);

#endif
