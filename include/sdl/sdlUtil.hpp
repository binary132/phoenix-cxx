#ifndef SDLUTIL_H
#define SDLUTIL_H

#include <string>

#include "initUtil.hpp"
#include "initVideo.hpp"
#include "display.hpp"
#include "window.hpp"

namespace sdl
{
     class SDLUtil
     {
     public:
          SDLUtil(const std::string& titleIn = "Phoenix App",
                  Uint32 windowFlags = 0,
	          Uint32 SDLSubsystems = SDL_INIT_VIDEO | SDL_INIT_AUDIO
	  ) noexcept(false);

          int w() { return display.w(); }
          int h() { return display.h(); }

          Window& windowHandle() { return window; }

          const std::string title;

     private:
          InitUtil initUtil;
          InitVideo initVideo;
          Display display;
          Window window;
     };
}

#endif
