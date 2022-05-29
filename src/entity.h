#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>

typedef struct Entity {
  SDL_Texture *texture;
  double angle;
  SDL_Rect rect;
  Mix_Chunk *sound;
  int speed;
  float vel_y;
  bool active;
} Entity;

void render_entity_texture(Entity entity, SDL_Renderer *renderer);
void render_entity_rect(Entity entity, SDL_Renderer *renderer);
void entity_create_texture(Entity *entity, const char *image_path,
                           SDL_Renderer *renderer);
void destroy_entity(Entity *entity);

#endif
