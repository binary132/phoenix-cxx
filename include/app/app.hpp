#ifndef APP_H
#define APP_H

#include <cmath>

#include "initError.hpp"
#include "world.hpp"
#include "graphics.hpp"
#include "sdlUtil.hpp"
#include "glRenderer.hpp"
#include "renderer.hpp"

#define DV 1000.0
#define FRIC 0.15

namespace app {

     template<class T>
     class App {
     public:
          App(const std::string& title = "Phoenix") noexcept(false);

          void run();

     private:
          int w() { return sdlUtil.w(); }
          int h() { return sdlUtil.h(); }

          const std::string title;

          sdl::SDLUtil sdlUtil;

          world::World world;
          gfx::Graphics<T> graphics;

          class Part {
          public:
               Part(int xi, int yi) :
                    x(xi), y(yi),
                    color(0), r(0),
                    vx(0.0), vy(0.0) { }

               void grav(int mX, int mY)
               {
                    int dx = mX - x;
                    int dy = mY - y;
                    float dst = sqrt(dx*dx + dy*dy);
                    float a = DV / (dst*dst) + 1.0/200000.0 * dst;
                    vx += a*dx - FRIC * vx;
                    vy += a*dy - FRIC * vy;
               }

               void update()
               {
                    x = x + vx, y = y + vy;
                    color = -255 + (int)(10*sqrt((vx*vx) + (vy*vy)));
                    r = 1 + 3.0*(1.0/20.0*sqrt((vx*vx) + (vy*vy)));

                    // (int)(1.0/100.0*sqrt((vx*vx) + (vy*vy)));
                    // r = 10.0/color;
               }

               int x, y;
               int color;
               int r;
               float vx, vy;
          };
     };
}

#include "app.hxx"
#include "appMain.hxx"

#endif
