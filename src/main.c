#include "header.h"

const int fps = 60;
const int desiredDelta = 1000 / fps;
int startLoop;

int main() {
  init_sdl2();

  while (1) {
    startLoop = SDL_GetTicks();
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
        break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_e)
        change_active_gun(Shotgun);
    }
    SDL_RenderClear(renderer);
    render_active_gun();
    render_entity_rect(Guns[active_gun], renderer);
    SDL_SetRenderDrawColor(renderer, 28, 28, 28, 255);
    SDL_RenderPresent(renderer);

    int delta = SDL_GetTicks() - startLoop;
    if (delta < desiredDelta)
      SDL_Delay(desiredDelta - delta);
  }

  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(renderer);
  return 0;
}
