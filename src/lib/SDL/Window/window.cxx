#include <sstream>
#include <string_view>

#include "SDL.h"

#include "initError.hpp"
#include "window.hpp"

using namespace sdl;

Window::Window(const char* title,
               int x, int y,
               int w, int h,
               Uint32 flags) noexcept(false):
     window(SDL_CreateWindow(title,
                               x, y,
                               w, h,
			     flags))
{
     if (window == NULL) {
          std::stringstream ss;
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
