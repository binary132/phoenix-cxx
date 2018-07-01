#include <cmath>

#include "initError.hpp"
#include "window.hpp"
#include "renderer.hpp"

#include "graphics.hpp"

using namespace gfx;

Graphics::Graphics(sdl::Window& winIn,
                   int wIn, int hIn,
                   Uint32 flags) noexcept(false) :
     w(wIn), h(hIn),
     renderer(winIn.handle(), flags),
     texture(renderer.handle(),
             w, h)
{
     pixels = new Uint32[w * h];
     memset(pixels, 0, w * h * sizeof(Uint32));
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
     memset(pixels, 0, w * h * sizeof(Uint32));
}

void Graphics::drawLine(int x1, int y1,
                        int x2, int y2)
{
     int dx = x2 - x1, dy = y2 - y1;
     int d2 = dx * dx + dy * dy;
     float d = sqrt(d2);
     float stepX = dx / d, stepY = dy / d;

     for( int i = 0; i * i < d2; i++ ) {
          drawPoint(x1 + (int)((i * stepX)), y1 + (int)(i * stepY), 255);
     }
}

void Graphics::drawBlob(int&& x, int&& y, int&& r, int&& color)
{
     int dx = 0, dy = 0, d2 = (r * r);

     for( int i = x - r; i < x + r; i++ ) {
          for( int j = y - r; j < y + r; j++ ) {
               dx = x - i;
               dy = y - j;
               if( dx*dx + dy*dy < d2 ) {
                    drawPoint(i, j, color);
               }
          }
     }
}

Graphics::~Graphics()
{
     delete[] pixels;
}
