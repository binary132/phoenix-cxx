#include <sstream>

#include <glad/glad.h>

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

     context = SDL_GL_CreateContext(win);
     if (context == NULL) {
	     std::stringstream ss;
	     ss << "SDL_GL_CreateContext failed: " << SDL_GetError();
	     throw error::InitError(ss);
     }

     int gladInitRes = gladLoadGL();
     if (!gladInitRes) {
	   std::stringstream ss;
	   ss << "gladLoadGL failed: " << gladInitRes;
	   throw error::InitError(ss);
     }
}

SDL_Renderer* Renderer::handle()
{
     return renderer;
}

SDL_GLContext Renderer::gl_handle()
{
     return context;
}

Renderer::~Renderer()
{
     SDL_DestroyRenderer(renderer);
     SDL_GL_DeleteContext(context);
}
