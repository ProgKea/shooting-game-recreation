#ifndef BULLET_H
#define BULLET_H

#include <SDL2/SDL.h>
#include <math.h>

#include "entity.h"

#define MAX_BULLETS 10

extern unsigned int bullet_count;

void create_new_bullet(int x, int y, Entity Gun, SDL_Renderer *renderer);
void render_active_bullets(SDL_Renderer *renderer);
void update_bullet();

#endif
