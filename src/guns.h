#ifndef GUNS_H
#define GUNS_H

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

#endif 
