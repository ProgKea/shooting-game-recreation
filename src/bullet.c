#include "bullet.h"

Entity Bullets[MAX_BULLETS] = {NULL};

unsigned int bullet_count = 0;

void create_new_bullet(int x, int y, Entity Gun, SDL_Renderer *renderer) {
  if (bullet_count == MAX_BULLETS)
    bullet_count = 0;
  Entity new_bullet;
  entity_create_texture(&new_bullet, "assets/PNG/small_bullet.png", renderer);

  double dx = x - Gun.rect.x;
  double dy = y - Gun.rect.y;
  new_bullet.angle = atan2(dy, dx) * 180 / M_PI;

  new_bullet.rect.w = 40;
  new_bullet.rect.h = 16;
  new_bullet.rect.x = Gun.rect.x + Gun.rect.w;
  new_bullet.rect.y = Gun.rect.y;

  new_bullet.active = true;

  Bullets[bullet_count] = new_bullet;
  bullet_count++;
}

void render_active_bullets(SDL_Renderer *renderer) {
  for (int i = 0; i < MAX_BULLETS; i++) {
    render_entity_texture(Bullets[i], renderer);
  }
}

void update_bullet(Entity Gun, int x, int y) {
  for (int i = 0; i < MAX_BULLETS; i++) {
    if (Bullets[i].active) {
      Bullets[i].rect.x += Gun.speed * (cos(atan2(y, x)));
      Bullets[i].rect.y += Gun.speed * (sin(atan2(y, x)));
    }
  }
}
