#include "crate.h"

Entity Crates[MAX_CRATES];

const float GRAVITY = 0.10f;
float jump_timer = 25.0f;
float jump_timer_current = 0.0f;

const float MIN_JUMP_TIMER = 10.0f;
float difficulty_timer = 250.0f;
float difficulty_timer_current = 0.0f;
int bounce_count = 1;

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
    int random_crate = rand_range(0, MAX_CRATES);
    if (Crates[random_crate].rect.y == CRATE_Y) {
      Crates[random_crate].vel_y = (float)rand_range(-15, -2);
    }
  }
}

void update_difficulty() {
  difficulty_timer_current += 0.1;
  if (difficulty_timer_current >= difficulty_timer && bounce_count <= MAX_CRATES) {
    bounce_count++;
    difficulty_timer_current -= difficulty_timer;
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

void render_crates(SDL_Renderer *renderer) {
  for (int i = 0; i < MAX_CRATES; i++) {
    render_entity_texture(Crates[i], renderer);
  }
}

void update_crates(SDL_Renderer *renderer) {
  apply_gravity();
  jump_timer_current += 0.1;
  // I hope I dont need delta time because of vsync
  update_difficulty();

  if (jump_timer_current >= jump_timer) {
    bounce_crates(bounce_count);
    jump_timer_current -= jump_timer;
  }

  render_crates(renderer);
}

void hit_crate(Entity *crate) {
  // TODO: increase score
  crate->rect.y = CRATE_Y;
  increase_score();
}

void destroy_crates() {
  for (int i = 0; i < MAX_CRATES; i++) {
    destroy_entity(&Crates[i]);
  }
}
