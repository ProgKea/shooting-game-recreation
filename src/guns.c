#include "init.h"

#define GUN_X 100

Entity Guns[GUN_AMOUNT];

unsigned int active_gun = Pistol;

void init_guns() {
  Entity pistol;
  pistol.rect.w = 104;
  pistol.rect.h = 83;
  pistol.rect.x = GUN_X;
  pistol.rect.y = HEIGHT / 2;
  entity_create_texture(&pistol, "assets/PNG/pistol.png", renderer);
  Guns[0] = pistol;

  Entity shotgun;
  shotgun.rect.w = 403;
  shotgun.rect.h = 116;
  shotgun.rect.x = GUN_X;
  shotgun.rect.y = HEIGHT / 2;
  entity_create_texture(&shotgun, "assets/PNG/shotgun.png", renderer);
  Guns[1] = shotgun;
}

void aim_gun_pos(double x, double y, Entity *Gun) {
  double dx = x - Gun->rect.x;
  double dy = y - Gun->rect.y;
  Gun->angle = atan2(dy, dx) * 180 / M_PI;
}

void render_active_gun() { render_entity_texture(Guns[active_gun], renderer); }

void change_active_gun(unsigned int gun) { active_gun = gun; }

void shoot_gun() {
  // TODO: shoot gun at given coordinates (x, y)
  printf("TODO\n");
}

void destroy_guns() {
  for (int i = 0; i < GUN_AMOUNT; i++) {
    destroy_entity(&Guns[i]);
  }
}
