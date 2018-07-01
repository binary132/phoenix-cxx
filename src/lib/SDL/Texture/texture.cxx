#include <sstream>

#include "SDL.h"

#include "initError.hpp"
#include "texture.hpp"

using namespace sdl;

Texture::Texture(SDL_Renderer* renderer,
                 int w, int h) noexcept(false)
{
     texture = SDL_CreateTexture(renderer,
                                 SDL_PIXELFORMAT_ARGB8888,
                                 SDL_TEXTUREACCESS_STREAMING,
                                 w, h);
     if (texture == NULL) {
          std::stringstream ss;
          ss << "SDL_CreateTexture failed: " << SDL_GetError();
          throw error::InitError(ss);
     }
}

void Texture::update(const SDL_Rect* rect,
                     const void*     pixels,
                     int             pitch) noexcept(false)
{
     if (int v = SDL_UpdateTexture(texture, rect, pixels, pitch) != 0) {
	  std::stringstream ss;
	  ss << "SD_UpdateTexture failed with " << v
	     << ": " << SDL_GetError();
	  throw error::InitError(ss);
     }
}

Texture::~Texture()
{
     SDL_DestroyTexture(texture);
}
