#ifndef GUNS_H
#define GUNS_H

#include <math.h>

#include "entity.h"

#define GUN_AMOUNT 2

enum Guns {
  Pistol = 0,
  Shotgun = 1,
};

extern Entity Guns[GUN_AMOUNT];
extern unsigned int active_gun;

void init_guns();
void change_active_gun(unsigned int gun);
void render_active_gun();
void aim_gun_pos(double x, double y, Entity *Gun);
void shoot_gun();
void destroy_guns();

#endif 
