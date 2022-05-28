#include "crate.h"

Entity Crates[MAX_CRATES];

void create_crates(SDL_Renderer *renderer, int startx) {
  Entity crate;

  entity_create_texture(&crate, "assets/PNG/crate.png", renderer);
  crate.rect.w = (float)95.75;
  crate.rect.h = (float)96.5;
  crate.rect.y = CRATE_Y;

  int crate_x = startx;

  for (int i = 0; i < MAX_CRATES; i++) {
    crate.rect.x = crate_x;
    Crates[i] = crate;
    crate_x += CRATE_GAP;
  }
}

void bounce_crates(int count) {
  assert(count <= MAX_CRATES);
  // TODO: if this function is called make x amount of crates jump
}

void render_crates(SDL_Renderer *renderer) {
  for (int i = 0; i < MAX_CRATES; i++) {
    render_entity_texture(Crates[i], renderer);
  }
}
