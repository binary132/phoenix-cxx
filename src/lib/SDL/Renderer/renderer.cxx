#include <sstream>

#include "SDL.h"

#include "initError.hpp"
#include "renderer.hpp"

using namespace sdl;

Renderer::Renderer(SDL_Window* win, Uint32 flags) noexcept(false)
{
     renderer = SDL_CreateRenderer(win, -1, flags);
     if (renderer == NULL) {
          std::stringstream ss;
          ss << "SDL_CreateRenderer failed: " << SDL_GetError();
          throw error::InitError(ss);
     }
}

SDL_Renderer* Renderer::handle()
{
     return renderer;
}

Renderer::~Renderer()
{
     SDL_DestroyRenderer(renderer);
}
