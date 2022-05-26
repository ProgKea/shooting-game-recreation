#include "header.h"

int main() {
  init_sdl2();

  while (1) {
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
        break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_e)
        Guns[Pistol].angle += 0.1;
    }
    SDL_RenderClear(renderer);
    render_active_gun();
    render_entity_rect(Guns[active_gun], renderer);
    SDL_SetRenderDrawColor(renderer, 28, 28, 28, 255);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(renderer);
  return 0;
}
