#ifndef SDLDISPLAY_H
#define SDLDISPLAY_H

#include "SDL.h"

namespace sdl
{
     class Display
     {
     public:
          Display() noexcept(false);

          int w() { return display.w; };
          int h() { return display.h; };

          const SDL_DisplayMode* handle();

     private:
          SDL_DisplayMode display;
     };
}

#endif
