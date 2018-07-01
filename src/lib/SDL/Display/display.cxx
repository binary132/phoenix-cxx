#include <sstream>

#include "SDL.h"

#include "initError.hpp"
#include "display.hpp"

using namespace sdl;

Display::Display() noexcept(false)
{
     std::stringstream ss;

     int initOk = SDL_GetCurrentDisplayMode(0, &display);
     if (initOk != 0) {
          ss << "SDL_GetCurrentDisplayMode failed with code " << initOk
             << ": " << SDL_GetError();
          throw error::InitError(ss);
     }
}
