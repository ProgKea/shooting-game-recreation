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
      if (e.type == SDL_MOUSEMOTION) {
        SDL_GetMouseState(&MouseX, &MouseY);
        aim_gun_pos(MouseX, MouseY, &Guns[active_gun]);
      }
      if (e.type == SDL_MOUSEBUTTONDOWN) {
        shoot_gun(MouseX, MouseY, Guns[active_gun]);
      }
    }
    SDL_RenderClear(renderer);

    render_active_gun();
    render_active_bullets(renderer);

    SDL_SetRenderDrawColor(renderer, 28, 28, 28, 255);
    SDL_RenderPresent(renderer);

    update_bullet(Guns[active_gun]);
  }

  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(renderer);
  destroy_guns(MouseX, MouseY);
  return 0;
}
