#ifndef SDLUTIL_H
#define SDLUTIL_H

#include "initError.hpp"
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
                  Uint32 windowFlags = 0) throw (error::InitError);

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
