#ifndef SDLRENDERER_H
#define SDLRENDERER_H

#include "SDL.h"

namespace sdl
{
     class Renderer
     {
     public:
          Renderer(SDL_Window*, Uint32 flags = 0) noexcept(false);

          SDL_Renderer* handle();

          ~Renderer();

     private:
          SDL_Renderer* renderer;
     };
}

#endif
