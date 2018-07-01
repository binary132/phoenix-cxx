#include <string>
#include <sstream>

#include "SDL.h"

#include "sdlUtil.hpp"
#include "initError.hpp"
#include "display.hpp"

using namespace sdl;

SDLUtil::SDLUtil(const std::string& titleIn, Uint32 windowFlags) noexcept(false) :
     title(titleIn),
     window(title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            display.w(), display.h(),
            windowFlags)
{
     window.show();
}
