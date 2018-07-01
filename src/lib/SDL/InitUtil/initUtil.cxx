#include <sstream>

#include "SDL.h"

#include "initError.hpp"
#include "initUtil.hpp"

using namespace sdl;

InitUtil::InitUtil(Uint32 flags) noexcept(false)
{
     if (int initOk = SDL_Init(flags) != 0) {
          std::stringstream ss;
          ss << "SDL_Init failed with code " << initOk
             << ": " << SDL_GetError();
          throw error::InitError(ss);
     }
}

InitUtil::~InitUtil()
{
     SDL_Quit();
}
