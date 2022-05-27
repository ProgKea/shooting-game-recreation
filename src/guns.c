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
  shotgun.rect.w = 200;
  shotgun.rect.h = 50;
  shotgun.rect.x = GUN_X;
  shotgun.rect.y = HEIGHT / 2;
  entity_create_texture(&shotgun, "assets/PNG/shotgun.png", renderer);
  Guns[1] = shotgun;

  Entity revolver;
  revolver.rect.w = 119;
  revolver.rect.h = 81;
  revolver.rect.x = GUN_X;
  revolver.rect.y = HEIGHT / 2;
  entity_create_texture(&revolver, "assets/PNG/revolver.png", renderer);
  Guns[2] = revolver;

  Entity sniper;
  sniper.rect.w = 198;
  sniper.rect.h = 75;
  sniper.rect.x = GUN_X;
  sniper.rect.y = HEIGHT / 2;
  entity_create_texture(&sniper, "assets/PNG/sniper.png", renderer);
  Guns[3] = sniper;
}

void aim_gun_pos(double x, double y, Entity *Gun) {
  double dx = x - Gun->rect.x;
  double dy = y - Gun->rect.y;
  Gun->angle = atan2(dy, dx) * 180 / M_PI;
}

void render_active_gun() { render_entity_texture(Guns[active_gun], renderer); }

void change_active_gun(unsigned int gun) { active_gun = gun; }

void shoot_gun() {
}

void destroy_guns() {
  for (int i = 0; i < GUN_AMOUNT; i++) {
    destroy_entity(&Guns[i]);
  }
}
