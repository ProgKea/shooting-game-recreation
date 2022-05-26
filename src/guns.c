#include "init.h"

#define GUN_X 100

Entity Guns[GUN_AMOUNT];

unsigned int active_gun = Pistol;

void init_guns() {
  Entity pistol;
  pistol.rect.w = 104;
  pistol.rect.h = 83;
  pistol.rect.x = GUN_X;
  pistol.rect.y = HEIGHT/2;
  entity_create_texture(&pistol, "assets/PNG/pistol.png", renderer);
  Guns[0] = pistol;
}

void render_active_gun() {
  render_entity_texture(Guns[active_gun], renderer);
}

void change_active_gun(unsigned int gun) {
  active_gun = gun;
}
