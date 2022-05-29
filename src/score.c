#include "score.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

int score = 0;
SDL_Surface *score_surface;
SDL_Texture *score_texture;
int tex_w = 0;
int tex_h = 0;
TTF_Font *font;
SDL_Rect font_rect;

void increase_score() { score += 1; }

void init_score(SDL_Renderer *renderer) {
  if (TTF_Init() != 0)
    fprintf(stderr, "Failed to init SDL_ttf: %s\n", SDL_GetError());
  font = NULL;
  font = TTF_OpenFont("assets/fonts/Robot.ttf", 100);
  if (font == NULL) {
    fprintf(stderr, "Failed to load Font: %s\n", SDL_GetError());
  }
}

// there is probably a better way to do this
void render_score(SDL_Renderer *renderer, int r, int g, int b, float x,
                  float y) {
  char score_char[5];
  sprintf(score_char, "%d", score);

  score_surface =
      TTF_RenderText_Solid(font, score_char, (SDL_Color){r, g, b, 255});
  score_texture = SDL_CreateTextureFromSurface(renderer, score_surface);

  SDL_QueryTexture(score_texture, NULL, NULL, &tex_w, &tex_h);
  font_rect =
      (SDL_Rect){x - (float)tex_w / 2, y - (float)tex_h / 2, tex_w, tex_h};

  SDL_RenderCopy(renderer, score_texture, NULL, &font_rect);

  SDL_FreeSurface(score_surface);
  SDL_DestroyTexture(score_texture);
}

void destroy_font() {
  TTF_CloseFont(font);

  SDL_FreeSurface(score_surface);
  SDL_DestroyTexture(score_texture);
}
