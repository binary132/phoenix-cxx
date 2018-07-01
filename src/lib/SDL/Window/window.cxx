#include <sstream>
#include <string_view>

#include "SDL.h"

#include "initError.hpp"
#include "window.hpp"

using namespace sdl;

Window::Window(const char* title,
               int x, int y,
               int w, int h,
               Uint32 flags) noexcept(false)
{
     std::stringstream ss;

     if (SDL_GetNumVideoDrivers() > 0) {
          if (int v = SDL_VideoInit(NULL) != 0) {
               ss << "SDL_VideoInit failed with code " << v
                  << ": " << SDL_GetError();
               throw error::InitError(ss);
          }
     } else {
          ss << "0 drivers found";
          throw error::InitError(ss);
     }

     if(int numDisp = SDL_GetNumVideoDisplays() < 1) {
          ss << "SDL_GetNumVideoDisplays returned " << numDisp;
          throw error::InitError(ss);
     }

     window = SDL_CreateWindow(title,
                               x, y,
                               w, h,
                               flags);

     if (window == NULL) {
          ss << "SDL_CreateWindow failed: " << SDL_GetError();
          throw error::InitError(ss);
     }
}

SDL_Window* Window::handle()
{
     return window;
}

void Window::show()
{
     SDL_ShowWindow(window);
}

Window::~Window()
{
     SDL_DestroyWindow(window);
}
