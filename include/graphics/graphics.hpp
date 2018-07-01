#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "initError.hpp"
#include "window.hpp"
#include "renderer.hpp"
#include "texture.hpp"

namespace gfx
{
     class Graphics
     {
     public:
          Graphics(sdl::Window&,
                   int w, int h,
                   Uint32 flags =
                     SDL_RENDERER_ACCELERATED |
		   SDL_RENDERER_PRESENTVSYNC) noexcept(false);

          void update();
          void draw();
          void clear();

          inline void drawPoint(int x, int y, int color)
          {
               if(x > 0 && x < w-1 &&
                  y > 0 && y < h-1) {
                    pixels[y * w + x] = color;
               }
          }

          void drawBlob(int&& x, int&& y, int&& r, int&& color);

          void drawLine(int x1, int y1,
                        int x2, int y2);

          ~Graphics();

     private:
          int w;
          int h;

          Uint32* pixels;

          sdl::Renderer renderer;
          sdl::Texture texture;
     };
}

#endif
