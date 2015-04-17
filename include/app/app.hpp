#ifndef APP_H
#define APP_H

#include "initError.hpp"
#include "world.hpp"
#include "graphics.hpp"
#include "sdlUtil.hpp"

#define DV 0.01
#define FRIC 0.005

namespace app {
     class App {
     public:
          App(const std::string& title = "Phoenix") throw (error::InitError);

          void run();

     private:
          int w() { return sdlUtil.w(); }
          int h() { return sdlUtil.h(); }

          const std::string title;

          sdl::SDLUtil sdlUtil;

          world::World world;
          gfx::Graphics graphics;

          class Part {
          public:
               Part(int xi, int yi,
                    int xM, int yM) : 
                    x(xi), y(yi),
                    dx(0.0), dy(0.0),
                    xMax(xM), yMax(yM) { }

               void grav(int mX, int mY)
               {
                    dx = dx + (DV * (mX - x)) - FRIC * (dx);
                    dy = dy + (DV * (mY - y)) - FRIC * (dy);
               }

               void update()
               {
                    x = x + dx, y = y + dy;
                    if( x > xMax - 1 ) { x = xMax - 1; }
                    if( x < 0 ) { x = 0; }
                    if( y > yMax - 1 ) { y = yMax - 1; }
                    if( y < 0 ) { y = 0; }
               }

               int x, y;
               int xMax, yMax;
               float dx, dy;
          };
     };
}

#endif
