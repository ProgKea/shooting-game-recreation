#include "header.h"

int MouseX, MouseY;

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
        change_active_gun(Sniper);
      if (e.type == SDL_MOUSEMOTION) {
        SDL_GetMouseState(&MouseX, &MouseY);
        aim_gun_pos(MouseX, MouseY, &Guns[active_gun]);
      }
      if (e.type == SDL_MOUSEBUTTONDOWN)
        shoot_gun();
    }
    SDL_RenderClear(renderer);

    render_active_gun();

    SDL_SetRenderDrawColor(renderer, 28, 28, 28, 255);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(renderer);
  destroy_guns();
  return 0;
}
