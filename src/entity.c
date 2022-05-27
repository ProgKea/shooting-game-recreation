#include "entity.h"

void render_entity_texture(Entity entity, SDL_Renderer *renderer) {
  SDL_Point center;
  center.x = entity.rect.w / 2;
  center.y = entity.rect.h / 2;

  if (entity.texture != NULL)
    SDL_RenderCopyEx(renderer, entity.texture, NULL, &entity.rect, entity.angle,
                     &center, SDL_FLIP_NONE);
}

void render_entity_rect(Entity entity, SDL_Renderer *renderer) {
  SDL_RenderDrawRect(renderer, &entity.rect);
}

void entity_create_texture(Entity *entity, const char *image_path,
                           SDL_Renderer *renderer) {
  SDL_Surface *img_surface = IMG_Load(image_path);
  if (!img_surface)
    fprintf(stderr, "Failed to create surface.\n");

  entity->texture = SDL_CreateTextureFromSurface(renderer, img_surface);
  SDL_FreeSurface(img_surface);
}

void destroy_entity(Entity *entity) { SDL_DestroyTexture(entity->texture); }
