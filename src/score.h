#ifndef SCORE_H
#define SCORE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

extern int score;

void init_score(SDL_Renderer *renderer);
void increase_score();
void render_score(SDL_Renderer *renderer, int r, int g, int b, float x, float y);

#endif
