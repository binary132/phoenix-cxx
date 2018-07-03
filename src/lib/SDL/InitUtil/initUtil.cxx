#include <iostream>
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

     if (int glOk = SDL_GL_LoadLibrary(NULL) != 0) {
	   std::stringstream ss;
	   ss << "SDL_GL_LoadLibrary failed with code " << glOk
		   << ": " << SDL_GetError();
	   throw error::InitError(ss);
     }

     // Request an OpenGL 4.1 context (should be core)
     SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
     SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
     SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
     // // Also request a depth buffer
     // SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
     // SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

InitUtil::~InitUtil()
{
     SDL_Quit();
}
