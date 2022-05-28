#ifndef CRATE_H
#define CRATE_H

#include <SDL2/SDL.h>
#include <assert.h>
#include <stdlib.h>

#include "entity.h"

#define MAX_CRATES 14
#define CRATE_GAP 100
#define CRATE_Y 900

void create_crates(SDL_Renderer *renderer, int startx);
void update_crates(SDL_Renderer *renderer);
void bounce_crates(int count);
void destroy_crates();

#endif
