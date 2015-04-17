#include <cmath>

#include "initError.hpp"
#include "window.hpp"
#include "renderer.hpp"

#include "graphics.hpp"

using namespace gfx;

Graphics::Graphics(sdl::Window& winIn,
                   int wIn, int hIn,
                   Uint32 flags) throw (error::InitError) :
     w(wIn), h(hIn),
     renderer(winIn.handle(), flags),
     texture(renderer.handle(),
             w, h)
{
     pixels = new Uint32[w * h];
     memset(pixels, 255, w * h * sizeof(Uint32));
}

void Graphics::update()
{
     texture.update(NULL, pixels, w * sizeof(Uint32));
}

void Graphics::draw()
{
     SDL_RenderClear(renderer.handle());
     SDL_RenderCopy(renderer.handle(), texture.handle(), NULL, NULL);
     SDL_RenderPresent(renderer.handle());
}

void Graphics::clear()
{
     memset(pixels, 255, w * h * sizeof(Uint32));
}

void Graphics::drawLine(int x1, int y1,
                        int x2, int y2)
{
     int dx = x2 - x1, dy = y2 - y1;
     int d2 = dx * dx + dy * dy;
     float d = sqrt(d2);
     float stepX = dx / d, stepY = dy / d;

     for( int i = 0; i * i < d2; i++ ) {
          drawPoint(x1 + (int)((i * stepX)), y1 + (int)(i * stepY));
     }
}

Graphics::~Graphics()
{
     delete[] pixels;
}
