#include "crate.h"

Entity Crates[MAX_CRATES];

const float GRAVITY = 0.10f;
float jump_timer = 50.0f;
float timer_current = 0.0f;

void create_crates(SDL_Renderer *renderer, int startx) {
  Entity crate;

  entity_create_texture(&crate, "assets/PNG/crate.png", renderer);
  crate.rect.w = (float)95.75f;
  crate.rect.h = (float)96.5f;
  crate.rect.y = CRATE_Y;

  crate.vel_y = 0.0f;

  int crate_x = startx;

  for (int i = 0; i < MAX_CRATES; i++) {
    crate.rect.x = crate_x;
    Crates[i] = crate;
    crate_x += CRATE_GAP;
  }
}

int rand_range(int low, int high) { return low + (rand() % (high - low)); }

void bounce_crates(int count) {
  for (int i = 0; i < count; i++) {
    Crates[rand_range(0, MAX_CRATES)].vel_y = (float)rand_range(-15, -1);
  }
}

void apply_gravity() {
  for (int i = 0; i < MAX_CRATES; i++) {
    if (!(Crates[i].rect.y > CRATE_Y)) {
      Crates[i].vel_y += GRAVITY;
      Crates[i].rect.y += Crates[i].vel_y;
    } else {
      Crates[i].rect.y = CRATE_Y;
      Crates[i].vel_y = 0;
    }
  }
}

void update_crates(SDL_Renderer *renderer) {
  apply_gravity();
  timer_current += 0.1;
  // I hope I dont need delta time because of vsync
  if (timer_current >= jump_timer) {
    bounce_crates(2);
    timer_current -= jump_timer;
  }

  for (int i = 0; i < MAX_CRATES; i++) {
    render_entity_texture(Crates[i], renderer);
  }
}

void destroy_crates() {
  for (int i = 0; i < MAX_CRATES; i++) {
    destroy_entity(&Crates[i]);
  }
}
