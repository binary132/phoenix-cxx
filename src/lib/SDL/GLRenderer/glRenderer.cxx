#include <sstream>

#include <glad/glad.h>

#include "SDL.h"

#include "initError.hpp"
#include "glRenderer.hpp"

using namespace sdl;

GLRenderer::GLRenderer(SDL_Window* win, int w, int h) noexcept(false)
{
     context = SDL_GL_CreateContext(win);
     if (context == NULL) {
	     std::stringstream ss;
	     ss << "SDL_GL_CreateContext failed: " << SDL_GetError();
	     throw error::InitError(ss);
     }

     int gladInitOk = gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress);
     if (gladInitOk) {
	   std::stringstream ss;
	   ss << "gladLoadGLLoader failed: " << gladInitOk;
	   throw error::InitError(ss);
     }
}

void GLRenderer::update() { }
void GLRenderer::draw() { }
void GLRenderer::clear() { }

void GLRenderer::drawPoint(int x, int y, int color) { }

GLRenderer::~GLRenderer()
{
     SDL_GL_DeleteContext(context);
}
