#include <iostream>
#include <string>

#include <glad/glad.h>

#include "SDL.h"

#include "initError.hpp"
#include "app.hpp"
#include "sdlUtil.hpp"
#include "graphics.hpp"

using namespace app;

App::App(const std::string& titleIn) noexcept(false) :
     title(titleIn),
     sdlUtil(title,
             SDL_WINDOW_FULLSCREEN | SDL_WINDOW_ALLOW_HIGHDPI |
             SDL_WINDOW_OPENGL     | SDL_WINDOW_INPUT_GRABBED),
     graphics(sdlUtil.windowHandle(),
              sdlUtil.w(), sdlUtil.h(),
	      SDL_RENDERER_ACCELERATED) { }
